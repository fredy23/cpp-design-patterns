#pragma once

#include "ienemy.hpp"

class SpiderEnemy : public IEnemy
{
    public:
        SpiderEnemy()
            : IEnemy{100}
        {
        }

        void attack(IEnemy& p_enemy) override
        {
            p_enemy.injure(10);
        }    
};
