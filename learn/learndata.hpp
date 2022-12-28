#pragma once
#include <array>
#include <string>
#include <vector>

class LearnData
{
public:
    std::array<float, 81> action_values;
    std::string agent_name;
    std::array<short, 81> flat_board;
    bool is_first;
    std::vector<short> legal_moves;
    short move;
    float result_value;
    float state_value;

    
};