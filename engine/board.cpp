#include "board.hpp"

/*
    LocalBoard
*/
const std::array<std::tuple<char, char, char>, 8> LocalBoard::bingo = {
    std::make_tuple(0, 1, 2),
    std::make_tuple(3, 4, 5),
    std::make_tuple(6, 7, 8),
    std::make_tuple(0, 3, 6),
    std::make_tuple(1, 4, 7),
    std::make_tuple(2, 5, 8),
    std::make_tuple(0, 4, 8),
    std::make_tuple(2, 4, 6),
};

void LocalBoard::Mark(int pos, Player player)
{
    /*posにplayerの手をマークする*/
    localBoard[pos] = player;
}

Player LocalBoard::CheckState()
{
    /*終了しているかをチェックする*/
    if (state != Player::NoSet)
        return state;

    for (auto &[a, b, c] : bingo)
    {
        if (localBoard[a] != Player::NoSet && localBoard[a] == localBoard[b] && localBoard[b] == localBoard[c])
        {
            state == localBoard[a];
            return state;
        }
    }

    for (auto a : localBoard)
        if (a == Player::NoSet)
            return Player::NoSet;

    return Player::Draw;
}

LocalBoard::LocalBoard()
{
}

/*
    Board
*/
std::tuple<int, int> Board::PosToLocalPos(int pos)
{
    /*boardのindexを(localboard番号, localboardのindex)に変換する*/
    int localNum = pos / 9, localPos = pos % 9;
    return std::make_tuple(localNum, localPos);
}

void Board::Mark(int pos, Player player)
{
    /*posにplayerの手をマークする*/
    auto [localNum, localPos] = PosToLocalPos(pos);
    localBoards[localNum].Mark(localPos, player);
    Player localResult = localBoards[localNum].CheckState();
    grobalBoard.Mark(localNum, localResult);
}

Board::Board()
{
}