#pragma once

#include <memory>

#include "igame_factory.hpp"
#include "igun.hpp"
#include "revolver_gun.hpp"
#include "ienemy.hpp"
#include "cowboy_enemy.hpp"

class WildWestGameFactory : public IGameFactory
{
public:
    std::unique_ptr<IGun> createGun() const override
    {
        return std::make_unique<RevolverGun>();
    }

    std::unique_ptr<IEnemy> createEnemy() const override
    {
        return std::make_unique<CowboyEnemy>();
    }
};
