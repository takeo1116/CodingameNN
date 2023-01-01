#pragma once
#include <array>
#include <tuple>
#include <bitset>
#include <string>
#include <vector>
#include "../engine/board.hpp"
#include "learndata.hpp"

class Features
{
public:
    static const std::array<std::tuple<short, short, short, short, short, short, short, short>, 192> idxes;

    static std::array<std::bitset<16>, 192> MakeFeatures(LearnData learndata);
    static std::string GetPythonInverseIdxes();
    static std::string GetPythonIdxes();
    static std::string Dump(LearnData learndata);
};

const std::array<std::tuple<short, short, short, short, short, short, short, short>, 192> Features::idxes = {
    /*モデル0*/
    // 012_0_012型
    std::make_tuple(0, 1, 2, 0, 0, 1, 2, 0),
    std::make_tuple(2, 5, 8, 2, 2, 5, 8, 0),
    std::make_tuple(8, 7, 6, 8, 8, 7, 6, 0),
    std::make_tuple(6, 3, 0, 6, 6, 3, 0, 0),
    std::make_tuple(2, 1, 0, 2, 2, 1, 0, 0),
    std::make_tuple(8, 5, 2, 8, 8, 5, 2, 0),
    std::make_tuple(6, 7, 8, 6, 6, 7, 8, 0),
    std::make_tuple(0, 3, 6, 0, 0, 3, 6, 0),
    // 012_0_258型
    std::make_tuple(0, 1, 2, 0, 2, 5, 8, 0),
    std::make_tuple(2, 5, 8, 2, 8, 7, 6, 0),
    std::make_tuple(8, 7, 6, 8, 6, 3, 0, 0),
    std::make_tuple(6, 3, 0, 6, 0, 1, 2, 0),
    std::make_tuple(2, 1, 0, 2, 0, 3, 6, 0),
    std::make_tuple(8, 5, 2, 8, 2, 1, 0, 0),
    std::make_tuple(6, 7, 8, 6, 8, 5, 2, 0),
    std::make_tuple(0, 3, 6, 0, 6, 7, 8, 0),
    // 012_0_876型
    std::make_tuple(0, 1, 2, 0, 8, 7, 6, 0),
    std::make_tuple(2, 5, 8, 2, 6, 3, 0, 0),
    std::make_tuple(8, 7, 6, 8, 0, 1, 2, 0),
    std::make_tuple(6, 3, 0, 6, 2, 5, 8, 0),
    std::make_tuple(2, 1, 0, 2, 6, 7, 8, 0),
    std::make_tuple(8, 5, 2, 8, 0, 3, 6, 0),
    std::make_tuple(6, 7, 8, 6, 2, 1, 0, 0),
    std::make_tuple(0, 3, 6, 0, 8, 5, 2, 0),
    // 012_0_630型
    std::make_tuple(0, 1, 2, 0, 6, 3, 0, 0),
    std::make_tuple(2, 5, 8, 2, 0, 1, 2, 0),
    std::make_tuple(8, 7, 6, 8, 2, 5, 8, 0),
    std::make_tuple(6, 3, 0, 6, 8, 7, 6, 0),
    std::make_tuple(2, 1, 0, 2, 8, 5, 2, 0),
    std::make_tuple(8, 5, 2, 8, 6, 7, 8, 0),
    std::make_tuple(6, 7, 8, 6, 0, 3, 6, 0),
    std::make_tuple(0, 3, 6, 0, 2, 1, 0, 0),
    // 012_0_345型
    std::make_tuple(0, 1, 2, 0, 3, 4, 5, 0),
    std::make_tuple(2, 5, 8, 2, 1, 4, 7, 0),
    std::make_tuple(8, 7, 6, 8, 5, 4, 3, 0),
    std::make_tuple(6, 3, 0, 6, 7, 4, 1, 0),
    std::make_tuple(2, 1, 0, 2, 5, 4, 3, 0),
    std::make_tuple(8, 5, 2, 8, 7, 4, 1, 0),
    std::make_tuple(6, 7, 8, 6, 3, 4, 5, 0),
    std::make_tuple(0, 3, 6, 0, 1, 4, 7, 0),
    // 012_0_147型
    std::make_tuple(0, 1, 2, 0, 1, 4, 7, 0),
    std::make_tuple(2, 5, 8, 2, 5, 4, 3, 0),
    std::make_tuple(8, 7, 6, 8, 7, 4, 1, 0),
    std::make_tuple(6, 3, 0, 6, 3, 4, 5, 0),
    std::make_tuple(2, 1, 0, 2, 1, 4, 7, 0),
    std::make_tuple(8, 5, 2, 8, 5, 4, 3, 0),
    std::make_tuple(6, 7, 8, 6, 7, 4, 1, 0),
    std::make_tuple(0, 3, 6, 0, 3, 4, 5, 0),
    // 012_0_048型
    std::make_tuple(0, 1, 2, 0, 0, 4, 8, 0),
    std::make_tuple(2, 5, 8, 2, 2, 4, 6, 0),
    std::make_tuple(8, 7, 6, 8, 8, 4, 0, 0),
    std::make_tuple(6, 3, 0, 6, 6, 4, 2, 0),
    std::make_tuple(2, 1, 0, 2, 2, 4, 6, 0),
    std::make_tuple(8, 5, 2, 8, 8, 4, 0, 0),
    std::make_tuple(6, 7, 8, 6, 6, 4, 2, 0),
    std::make_tuple(0, 3, 6, 0, 0, 4, 8, 0),
    // 012_0_246型
    std::make_tuple(0, 1, 2, 0, 2, 4, 6, 0),
    std::make_tuple(2, 5, 8, 2, 8, 4, 0, 0),
    std::make_tuple(8, 7, 6, 8, 6, 4, 2, 0),
    std::make_tuple(6, 3, 0, 6, 0, 4, 8, 0),
    std::make_tuple(2, 1, 0, 2, 0, 4, 8, 0),
    std::make_tuple(8, 5, 2, 8, 2, 4, 6, 0),
    std::make_tuple(6, 7, 8, 6, 8, 4, 0, 0),
    std::make_tuple(0, 3, 6, 0, 6, 4, 2, 0),

    /*モデル1*/
    // 012_1_012型
    std::make_tuple(0, 1, 2, 1, 0, 1, 2, 1),
    std::make_tuple(2, 5, 8, 5, 2, 5, 8, 1),
    std::make_tuple(8, 7, 6, 7, 8, 7, 6, 1),
    std::make_tuple(6, 3, 0, 3, 6, 3, 0, 1),
    // 012_1_258型
    std::make_tuple(0, 1, 2, 1, 2, 5, 8, 1),
    std::make_tuple(2, 5, 8, 5, 8, 7, 6, 1),
    std::make_tuple(8, 7, 6, 7, 6, 3, 0, 1),
    std::make_tuple(6, 3, 0, 3, 0, 1, 2, 1),
    // 012_1_876型
    std::make_tuple(0, 1, 2, 1, 8, 7, 6, 1),
    std::make_tuple(2, 5, 8, 5, 6, 3, 0, 1),
    std::make_tuple(8, 7, 6, 7, 0, 1, 2, 1),
    std::make_tuple(6, 3, 0, 3, 2, 5, 8, 1),
    // 012_1_630型
    std::make_tuple(0, 1, 2, 1, 6, 3, 0, 1),
    std::make_tuple(2, 5, 8, 5, 0, 1, 2, 1),
    std::make_tuple(8, 7, 6, 7, 2, 5, 8, 1),
    std::make_tuple(6, 3, 0, 3, 8, 7, 6, 1),
    // 012_1_345型
    std::make_tuple(0, 1, 2, 1, 3, 4, 5, 1),
    std::make_tuple(2, 5, 8, 5, 1, 4, 7, 1),
    std::make_tuple(8, 7, 6, 7, 5, 4, 3, 1),
    std::make_tuple(6, 3, 0, 3, 7, 4, 1, 1),
    // 012_1_147型
    std::make_tuple(0, 1, 2, 1, 1, 4, 7, 1),
    std::make_tuple(2, 5, 8, 5, 5, 4, 3, 1),
    std::make_tuple(8, 7, 6, 7, 7, 4, 1, 1),
    std::make_tuple(6, 3, 0, 3, 3, 4, 5, 1),
    // 012_1_048型
    std::make_tuple(0, 1, 2, 1, 0, 4, 8, 1),
    std::make_tuple(2, 5, 8, 5, 2, 4, 6, 1),
    std::make_tuple(8, 7, 6, 7, 8, 4, 0, 1),
    std::make_tuple(6, 3, 0, 3, 6, 4, 2, 1),
    // 012_1_246型
    std::make_tuple(0, 1, 2, 1, 2, 4, 6, 1),
    std::make_tuple(2, 5, 8, 5, 8, 4, 0, 1),
    std::make_tuple(8, 7, 6, 7, 6, 4, 2, 1),
    std::make_tuple(6, 3, 0, 3, 0, 4, 8, 1),

    /*モデル2*/
    // 345_3_012型
    std::make_tuple(3, 4, 5, 3, 0, 1, 2, 2),
    std::make_tuple(1, 4, 7, 1, 2, 5, 8, 2),
    std::make_tuple(5, 4, 3, 5, 8, 7, 6, 2),
    std::make_tuple(7, 4, 1, 7, 6, 3, 0, 2),
    std::make_tuple(5, 4, 3, 5, 2, 1, 0, 2),
    std::make_tuple(7, 4, 1, 7, 8, 5, 2, 2),
    std::make_tuple(3, 4, 5, 3, 6, 7, 8, 2),
    std::make_tuple(1, 4, 7, 1, 0, 3, 6, 2),
    // 345_3_258型
    std::make_tuple(3, 4, 5, 3, 2, 5, 8, 2),
    std::make_tuple(1, 4, 7, 1, 8, 7, 6, 2),
    std::make_tuple(5, 4, 3, 5, 6, 3, 0, 2),
    std::make_tuple(7, 4, 1, 7, 0, 1, 2, 2),
    std::make_tuple(5, 4, 3, 5, 0, 3, 6, 2),
    std::make_tuple(7, 4, 1, 7, 2, 1, 0, 2),
    std::make_tuple(3, 4, 5, 3, 8, 5, 2, 2),
    std::make_tuple(1, 4, 7, 1, 6, 7, 8, 2),
    // 345_3_345型
    std::make_tuple(3, 4, 5, 3, 3, 4, 5, 2),
    std::make_tuple(1, 4, 7, 1, 1, 4, 7, 2),
    std::make_tuple(5, 4, 3, 5, 5, 4, 3, 2),
    std::make_tuple(7, 4, 1, 7, 7, 4, 1, 2),
    // 345_3_147型
    std::make_tuple(3, 4, 5, 3, 1, 4, 7, 2),
    std::make_tuple(1, 4, 7, 1, 5, 4, 3, 2),
    std::make_tuple(5, 4, 3, 5, 7, 4, 1, 2),
    std::make_tuple(7, 4, 1, 7, 3, 4, 5, 2),
    // 345_3_048型
    std::make_tuple(3, 4, 5, 3, 0, 4, 8, 2),
    std::make_tuple(1, 4, 7, 1, 2, 4, 6, 2),
    std::make_tuple(5, 4, 3, 5, 8, 4, 0, 2),
    std::make_tuple(7, 4, 1, 7, 6, 4, 2, 2),
    std::make_tuple(5, 4, 3, 5, 2, 4, 6, 2),
    std::make_tuple(7, 4, 1, 7, 8, 4, 0, 2),
    std::make_tuple(3, 4, 5, 3, 6, 4, 2, 2),
    std::make_tuple(1, 4, 7, 1, 0, 4, 8, 2),

    /*モデル3*/
    // 345_4_012型
    std::make_tuple(3, 4, 5, 4, 0, 1, 2, 3),
    std::make_tuple(1, 4, 7, 4, 2, 5, 8, 3),
    std::make_tuple(5, 4, 3, 4, 8, 7, 6, 3),
    std::make_tuple(7, 4, 1, 4, 6, 3, 0, 3),
    // 345_4_258型
    std::make_tuple(3, 4, 5, 4, 2, 5, 8, 3),
    std::make_tuple(1, 4, 7, 4, 8, 7, 6, 3),
    std::make_tuple(5, 4, 3, 4, 6, 3, 0, 3),
    std::make_tuple(7, 4, 1, 4, 0, 1, 2, 3),
    // 345_4_345型
    std::make_tuple(3, 4, 5, 4, 3, 4, 5, 3),
    std::make_tuple(1, 4, 7, 4, 1, 4, 7, 3),
    // 345_4_147型
    std::make_tuple(3, 4, 5, 4, 1, 4, 7, 3),
    std::make_tuple(1, 4, 7, 4, 5, 4, 3, 3),
    // 345_4_048型
    std::make_tuple(3, 4, 5, 4, 0, 4, 8, 3),
    std::make_tuple(1, 4, 7, 4, 2, 4, 6, 3),
    std::make_tuple(5, 4, 3, 4, 2, 4, 6, 3),
    std::make_tuple(1, 4, 7, 4, 0, 4, 8, 3),

    /*モデル4*/
    // 048_0_012型
    std::make_tuple(0, 4, 8, 0, 0, 1, 2, 4),
    std::make_tuple(2, 4, 6, 2, 2, 5, 8, 4),
    std::make_tuple(8, 4, 0, 8, 8, 7, 6, 4),
    std::make_tuple(6, 4, 2, 6, 6, 3, 0, 4),
    std::make_tuple(2, 4, 6, 2, 2, 1, 0, 4),
    std::make_tuple(8, 4, 0, 8, 8, 5, 2, 4),
    std::make_tuple(6, 4, 2, 6, 6, 7, 8, 4),
    std::make_tuple(0, 4, 8, 0, 0, 3, 6, 4),
    // 048_0_258型
    std::make_tuple(0, 4, 8, 0, 2, 5, 8, 4),
    std::make_tuple(2, 4, 6, 2, 8, 7, 6, 4),
    std::make_tuple(8, 4, 0, 8, 6, 3, 0, 4),
    std::make_tuple(6, 4, 2, 6, 0, 1, 2, 4),
    std::make_tuple(2, 4, 6, 2, 0, 3, 6, 4),
    std::make_tuple(8, 4, 0, 8, 2, 1, 0, 4),
    std::make_tuple(6, 4, 2, 6, 8, 5, 2, 4),
    std::make_tuple(0, 4, 8, 0, 6, 7, 8, 4),
    // 048_0_345型
    std::make_tuple(0, 4, 8, 0, 3, 4, 5, 4),
    std::make_tuple(2, 4, 6, 2, 1, 4, 7, 4),
    std::make_tuple(8, 4, 0, 8, 5, 4, 3, 4),
    std::make_tuple(6, 4, 2, 6, 7, 4, 1, 4),
    std::make_tuple(2, 4, 6, 2, 5, 4, 3, 4),
    std::make_tuple(8, 4, 0, 8, 7, 4, 1, 4),
    std::make_tuple(6, 4, 2, 6, 3, 4, 5, 4),
    std::make_tuple(0, 4, 8, 0, 1, 4, 7, 4),
    // 048_0_048型
    std::make_tuple(0, 4, 8, 0, 0, 4, 8, 4),
    std::make_tuple(2, 4, 6, 2, 2, 4, 6, 4),
    std::make_tuple(8, 4, 0, 8, 8, 4, 0, 4),
    std::make_tuple(6, 4, 2, 6, 6, 4, 2, 4),
    // 048_0_246型
    std::make_tuple(0, 4, 8, 0, 2, 4, 6, 4),
    std::make_tuple(2, 4, 6, 2, 8, 4, 0, 4),
    std::make_tuple(8, 4, 0, 8, 6, 4, 2, 4),
    std::make_tuple(6, 4, 2, 6, 0, 4, 8, 4),

    /*モデル5*/
    // 048_4_012型
    std::make_tuple(0, 4, 8, 4, 0, 1, 2, 5),
    std::make_tuple(2, 4, 6, 4, 2, 5, 8, 5),
    std::make_tuple(8, 4, 0, 4, 8, 7, 6, 5),
    std::make_tuple(6, 4, 2, 4, 6, 3, 0, 5),
    // 048_4_258型
    std::make_tuple(0, 4, 8, 4, 2, 5, 8, 5),
    std::make_tuple(2, 4, 6, 4, 8, 7, 6, 5),
    std::make_tuple(8, 4, 0, 4, 6, 3, 0, 5),
    std::make_tuple(6, 4, 2, 4, 0, 1, 2, 5),
    // 048_4_345型
    std::make_tuple(0, 4, 8, 4, 3, 4, 5, 5),
    std::make_tuple(2, 4, 6, 4, 1, 4, 7, 5),
    // 048_4_147型
    std::make_tuple(0, 4, 8, 4, 1, 4, 7, 5),
    std::make_tuple(2, 4, 6, 4, 5, 4, 3, 5),
    // 048_4_048型
    std::make_tuple(0, 4, 8, 4, 0, 4, 8, 5),
    std::make_tuple(2, 4, 6, 4, 2, 4, 6, 5),
    // 048_4_246型
    std::make_tuple(0, 4, 8, 4, 2, 4, 6, 5),
    std::make_tuple(2, 4, 6, 4, 8, 4, 0, 5),
};

