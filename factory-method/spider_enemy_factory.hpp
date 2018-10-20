#pragma once

#include <memory>

#include "ienemy.hpp"
#include "spider_enemy.hpp"
#include "ienemy_factory.hpp"

class SpiderEnemyFactory : public IEnemyFactory
{
    public:
        std::unique_ptr<IEnemy> createEnemy() const
        {
            return std::make_unique<SpiderEnemy>();
        }
};
