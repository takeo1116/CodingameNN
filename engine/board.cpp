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
    return local_board;
}

std::array<bool, 9> LocalBoard::MakeLegalMoveMap()
{
    /*このlocalMap中で、合法手となりうる場所*/
    std::array<bool, 9> legal_move_map = {};
    if (CheckState() != Result::NO_SET)
        return legal_move_map;

    for (int pos = 0; pos < 9; pos++)
        legal_move_map[pos] = (local_board[pos] == Player::NO_SET);
    return legal_move_map;
}

bool LocalBoard::IsFull()
{
    /*local_boardがすべて埋まっているか？*/
    for (auto a : local_board)
        if (a == Player::NO_SET)
            return false;
    return true;
}

void LocalBoard::Mark(int pos, Player player)
{
    /*posにplayerの手をマークする*/
    local_board[pos] = player;
}

Result LocalBoard::CheckState()
{
    /*終了しているかをチェックする*/
    if (result != Result::NO_SET)
        return result;

    for (auto &[a, b, c] : bingo)
    {
        if (local_board[a] != Player::NO_SET && local_board[a] == local_board[b] && local_board[b] == local_board[c])
        {
            switch (local_board[a])
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
    std::array<Player, 81> flat_board = {};
    for (int local_num = 0; local_num < 9; local_num++)
    {
        std::array<Player, 9> flat_local_board = local_boards[local_num].Flatten();
        for (int local_pos = 0; local_pos < 9; local_pos++)
        {
            int pos = LocalPosToPos(local_num, local_pos);
            flat_board[pos] = flat_local_board[local_pos];
        }
    }
    return flat_board;
}

std::tuple<int, int> Board::PosToLocalPos(int pos)
{
    /*boardのindexを(localboard番号, localboardのindex)に変換する*/
    int local_num = pos / 9, local_pos = pos % 9;
    return std::make_tuple(local_num, local_pos);
}

int LocalPosToPos(int local_num, int local_pos)
{
    int pos = local_num * 9 + local_pos;
    return pos;
}

void Board::Mark(int pos, Player player)
{
    /*posにplayerの手をマークする*/
    auto [local_num, local_pos] = PosToLocalPos(pos);
    local_boards[local_num].Mark(local_pos, player);
    Result local_result = local_boards[local_num].CheckState();
    if (local_result == Result::PLAYER1_WIN)
        grobal_board.Mark(local_num, Player::PLAYER_1);
    else if (local_result == Result::PLAYER2_WIN)
        grobal_board.Mark(local_num, Player::PLAYER_2);
}

std::array<bool, 81> Board::MakeLegalMoveMap(int last_move)
{
    std::array<bool, 81> legal_board = {};
    if (last_move != -1) // 1ターン目
    {
        for (int pos = 0; pos < 81; pos++)
            legal_board[pos] = true;
        return legal_board;
    }
    auto [local_num, local_pos] = PosToLocalPos(last_move);
    if (local_boards[local_num].CheckState() == Result::NO_SET) // 指定されたlocalBoardに置けるとき
    {
        std::array<bool, 9> empty_cell_map = local_boards[local_num].MakeLegalMoveMap();
        for (int i = 0; i < 9; i++)
        {
            int pos = LocalPosToPos(local_num, i);
            legal_board[pos] = empty_cell_map[i];
        }
        return legal_board;
    }
    else // 指定されたlocalBoardに置けないとき
    {
        for (int local_num = 0; local_num < 9; local_num++)
        {
            std::array<bool, 9> empty_cell_map = local_boards[local_num].MakeLegalMoveMap();
            for (int i = 0; i < 9; i++)
            {
                int pos = LocalPosToPos(local_num, i);
                legal_board[pos] = empty_cell_map[i];
            }
        }
        return legal_board;
    }
}

Result Board::CheckState()
{
    return grobal_board.CheckState();
}

Board::Board()
{
}