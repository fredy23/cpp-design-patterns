#pragma once

#include <string>

#include "inameable.hpp"

class IEnemy : private INameable
{
public:
    bool isAlive() const noexcept
    {
        return m_health > 0;
    }

    double getHealth() const noexcept
    {
        return m_health;
    }

    void setName(const std::string& p_name)
    {
        INameable::setName(p_name);
    }

    std::string getName() const
    {
        return INameable::getName();
    }

    virtual void injure(double p_damage) noexcept = 0;
    virtual ~IEnemy() = default;

protected:
    double m_health {100.0};
};
