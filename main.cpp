#include <iostream>
#include <memory>
#include "engine/game.hpp"
#include "agent/random_agent.hpp"

int main()
{
    std::cout << "test" << std::endl;
    std::shared_ptr<RandomAgent> random_agent(new RandomAgent());
    Game<RandomAgent, RandomAgent> game(random_agent, random_agent, Player::PLAYER_1);
    game.Play();
    return 0;
}