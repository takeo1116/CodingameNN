#include <chrono>
#include "game.hpp"
#include "state.hpp"
#include "board.hpp"
#include "action.hpp"

Result Game::ProcessGame(){
    /*ゲームを1手進める*/
    State nowState = State(board, nowPlayer, firstPlayer);
    Action action;
    if (nowPlayer == Player::PLAYER_1)
        players[0].RequestAction(nowState);
    else if (nowPlayer == Player::PLAYER_2)
        players[1].RequestAction(nowState);
    else
        throw std::runtime_error("error in Game::ProcessGame");
    
}

Record Game::Play(){
    /*ゲーム終了までシミュレートする*/
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    while (result == Result::NO_SET){
        result = ProcessGame();
    }

    int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count();
}