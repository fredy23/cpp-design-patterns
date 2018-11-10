#pragma once

#include <iostream>

#include "igame.hpp"
#include "wild_west_game_factory.hpp"

class WildWestGame : public IGame
{
public:
    void play() const override
    {
        auto wildWestGun = m_gameFactory.createGun();
        auto wildWestEnemy = m_gameFactory.createEnemy();

        std::cout << "Created " << wildWestGun->getName() << "\n";

        std::cout << "Created " << wildWestEnemy->getName() << " enemy with "
                <<  wildWestEnemy->getHealth() << " health\n";


        std::cout << "Taking first shot to enemy!\n";

        wildWestGun->shoot(*wildWestEnemy);

        std::cout << "Enemy has now " << wildWestEnemy->getHealth() << " health\n";

        std::cout << "Taking second shot to enemy!\n";

        wildWestGun->shoot(*wildWestEnemy);

        std::cout << "Enemy has now " << wildWestEnemy->getHealth() << " health\n";

        if(!wildWestEnemy->isAlive())
        {
            std::cout << "Enemy is eliminated\n";
        }
    }

private:
    WildWestGameFactory m_gameFactory {};
};
