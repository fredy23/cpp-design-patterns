#pragma once

#include <memory>

class IEnemy;

class IEnemyFactory
{
public:
    virtual std::unique_ptr<IEnemy> createEnemy() const = 0;
    virtual ~IEnemyFactory() = default;
};
