#pragma once
#include <random>
#include "../engine/agent.hpp"

class RandomAgent : public AgentBase
{
private:
    std::random_device random;

public:
    Action RequestAction(State state) override
    {
        auto legal_positions = state.GetLegalPositions();
        int index = random() % legal_positions.size();
        return legal_positions[index];
    }
    std::string GetAgentName()
    {
        return "RandomAgent";
    }
    RandomAgent() : AgentBase()
    {

    }
};