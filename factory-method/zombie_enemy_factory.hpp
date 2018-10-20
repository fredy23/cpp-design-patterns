#pragma once

#include <memory>

#include "ienemy.hpp"
#include "zombie_enemy.hpp"
#include "ienemy_factory.hpp"

class ZombieEnemyFactory : public IEnemyFactory
{
    public:
        std::unique_ptr<IEnemy> createEnemy() const override
        {
            return std::make_unique<ZombieEnemy>();
        }
};
