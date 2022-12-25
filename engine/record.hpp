#pragma once
#include <string>
#include <vector>
#include "action.hpp"
#include "state.hpp"

class ActionData
{
public:
    std::string agent_name;
    State state;
    Action action;

    std::string Dump(Result result)
    {
        std::string str = "{";
        str += "is_first:" + std::to_string(state.IsFirstPlayer()) + ",";
        str += "agent_name:" + agent_name + ",";
        str += "flat_board:[";
        for (Cell cell : state.MakeFlatBoard())
        {
            if (cell == Cell::NO_SET)
                str += "0,";
            else if (cell == Cell::ME)
                str += "1,";
            else if (cell == Cell::OPPONENT)
                str += "2,";
            else
                throw std::runtime_error("in Action::Dump()");
        }
        str.pop_back();
        str += "],";
        str += "legal_moves:[";
        for (int a : state.GetLegalPositions())
            str += std::to_string(a) + ",";
        str.pop_back();
        str += "],";
        str += "move:" + std::to_string(action.GetMove()) + ",";
        str += "result_value:";
        if ((state.GetPlayer() == Player::PLAYER_1 && result == Result::PLAYER1_WIN) || (state.GetPlayer() == Player::PLAYER_2 && result == Result::PLAYER2_WIN))
            str += "1.0,";
        else if ((state.GetPlayer() == Player::PLAYER_1 && result == Result::PLAYER2_WIN) || (state.GetPlayer() == Player::PLAYER_2 && result == Result::PLAYER1_WIN))
            str += "-1.0,";
        else
            str += "0.0,";
        str += "state_value:" + std::to_string(action.GetStateValue()) + ",";
        str += "action_values:[";
        for (float a : action.GetActionValues())
            str += std::to_string(a) + ",";
        str.pop_back();
        str += "]";
        str += "}";

        return str;
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
    void Dump()
    {
        std::vector<std::string> strings;
        for (auto &actiondata : storage)
        {
            std::string str = actiondata.Dump(result);
            strings.push_back(str);
            std::cout << str << std::endl;
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