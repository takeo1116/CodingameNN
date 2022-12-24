#pragma once
#include <random>
#include <map>
#include <memory>
#include <cmath>
#include <cfloat>
#include "../engine/agent.hpp"

class StateData
{
private:
    int visited_num = 0;                 // シミュレーションでこの状態を訪れた回数
    bool expanded = false;               // next_statedataが展開されているかどうか
    float win_num = 0.0f;                // この状態に遷移させる手を打ったプレイヤーが勝った回数（この状態で手番が回ってきたプレイヤーではない）
    StateData *prev_statedata = nullptr; // 親のstatedata
    Cell now_player = Cell::NO_SET;      // 手番プレイヤー（自分か相手か）

public:
    std::map<int, std::unique_ptr<StateData>> next_statedata; // next_statedata[pos]=posに打ったときに遷移するstateのポインタ
    float GetWinRate()
    {
        if (visited_num == 0)
            return 0.0f;
        return win_num / visited_num;
    }
    float CalcUcbValue(int total_visited_num)
    {
        float value = GetWinRate();
        value += std::sqrt(2 * logf(total_visited_num + 1.0) / (visited_num + 1.0));
        return value;
    }
    void Win()
    {
        /*この状態に遷移させた人は負け*/
        visited_num++;
        win_num += 0.0;
    }
    void DRAW()
    {
        visited_num++;
        win_num += 0.5;
    }
    void Lose()
    {
        /*この状態に遷移させた人は勝ち*/
        visited_num++;
        win_num += 1.0;
    }
    bool IsExpanded()
    {
        return expanded;
    }
    void Expand(State *state)
    {
        auto next_positions = state->GetLegalPositions();
        Cell next_player = ToOpponentCell(now_player);

        for (int next : next_positions)
            next_statedata[next] = std::unique_ptr<StateData>(new StateData(next_player, this));
        expanded = true;
    }
    int GetVisitedNum()
    {
        return visited_num;
    }
    void BackPropagation(Cell winner)
    {
        if (winner == now_player)
            Win();
        else if (winner == Cell::NO_ONE)
            DRAW();
        else
            Lose();
        if (prev_statedata != nullptr)
            prev_statedata->BackPropagation(winner);
        return;
    }
    StateData(Cell now_player, StateData *prev_statedata = nullptr)
    {
        this->now_player = now_player;
        this->prev_statedata = prev_statedata;
    }
};

class MctsAgent : public AgentBase
{
private:
    std::random_device random;
    const int THRESHOLD = 10;
    int playout = 1;

    int SimulateAction(State state, StateData *statedata)
    {
        /*プレイアウト内でのActionを決める*/
        auto legal_positions = state.GetLegalPositions();

        if (statedata == nullptr || (!statedata->IsExpanded() && statedata->GetVisitedNum() < THRESHOLD))
        {
            /*ランダム*/
            int index = random() % legal_positions.size();
            return legal_positions[index];
        }

        if (!statedata->IsExpanded() && statedata->GetVisitedNum() == THRESHOLD)
            statedata->Expand(&state);

        /*UCBで手を判断する*/
        int move = -1;
        float max_value = -FLT_MAX;
        int total = statedata->GetVisitedNum();

        for (auto &[pos, next_statedata] : statedata->next_statedata)
        {
            float value = next_statedata->CalcUcbValue(total);
            if (max_value < value)
            {
                move = pos;
                max_value = value;
            }
        }
        return move;
    }

public:
    Action RequestAction(State root_state) override
    {
        Player root_player = root_state.GetPlayer();
        std::unique_ptr<StateData> root_statedata(new StateData(Cell::ME));
        root_statedata->Expand(&root_state);

        for (int play = 0; play < playout; play++)
        {
            Player now_player = root_player;
            Board board = Board(root_state.GetPlayerBoard());
            StateData *now_statedata = root_statedata.get();
            StateData *last_statedata = nullptr; // ゲーム木の葉（展開されていない最初のノード）
            Result result = board.CheckState();
            int last_action = -1;

            while (result == Result::NO_SET)
            {
                State now_state = State(board, now_player, root_state.GetFirstPlayer(), last_action);
                int move = SimulateAction(now_state, now_statedata);
                // std::cout << "move: " << move << std::endl;
                if (now_statedata != nullptr && now_statedata->IsExpanded())
                {
                    now_statedata = now_statedata->next_statedata[move].get();
                    last_statedata = now_statedata;
                }
                else
                    now_statedata = nullptr;
                board.Mark(move, now_player); // illegalな手は打たない前提
                result = board.CheckState();
                last_action = move;
                // 手番を移す
                if (now_player == Player::PLAYER_1)
                    now_player = Player::PLAYER_2;
                else if (now_player == Player::PLAYER_2)
                    now_player = Player::PLAYER_1;
            }

            /*逆伝搬*/
            if (result == Result::DRAW)
                last_statedata->BackPropagation(Cell::NO_ONE); // 引き分け
            else if ((result == Result::PLAYER1_WIN && root_player == Player::PLAYER_1) || (result == Result::PLAYER2_WIN && root_player == Player::PLAYER_2))
                last_statedata->BackPropagation(Cell::ME); // 勝ち
            else
                last_statedata->BackPropagation(Cell::OPPONENT); // 負け
        }

        int move = -1;
        float max_value = -FLT_MAX;
        for (auto &[pos, next_statedata] : root_statedata->next_statedata)
        {
            float value = next_statedata->GetWinRate();
            // float value = next_statedata->GetVisitedNum();
            std::cout << pos << ": " << next_statedata->GetVisitedNum() << ", " << value << std::endl;
            if (max_value < value)
            {
                move = pos;
                max_value = value;
            }
        }

        for (auto &[pos, next_statedata] : root_statedata->next_statedata[move]->next_statedata)
        {
            float value = next_statedata->GetWinRate();
            // float value = next_statedata->GetVisitedNum();
            std::cout << "-" << pos << ": " << next_statedata->GetVisitedNum() << ", " << value << std::endl;
        }

        // throw std::runtime_error("test");
        return Action(move);
    }
    std::string GetAgentName() override
    {
        return "MctsAgent_" + std::to_string(playout);
    }
    MctsAgent(int playout) : AgentBase()
    {
        this->playout = playout;
    }
};