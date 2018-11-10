#pragma once

#include <string>

#include "inameable.hpp"

class IEnemy;

class IGun : private INameable
{
public:
    void setName(const std::string& p_name)
    {
        INameable::setName(p_name);
    }

    std::string getName() const
    {
        return INameable::getName();
    }

    virtual void shoot(IEnemy& p_enemy) noexcept = 0;
    virtual bool isUsable() const noexcept = 0;
    virtual ~IGun() = default;
};
