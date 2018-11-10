#pragma once

#include <memory>

#include "igame_factory.hpp"
#include "igun.hpp"
#include "plasma_gun.hpp"
#include "ienemy.hpp"
#include "alien_enemy.hpp"

class SpaceGameFactory : public IGameFactory
{
public:
    std::unique_ptr<IGun> createGun() const override
    {
        return std::make_unique<PlasmaGun>();
    }

    std::unique_ptr<IEnemy> createEnemy() const override
    {
        return std::make_unique<AlienEnemy>();
    }
};
