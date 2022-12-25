#pragma once
#include "state.hpp"

struct Action
{
    /*agentからの出力*/
private:
    int move;

    float state_value = 0.0f;                 // 学習用：状態価値
    std::array<float, 81> action_values = {}; // 学習用：各アクションの価値

public:
    int GetMove()
    {
        return move;
    }
    float GetStateValue()
    {
        return state_value;
    }
    std::array<float, 81> GetActionValues()
    {
        return action_values;
    }
    Action()
    {
    }
    Action(int pos)
    {
        move = pos;
    }
    Action(int pos, float state_value, std::array<float, 81> action_values)
    {
        /*学習用*/
        this->move = pos;
        this->state_value = state_value;
        this->action_values = action_values;
    }
};