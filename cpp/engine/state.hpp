#pragma once
#include <iostream>
#include <array>
#include <vector>
#include "board.hpp"
#include "cell.hpp"

class State
{
private:
    Board board;
    Player now_player;
    Player first_player;
    int last_action;
    int turn;

public:
    int GetTurn()
    {
        return turn;
    }
    Player GetPlayer()
    {
        return now_player;
    }
    Player GetFirstPlayer()
    {
        return first_player;
    }
    bool IsFirstPlayer()
    {
        return now_player == first_player;
    }
    std::array<Player, 81> GetPlayerBoard()
    {
        return board.Flatten();
    }
    std::array<Cell, 81> MakeFlatBoard()
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
    std::array<Cell, 9> MakeFlatGlobalBoard()
    {
        /*GlobalBoardを表すarrayを得る*/
        std::array<Cell, 9> flat_cell_board = {};
        std::array<Player, 9> flat_player_board = board.FlattenGlobalBoard();
        for (int pos = 0; pos < 9; pos++)
        {
            if (flat_player_board[pos] == Player::NO_SET)
                flat_cell_board[pos] = Cell::NO_SET;
            else if (flat_player_board[pos] == Player::NO_ONE)
                flat_cell_board[pos] = Cell::NO_ONE;
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

    std::string DumpLegalPositionMap()
    {
        auto legal_move_map = board.MakeLegalMoveMap(last_action);
        std::string str = "";
        for (int pos = 0; pos < 81; pos++)
        {
            str += legal_move_map[pos] ? '|' : '-';
            if (pos % 9 == 8)
                str += " ";
        }
        std::cout << str << std::endl;
        return str;
    }

    std::string DumpFlatBoard()
    {
        auto flat_board = board.Flatten();
        std::string str = "";
        for (int i = 0; i < 81; i++)
        {
            str += (int)flat_board[i] + '0';
            if (i % 9 == 8)
                str += " ";
        }
        str += "| ";
        auto global_flat_board = board.FlattenGlobalBoard();
        for (int i = 0; i < 9; i++)
            str += (int)global_flat_board[i] + '0';
        std::cout << str << std::endl;
        return str;
    }

    State(Board board, Player now_player, Player first_player, int last_action, int turn)
    {
        this->board = board;
        this->now_player = now_player;
        this->first_player = first_player;
        this->last_action = last_action;
        this->turn = turn;
    }
    State() {}
};