std::array<std::bitset<16>, 192> Features::MakeFeatures(LearnData learndata)
{
    std::array<std::bitset<16>, 192> features = {};
    for (int i = 0; i < 192; i++)
    {
        auto &feature = features[i];

        auto &[g0, g1, g2, gf, l0, l1, l2, m] = idxes[i];
        short pos0 = Board::LocalPosToPos(gf, l0);
        short pos1 = Board::LocalPosToPos(gf, l1);
        short pos2 = Board::LocalPosToPos(gf, l2);

        if (learndata.global_board[g0] == Cell::ME)
            feature |= 1 << 0;
        else if (learndata.global_board[g0] == Cell::OPPONENT)
            feature |= 1 << 1;
        else if (learndata.global_board[g0] == Cell::NO_ONE)
            feature |= 1 << 2;

        if (learndata.global_board[g1] == Cell::ME)
            feature |= 1 << 3;
        else if (learndata.global_board[g1] == Cell::OPPONENT)
            feature |= 1 << 4;
        else if (learndata.global_board[g1] == Cell::NO_ONE)
            feature |= 1 << 5;

        if (learndata.global_board[g2] == Cell::ME)
            feature |= 1 << 6;
        else if (learndata.global_board[g2] == Cell::OPPONENT)
            feature |= 1 << 7;
        else if (learndata.global_board[g2] == Cell::NO_ONE)
            feature |= 1 << 8;

        if (learndata.global_board[gf] == Cell::NO_SET)
        {
            if (learndata.flat_board[pos0] == Cell::ME)
                feature |= 1 << 9;
            else if (learndata.flat_board[pos0] == Cell::OPPONENT)
                feature |= 1 << 10;

            if (learndata.flat_board[pos1] == Cell::ME)
                feature |= 1 << 11;
            else if (learndata.flat_board[pos1] == Cell::OPPONENT)
                feature |= 1 << 12;

            if (learndata.flat_board[pos2] == Cell::ME)
                feature |= 1 << 13;
            else if (learndata.flat_board[pos2] == Cell::OPPONENT)
                feature |= 1 << 14;
        }

        for (short pos : learndata.legal_moves)
        {
            if (pos == pos0 || pos == pos1 || pos == pos2)
            {
                feature |= 1 << 15;
                break;
            }
        }
    }
    return features;
}

