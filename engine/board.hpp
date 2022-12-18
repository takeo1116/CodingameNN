#pragma once
#include <array>
#include <tuple>

enum class Player
{
    NO_SET,
    PLAYER_1,
    PLAYER_2,
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
    std::array<Player, 9> localBoard;
    Result result;

public:
    std::array<Player, 9> Flatten();
    std::array<bool, 9> MakeLegalMoveMap();
    bool IsFull();
    void Mark(int pos, Player player);
    Result CheckState();
    LocalBoard();
};

class Board
{
private:
    std::array<LocalBoard, 9> localBoards;
    LocalBoard grobalBoard;

public:
    std::array<Player, 81> Flatten();
    std::array<bool, 81> MakeLegalMoveMap(int lastMove);
    std::tuple<int, int> PosToLocalPos(int pos);
    void Mark(int pos, Player player);
    Board();
};