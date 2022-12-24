#include <iostream>
#include <memory>
#include "engine/game.hpp"
#include "agent/random_agent.hpp"
#include "agent/mcts_agent.hpp"

int main()
{
    std::shared_ptr<RandomAgent> random_agent(new RandomAgent());
    // Game<RandomAgent, RandomAgent> game(random_agent, random_agent, Player::PLAYER_1);

    std::shared_ptr<MctsAgent> mcts_agent_50000(new MctsAgent(50000));
    std::shared_ptr<MctsAgent> mcts_agent_5000(new MctsAgent(5000));
    Game<MctsAgent, MctsAgent> game(mcts_agent_50000, mcts_agent_5000, Player::PLAYER_1);

    // Game<MctsAgent, RandomAgent> game(mcts_agent, random_agent, Player::PLAYER_1);

    game.Play();
    return 0;
}