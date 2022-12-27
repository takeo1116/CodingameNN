#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "action.hpp"
#include "state.hpp"
#include "../nlohmann/json.hpp"

class ActionData
{
public:
    std::string agent_name;
    State state;
    Action action;
    float GetResultValue(Result result)
    {
        if ((state.GetPlayer() == Player::PLAYER_1 && result == Result::PLAYER1_WIN) || (state.GetPlayer() == Player::PLAYER_2 && result == Result::PLAYER2_WIN))
            return 1.0f;
        else if ((state.GetPlayer() == Player::PLAYER_1 && result == Result::PLAYER2_WIN) || (state.GetPlayer() == Player::PLAYER_2 && result == Result::PLAYER1_WIN))
            return -1.0f;
        else
            return 0.0f;
    }
    std::string Dump(Result result)
    {
        nlohmann::json json = {
            {"is_first", state.IsFirstPlayer()},
            {"agent_name", agent_name},
            {"flat_board", state.MakeFlatBoard()},
            {"legal_moves", state.GetLegalPositions()},
            {"move", action.GetMove()},
            {"result_value", GetResultValue(result)},
            {"state_value", action.GetStateValue()},
            {"action_values", action.GetActionValues()},
        };

        return json.dump();
    }
    ActionData(std::string agent_name, State state, Action action)
    {
        this->agent_name = agent_name;
        this->state = state;
        this->action = action;
    }
};

class Record
{
private:
    std::vector<ActionData> storage;
    Result result = Result::NO_SET;

public:
    void Add(ActionData &action_data)
    {
        storage.push_back(action_data);
    }
    void SetResult(Result result)
    {
        this->result = result;
    }
    void Dump(std::string output_path = "NO_SET")
    {
        for (auto &actiondata : storage)
        {
            std::string str = actiondata.Dump(result);
            // std::cout << str << std::endl;
            if (output_path != "NO_SET")
            {
                std::ofstream ofs(output_path, std::ios::app);
                ofs << str << std::endl;
            }
        }
    }
    int GetLastAction()
    {
        int last_action = -1;
        if (!storage.empty())
            last_action = storage.back().action.GetMove();
        return last_action;
    }
};