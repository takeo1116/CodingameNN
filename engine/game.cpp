#include <chrono>
#include <iostream>
#include "game.hpp"
#include "state.hpp"
#include "board.hpp"
#include "action.hpp"

Result Game::ProcessGame()
{
    /*ゲームを1手進める*/
    State now_state = State(board, now_player, first_player);
    AgentBase &player = players[0];
    if (now_player == Player::PLAYER_2)
        player = players[1];
    else if (now_player != Player::PLAYER_1)
        throw std::runtime_error("error in Game::ProcessGame");
    Action action = player.RequestAction(now_state);

    // 手を記録する
    ActionData action_data = ActionData(now_player, first_player, player.GetAgentName(), now_state, action);
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

Record Game::Play()
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
}