#pragma once

#include <memory>

class IShape
{
public:
    virtual double getPerimeter() const noexcept = 0;
    virtual void enlarge(double p_scaleFactor) noexcept = 0;
    virtual std::unique_ptr<IShape> clone() const = 0;
    virtual ~IShape() = default;
};
