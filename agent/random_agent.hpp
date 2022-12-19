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
        
    }
    std::string GetAgentName()
    {
        return "RandomAgent";
    }
};