std::string Features::GetPythonInverseIdxes()
{
    std::string idxes_inv_local_py = "idxes_inv_local = [";
    std::string idxes_inv_global_py = "idxes_inv_global = [";
    std::array<std::vector<std::tuple<short, short>>, 81> idxes_inv_local = {};
    std::array<std::vector<std::tuple<short, short>>, 9> idxes_inv_global = {};

    for (int i = 0; i < idxes.size(); i++)
    {
        auto &[g0, g1, g2, gf, l0, l1, l2, m] = idxes[i];

        short pos0 = Board::LocalPosToPos(gf, l0);
        short pos1 = Board::LocalPosToPos(gf, l1);
        short pos2 = Board::LocalPosToPos(gf, l2);

        idxes_inv_local[pos0].push_back(std::make_tuple(i, 0));
        idxes_inv_local[pos1].push_back(std::make_tuple(i, 1));
        idxes_inv_local[pos2].push_back(std::make_tuple(i, 2));
        idxes_inv_global[gf].push_back(std::make_tuple(i, 3));
    }

    for (int i = 0; i < 81; i++)
    {
        idxes_inv_local_py += "[";
        for (auto &[feature_idx, out_idx] : idxes_inv_local[i])
            idxes_inv_local_py += "(" + std::to_string(feature_idx) + "," + std::to_string(out_idx) + "),";
        idxes_inv_local_py.pop_back();
        idxes_inv_local_py += "],";
    }
    idxes_inv_local_py.pop_back();
    idxes_inv_local_py += "]";

    for (int i = 0; i < 9; i++)
    {
        idxes_inv_global_py += "[";
        for (auto &[feature_idx, out_idx] : idxes_inv_global[i])
            idxes_inv_global_py += "(" + std::to_string(feature_idx) + "," + std::to_string(out_idx) + "),";
        idxes_inv_global_py.pop_back();
        idxes_inv_global_py += "],";
    }
    idxes_inv_global_py.pop_back();
    idxes_inv_global_py += "]";

    return idxes_inv_local_py + idxes_inv_global_py;
}

