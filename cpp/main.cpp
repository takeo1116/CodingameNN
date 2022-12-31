#include <iostream>
#include <memory>
#include <fstream>
#include "engine/game.hpp"
#include "agent/random_agent.hpp"
#include "agent/mcts_agent.hpp"
#include "learn/learndata.hpp"
#include "learn/features.hpp"

int main(int argc, char *argv[])
{
    // std::shared_ptr<MctsAgent> mcts_agent_100000(new MctsAgent(100000));
    // for (int j = 0; j < 100; j++)
    // {
    //     std::string filepath = argv[1];
    //     for (int i = 0; i < 1; i++)
    //     {
    //         Game<MctsAgent, MctsAgent> game(mcts_agent_100000, mcts_agent_100000, Player::PLAYER_1);
    //         game.Play();
    //         game.Dump(filepath);
    //     }
    // }

    std::cout << Features::GetPythonInverseIdxes() << std::endl;

    return 0;
}