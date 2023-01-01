#pragma once
#include <array>
#include <string>
#include <vector>
#include "../engine/cell.hpp"
#include "../nlohmann/json.hpp"

class LearnData
{
public:
    std::array<float, 81> action_values;
    std::string agent_name;
    std::array<Cell, 81> flat_board;
    std::array<Cell, 9> global_board;
    bool is_first;
    std::vector<int> legal_moves;
    int move;
    float result_value;
    float state_value;

    std::string GetJsonString();

    LearnData(std::array<Cell, 81> flat_board, std::vector<int> legal_moves, std::array<Cell, 9> global_board, bool is_first, std::string agent_name, int move, float state_value, std::array<float, 81> action_values, float result_value);

    LearnData(std::string json_string);
};