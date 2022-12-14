#include <string>
#include <vector>
#include "action.hpp"
#include "state.hpp"

class ActionData{
public:
    int playerIdx;
    bool isFirst;
    std::string agentName;
    State state;
    Action action;

    ActionData(int playerIdx, bool isFirst, std::string agentName, State& state, Action action){
        this->playerIdx = playerIdx;
        this->isFirst = isFirst;
        this->agentName = agentName;
        this->state = state;
        this->action = action;
    }
};

class Record{
private:
    std::vector<ActionData> storage;
public:
    bool Add(ActionData& actionData){
        storage.push_back(actionData);
    }
};