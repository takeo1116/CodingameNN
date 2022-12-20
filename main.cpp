#include <iostream>
#include "engine/game.hpp"
#include "agent/random_agent.hpp"

int main()
{
    std::cout << "test" << std::endl;
    RandomAgent random_agent;
    auto game = Game<RandomAgent, RandomAgent>(random_agent, random_agent, Player::PLAYER_1);
    game.Play();
    return 0;
}