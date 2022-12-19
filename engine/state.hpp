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
    Player now_player;
    Player first_player;
    int last_action;

public:
    std::array<Cell, 81> makeFlatBoard()
    {
        /*盤面を表すarrayを得る*/
        std::array<Cell, 81> flat_cell_board = {};
        std::array<Player, 81> flat_player_board = board.Flatten();
        for (int pos = 0; pos < 81; pos++)
        {
            if (flat_player_board[pos] == Player::NO_SET)
                flat_cell_board[pos] = Cell::NO_SET;
            else if (flat_player_board[pos] == now_player)
                flat_cell_board[pos] = Cell::ME;
            else
                flat_cell_board[pos] = Cell::OPPONENT;
        }
        return flat_cell_board;
    }
    bool IsLegal(int move)
    {
        if (move < 0 || 81 <= move)
            return false;
        auto legal_move_map = board.MakeLegalMoveMap(last_action);
        return legal_move_map[move];
    }
    std::vector<int> GetLegalPositions()
    {
        /*合法手のリストを得る*/
        std::vector<int> legal_positions;
        auto legal_move_map = board.MakeLegalMoveMap(last_action);
        for (int pos = 0; pos < 81; pos++)
            if (legal_move_map[pos])
                legal_positions.push_back(pos);
        return legal_positions;
    }
    State(Board board, Player now_player, Player first_player)
    {
        this->board = board;
        this->now_player = now_player;
        this->first_player = first_player;
    }
};