#pragma once
#include <array>
#include <vector>
#include <any>
#include "agent.hpp"
#include "board.hpp"
#include "record.hpp"

template <class Agent1, class Agent2>
class Game
{
private:
    Agent1& player_1;
    Agent2& player_2;
    Board board;
    Record record;
    Player now_player;
    Player first_player;
    Result result;

public:
    Result ProcessGame();
    Record Play();
    Game(Agent1& agent_1, Agent2& agent_2, Player first_player);
};