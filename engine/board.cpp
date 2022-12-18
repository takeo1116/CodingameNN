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

std::array<Player, 9> LocalBoard::Flatten()
{
    return localBoard;
}

std::array<bool, 9> LocalBoard::MakeLegalMoveMap()
{
    /*このlocalMap中で、合法手となりうる場所*/
    std::array<bool, 9> legalMoveMap = {};
    if (CheckState() != Result::NO_SET)
        return legalMoveMap;

    for (int pos = 0; pos < 9; pos++)
        legalMoveMap[pos] = (localBoard[pos] == Player::NO_SET);
    return legalMoveMap;
}

bool LocalBoard::IsFull()
{
    /*LocalBoardがすべて埋まっているか？*/
    for (auto a : localBoard)
        if (a == Player::NO_SET)
            return false;
    return true;
}

void LocalBoard::Mark(int pos, Player player)
{
    /*posにplayerの手をマークする*/
    localBoard[pos] = player;
}

Result LocalBoard::CheckState()
{
    /*終了しているかをチェックする*/
    if (result != Result::NO_SET)
        return result;

    for (auto &[a, b, c] : bingo)
    {
        if (localBoard[a] != Player::NO_SET && localBoard[a] == localBoard[b] && localBoard[b] == localBoard[c])
        {
            switch (localBoard[a])
            {
            case Player::PLAYER_1:
                result = Result::PLAYER1_WIN;
                break;
            case Player::PLAYER_2:
                result = Result::PLAYER2_WIN;
                break;
            default:
                result = Result::ERROR;
                break;
            }
            return result;
        }
    }

    if (!IsFull())
        return Result::NO_SET;

    result = Result::DRAW;
    return result;
}

LocalBoard::LocalBoard()
{
}

/*
    Board
*/
std::array<Player, 81> Board::Flatten()
{
    std::array<Player, 81> flatBoard = {};
    for (int localNum = 0; localNum < 9; localNum++)
    {
        std::array<Player, 9> flatLocalBoard = localBoards[localNum].Flatten();
        for (int localPos = 0; localPos < 9; localPos++)
        {
            int pos = LocalPosToPos(localNum, localPos);
            flatBoard[pos] = flatLocalBoard[localPos];
        }
    }
    return flatBoard;
}

std::tuple<int, int> Board::PosToLocalPos(int pos)
{
    /*boardのindexを(localboard番号, localboardのindex)に変換する*/
    int localNum = pos / 9, localPos = pos % 9;
    return std::make_tuple(localNum, localPos);
}

int LocalPosToPos(int localNum, int localPos)
{
    int pos = localNum * 9 + localPos;
    return pos;
}

void Board::Mark(int pos, Player player)
{
    /*posにplayerの手をマークする*/
    auto [localNum, localPos] = PosToLocalPos(pos);
    localBoards[localNum].Mark(localPos, player);
    Result localResult = localBoards[localNum].CheckState();
    if (localResult == Result::PLAYER1_WIN)
        grobalBoard.Mark(localNum, Player::PLAYER_1);
    else if (localResult == Result::PLAYER2_WIN)
        grobalBoard.Mark(localNum, Player::PLAYER_2);
}

std::array<bool, 81> Board::MakeLegalMoveMap(int lastMove)
{
    std::array<bool, 81> legalBoard = {};
    if (lastMove != -1) // 1ターン目
    {
        for (int pos = 0; pos < 81; pos++)
            legalBoard[pos] = true;
        return legalBoard;
    }
    auto [localNum, localPos] = PosToLocalPos(lastMove);
    if (localBoards[localNum].CheckState() == Result::NO_SET) // 指定されたlocalBoardに置けるとき
    {
        std::array<bool, 9> emptyCellMap = localBoards[localNum].MakeLegalMoveMap();
        for (int i = 0; i < 9; i++)
        {
            int pos = LocalPosToPos(localNum, i);
            legalBoard[pos] = emptyCellMap[i];
        }
        return legalBoard;
    }
    else // 指定されたlocalBoardに置けないとき
    {
        for (int localNum = 0; localNum < 9; localNum++)
        {
            std::array<bool, 9> emptyCellMap = localBoards[localNum].MakeLegalMoveMap();
            for (int i = 0; i < 9; i++)
            {
                int pos = LocalPosToPos(localNum, i);
                legalBoard[pos] = emptyCellMap[i];
            }
        }
        return legalBoard;
    }
}

Board::Board()
{
}