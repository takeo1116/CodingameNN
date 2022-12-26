#include <iostream>
#include <memory>
#include <fstream>
#include "engine/game.hpp"
#include "agent/random_agent.hpp"
#include "agent/mcts_agent.hpp"

int main(int argc, char *argv[])
{
    std::shared_ptr<RandomAgent> random_agent(new RandomAgent());
    std::shared_ptr<MctsAgent> mcts_agent_100000(new MctsAgent(1000));
    while (true)
    {
        std::string filepath = argv[1];
        std::ofstream ofs(filepath);
        for (int i = 0; i < 1; i++)
        {
            Game<MctsAgent, MctsAgent> game(mcts_agent_100000, mcts_agent_100000, Player::PLAYER_1);
            game.Play();
            game.Dump();
        }
    }

    return 0;
}