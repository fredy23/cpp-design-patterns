#pragma once

class IEnemy
{
    public:
        IEnemy(double p_health)
            : m_health{p_health}
        {
        }

        void injure(double p_damage)
        {
            m_health -= (m_health > p_damage ? p_damage : m_health);
        }

        double getHealth() const noexcept
        {
            return m_health;
        }

        bool isAlive() const noexcept
        {
            return m_health > 0;
        }

        virtual void attack(IEnemy& p_enemy) = 0;
        virtual ~IEnemy() = default;

    protected:
        double m_health;
};
