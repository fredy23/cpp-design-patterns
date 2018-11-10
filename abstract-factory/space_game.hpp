#pragma once

#include <iostream>

#include "igame.hpp"
#include "space_game_factory.hpp"

class SpaceGame : public IGame
{
public:
    void play() const override
    {
        SpaceGameFactory spaceGameFactory {};

        auto spaceGun = spaceGameFactory.createGun();
        auto spaceEnemy = spaceGameFactory.createEnemy();

        std::cout << "Created " << spaceGun->getName() << "\n";

        std::cout << "Created " << spaceEnemy->getName() << " enemy with "
                <<  spaceEnemy->getHealth() << " health\n";

        std::cout << "Taking 6 shots to enemy!\n";

        for(auto i = 0u; i < 6; ++i)
        {
            spaceGun->shoot(*spaceEnemy);
            std::cout << "Enemy has now " << spaceEnemy->getHealth() << " health\n";
        }

        std::cout << "Taking last shot to enemy!\n";

        spaceGun->shoot(*spaceEnemy);

        std::cout << "Enemy has now " << spaceEnemy->getHealth() << " health\n";

        if(!spaceGun->isUsable())
        {
            std::cout << spaceGun->getName() << " is unusable\n";
        }

        if(spaceEnemy->isAlive())
        {
            std::cout << spaceEnemy->getName() << " enemy is still alive!\n";
        }
    }

private:
    SpaceGameFactory m_gameFactory {};
};
