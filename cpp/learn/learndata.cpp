#include "learndata.hpp"
#include "../engine/cell.hpp"

std::string LearnData::GetJsonString()
{
    nlohmann::json json = {
        {"is_first", is_first},
        {"agent_name", agent_name},
        {"flat_board", flat_board},
        {"global_board", global_board},
        {"legal_moves", legal_moves},
        {"move", move},
        {"result_value", result_value},
        {"state_value", state_value},
        {"action_values", action_values},
    };

    return json.dump();
}

LearnData::LearnData(std::array<Cell, 81> flat_board, std::vector<int> legal_moves, std::array<Cell, 9> global_board, bool is_first, std::string agent_name, int move, float state_value, std::array<float, 81> action_values, float result_value)
{
    this->flat_board = flat_board;
    this->legal_moves = legal_moves;
    this->global_board = global_board;
    this->is_first = is_first;
    this->agent_name = agent_name;
    this->move = move;
    this->state_value = state_value;
    this->action_values = action_values;
    this->result_value = result_value;
}

LearnData::LearnData(std::string json_string)
{
    nlohmann::json json = nlohmann::json::parse(json_string);

    this->flat_board = json["flat_board"].get<std::array<Cell, 81>>();
    this->legal_moves = json["legal_moves"].get<std::vector<int>>();
    this->global_board = json["global_board"].get<std::array<Cell, 9>>();
    this->is_first = json["is_first"].get<bool>();
    this->agent_name = json["agent_name"].get<std::string>();
    this->move = json["move"].get<int>();
    this->state_value = json["state_value"].get<float>();
    this->action_values = json["action_values"].get<std::array<float, 81>>();
    this->result_value = json["result_value"].get<float>();
}

// Features LearnData::MakeFeatures()
// {

// }