std::string Features::GetPythonIdxes()
{
    std::string idxes_py = "idxes = [";
    for (auto &[g0, g1, g2, gf, l0, l1, l2, m] : idxes)
    {
        short pos0 = Board::LocalPosToPos(gf, l0);
        short pos1 = Board::LocalPosToPos(gf, l1);
        short pos2 = Board::LocalPosToPos(gf, l2);
        idxes_py += "(" +
                    std::to_string(g0) + "," +
                    std::to_string(g1) + "," +
                    std::to_string(g2) + "," +
                    std::to_string(gf) + "," +
                    std::to_string(pos0) + "," +
                    std::to_string(pos1) + "," +
                    std::to_string(pos2) + "," +
                    std::to_string(m) +
                    "),";
    }
    idxes_py.pop_back();
    idxes_py += "]";
    return idxes_py;
}

// std::string Features::Dump(LearnData learndata)
// {
//     std::string feature_str = "";
//     auto features = MakeFeatures(learndata);
//     for (auto &feature : features)
//     {
//         for (int i = 0; i < feature.size(); i++)
//         {
//             if (feature[i])
//                 feature_str += "1";
//             else
//                 feature_str += "0";
//         }
//         feature_str += ",";
//     }

//     nlohmann::json json = {
//         {"features", feature_str},

//     }
// }