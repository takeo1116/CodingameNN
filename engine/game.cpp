#include <chrono>
#include <iostream>
#include <string>
#include "game.hpp"
#include "state.hpp"
#include "board.hpp"
#include "action.hpp"

template <class Agent1, class Agent2>
Result Game<Agent1, Agent2>::ProcessGame()
{
    /*ゲームを1手進める*/
    State now_state = State(board, now_player, first_player);
    Action action;
    std::string agent_name;
    if (now_player == Player::PLAYER_1)
    {
        action = player_1.RequestAction(now_state);
        agent_name = player_1.GetAgentName();
    }
    else if (now_player == Player::PLAYER_2)
    {
        action = player_2.RequestAction(now_state);
        agent_name = player_2.GetAgentName();
    }
    else
        throw std::runtime_error("error in Game::ProcessGame");

    // 手を記録する
    ActionData action_data = ActionData(now_player, first_player, agent_name, now_state, action);
    record.Add(action_data);

    // 返ってきた手が有効かどうか調べる（有効じゃない手を打とうとしたら負け）
    if (!now_state.IsLegal(action.GetMove()))
    {
        if (now_player == Player::PLAYER_1)
            result = Result::PLAYER2_WIN;
        else if (now_player == Player::PLAYER_2)
            result = Result::PLAYER1_WIN;
        else
            result = Result::ERROR;
        return result;
    }

    // 手を反映させる
    board.Mark(action.GetMove(), now_player);

    return board.CheckState();
}

template <class Agent1, class Agent2>
Record Game<Agent1, Agent2>::Play()
{
    /*ゲーム終了までシミュレートする*/
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    while (result == Result::NO_SET)
    {
        result = ProcessGame();
    }
    record.SetResult(result);

    int elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count();

    std::cout << "result: " << (int)result << ", time: " << elapsed_time << " ms" << std::endl;
    return record;
}

template <class Agent1, class Agent2>
Game<Agent1, Agent2>::Game(Agent1 &agent_1, Agent2 &agent_2, Player first_player)
{
    player_1 = agent_1;
    player_2 = agent_2;
    board = Board();
    record = Record();
    first_player = first_player;
    now_player = first_player;
    result = Result::NO_SET;
}