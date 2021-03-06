#pragma once

#include <memory>
#include <type_traits>

#include "ishape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

class ShapeFactory
{
public:
    enum class ShapeType
    {
        TYPE_CIRCLE,
        TYPE_RECTANGLE,
    };

    template<typename... Args>
    std::unique_ptr<IShape> createShape(ShapeType p_type, Args&&... args) const;

private:
    template<typename T, typename... Args>
    std::unique_ptr<T> construct(...) const
    {
        return nullptr;
    }

    template<typename T, typename... Args>
    std::enable_if_t<std::is_constructible<T, Args...>::value, std::unique_ptr<T>>
    construct(Args&&... args) const
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
};

template<typename... Args>
std::unique_ptr<IShape> ShapeFactory::createShape(ShapeType p_type, Args&&... args) const
{
    if(p_type == ShapeType::TYPE_CIRCLE)
    {
        return construct<Circle, Args...>(std::forward<Args>(args)...);
    }
    else if(p_type == ShapeType::TYPE_RECTANGLE)
    {
        return construct<Rectangle, Args...>(std::forward<Args>(args)...);
    }

    return nullptr;
}
