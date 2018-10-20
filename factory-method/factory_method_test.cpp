#include <iostream>

#include "spider_enemy_factory.hpp"
#include "zombie_enemy_factory.hpp"

int main()
{
    SpiderEnemyFactory spiderFactory {};

    auto spiderEnemy = spiderFactory.createEnemy();
    std::cout << "Created spider with " << spiderEnemy->getHealth() << " health\n";

    ZombieEnemyFactory zombieFactory {};

    auto zombieEnemy = zombieFactory.createEnemy();
    std::cout << "Created zombie with " << zombieEnemy->getHealth() << " health\n";

    std::cout << "Spider attacks zombie!\n";
    spiderEnemy->attack(*zombieEnemy);

    std::cout << "Zombie has now " << zombieEnemy->getHealth() << " health\n";

    std::cout << "Now zombie attacks spider!\n";
    zombieEnemy->attack(*spiderEnemy);

    std::cout << "Spider has now " << spiderEnemy->getHealth() << " health\n";

    std::cout << "Zombie attacks spider again!\n";
    zombieEnemy->attack(*spiderEnemy);

    std::cout << "Spider has now " << spiderEnemy->getHealth() << " health\n";

    std::cout << "Spider attacks zombie!\n";
    spiderEnemy->attack(*zombieEnemy);

    std::cout << "Zombie has now " << zombieEnemy->getHealth() << " health\n";

    std::cout << "Zombie attacks spider for the last time!\n";
    zombieEnemy->attack(*spiderEnemy);

    if(!spiderEnemy->isAlive())
    {
        std::cout << "Spider is dead\n";
    }
}
