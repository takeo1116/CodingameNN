#pragma once
#include <array>
#include <tuple>

enum class Player
{
    NoSet,
    Player1,
    Player2,
    Draw,
};

class LocalBoard
{
private:
    static const std::array<std::tuple<char, char, char>, 8> bingo;
    std::array<Player, 9> localBoard;
    Player state;

public:
    void Mark(int pos, Player player);
    Player CheckState();
    LocalBoard();
};

class Board
{
private:
    std::array<LocalBoard, 9> localBoards;
    LocalBoard grobalBoard;

public:
    std::tuple<int, int> PosToLocalPos(int pos);
    void Mark(int pos, Player player);
    Board();
};