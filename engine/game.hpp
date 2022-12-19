#pragma once
#include <array>
#include <vector>
#include "agent.hpp"
#include "board.hpp"
#include "record.hpp"

class Game
{
private:
    std::array<AgentBase, 2> players;
    Board board;
    Record record;
    Player now_player;
    Player first_player;
    Result result;

public:
    Result ProcessGame();
    Record Play();
};