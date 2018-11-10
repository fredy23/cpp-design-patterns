#pragma once

#include <memory>

class IGun;
class IEnemy;

class IGameFactory
{
public:
    virtual std::unique_ptr<IGun> createGun() const = 0;
    virtual std::unique_ptr<IEnemy> createEnemy() const = 0;
    virtual ~IGameFactory() = default;
};
