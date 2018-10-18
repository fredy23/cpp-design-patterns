#pragma once

class Shape
{
    public:
        virtual double getArea() const noexcept = 0;
        virtual ~Shape() = default;
};
