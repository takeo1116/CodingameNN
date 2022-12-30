#pragma once
#include <array>
#include <tuple>
#include <bitset>
#include "../engine/board.hpp"

class Features
{
public:
    static const std::array<std::tuple<short, short, short, short>, 24> grobal_idxes;
    // static const std::array<std::tuple<short, short, short>, 8> local_idxes;

    std::array<std::bitset<13>, 192> MakeFeatures();
};

// const std::array<std::tuple<short, short, short, short>, 24> Features::grobal_idxes = {
//     std::make_tuple(1, 2, 3, 1),
//     std::make_tuple(1, 2, 3, 2),
//     std::make_tuple(1, 2, 3, 3),
//     std::make_tuple(3, 6, 9, 3),
//     std::make_tuple(3, 6, 9, 6),
//     std::make_tuple(3, 6, 9, 9),
//     std::make_tuple(9, 8, 7, 9),
//     std::make_tuple(9, 8, 7, 8),
//     std::make_tuple(9, 8, 7, 7),
//     std::make_tuple(7, 4, 1, 7),
//     std::make_tuple(7, 4, 1, 4),
//     std::make_tuple(7, 4, 1, 1),
//     std::make_tuple(4, 5, 6, 4),
//     std::make_tuple(4, 5, 6, 5),
//     std::make_tuple(4, 5, 6, 6),
//     std::make_tuple(2, 5, 8, 2),
//     std::make_tuple(2, 5, 8, 5),
//     std::make_tuple(2, 5, 8, 8),
//     std::make_tuple(1, 5, 9, 1),
//     std::make_tuple(1, 5, 9, 5),
//     std::make_tuple(1, 5, 9, 9),
//     std::make_tuple(3, 5, 7, 3),
//     std::make_tuple(3, 5, 7, 5),
//     std::make_tuple(2, 5, 7, 7),
// };

// std::array<std::bitset<13>, 192> Features::MakeFeatures()
// {
//     std::array<std::bitset<13>, 192> features = {};
//     for (int i = 0; i < 192; i++)
//     {
//         std::bitset<13> &feature = features[i];
//         int g = i / 8, l = i % 8;
//         auto &[g1, g2, g3, gf] = grobal_idxes[g];
//         auto &[l1, l2, l3] = LocalBoard::bingo[l];
        
        
//     }
// }