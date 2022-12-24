#pragma once
#include <array>
#include <tuple>

enum class Player
{
    NO_SET,
    PLAYER_1,
    PLAYER_2,
    NO_ONE,
};

enum class Result
{
    NO_SET,
    PLAYER1_WIN,
    PLAYER2_WIN,
    DRAW,
    ERROR,
};

class LocalBoard
{
private:
    static const std::array<std::tuple<char, char, char>, 8> bingo;
    std::array<Player, 9> local_board = {};
    Result result = Result::NO_SET;

public:
    std::array<Player, 9> Flatten();
    std::array<bool, 9> MakeLegalMoveMap();
    bool IsFull();
    void Mark(int pos, Player player);
    Result CheckState();
    LocalBoard();
    LocalBoard(std::array<Player, 9> flat_board);
};

class Board
{
private:
    std::array<LocalBoard, 9> local_boards;
    LocalBoard grobal_board;

public:
    std::array<Player, 81> Flatten();
    std::array<Player, 9> FlattenGrobalBoard();
    std::array<bool, 81> MakeLegalMoveMap(int last_move);
    std::tuple<int, int> PosToLocalPos(int pos);
    int LocalPosToPos(int local_num, int local_pos);
    void Mark(int pos, Player player);
    Result CheckState();
    Board();
    Board(std::array<Player, 81> flat_board);
};