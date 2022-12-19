#pragma once
#include <string>
#include <vector>
#include "action.hpp"
#include "state.hpp"

class ActionData
{
public:
    Player now_player;
    Player first_player;
    std::string agent_name;
    State state;
    Action action;

    ActionData(Player now_player, Player first_player, std::string agent_name, State state, Action action)
    {
        this->now_player = now_player;
        this->first_player = first_player;
        this->agent_name = agent_name;
        this->state = state;
        this->action = action;
    }
};

class Record
{
private:
    std::vector<ActionData> storage;
    Result result;

public:
    void Add(ActionData &action_data)
    {
        storage.push_back(action_data);
    }
    void SetResult(Result result)
    {
        this->result = result;
    }
};