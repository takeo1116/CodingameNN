#include <array>
#include <vector>
#include "agent.hpp"
#include "board.hpp"

class Game
{
private:
    std::array<AgentBase, 2> players;
    Board board;
    std::vector<Action> action;

public:
};