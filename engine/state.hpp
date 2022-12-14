#pragma once
#include <array>
#include <vector>

class State
{
private:
    std::array<char, 81> flat_board;
    std::array<bool, 81> legal_moves;

public:
    std::vector<int> GetLegalPositions()
    {
        /*合法手のリストを得る*/

    }
};