#pragma once

#include <memory>

#include "ienemy.hpp"

class IEnemyFactory
{
public:
    virtual std::unique_ptr<IEnemy> createEnemy() const = 0;
    virtual ~IEnemyFactory() = default;
};
