#pragma once
#include <string>
#include "action.hpp"
#include "state.hpp"

class AgentBase{
public:
    virtual Action RequestAction(State state) = 0;
    virtual std::string GetAgentName(){
        return "AgentBase";
    }
    virtual ~AgentBase() {};
};