#pragma once

class IShape
{
    public:
        virtual double getArea() const noexcept = 0;
        virtual ~IShape() = default;
};
