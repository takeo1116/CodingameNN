#pragma once
#include <array>
#include <vector>
#include "board.hpp"

enum class Cell
{
    NO_SET,
    ME,
    OPPONENT,
};

class State
{
private:
    Board board;
    Player nowPlayer;
    Player firstPlayer;
    int lastAction;

public:
    std::array<Cell, 81> makeFlatBoard()
    {
        /*盤面を表すarrayを得る*/
        std::array<Cell, 81> flatCellBoard = {};
        std::array<Player, 81> flatPlayerBoard = board.Flatten();
        for (int pos = 0; pos < 81; pos++)
        {
            if (flatPlayerBoard[pos] == Player::NO_SET)
                flatCellBoard[pos] = Cell::NO_SET;
            else if (flatPlayerBoard[pos] == nowPlayer)
                flatCellBoard[pos] = Cell::ME;
            else
                flatCellBoard[pos] = Cell::OPPONENT;
        }
        return flatCellBoard;
    }
    std::vector<int> GetLegalPositions()
    {
        /*合法手のリストを得る*/
    }
    State(Board board, Player nowPlayer, Player firstPlayer)
    {
        this->board = board;
        this->nowPlayer = nowPlayer;
        this->firstPlayer = firstPlayer;
    }
};