#pragma once

class IGame
{
public:
    virtual void play() const = 0;
    virtual ~IGame() = default;
};
