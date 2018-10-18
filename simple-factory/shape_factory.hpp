#pragma once

#include <memory>
#include <type_traits>

#include "shape.hpp"
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
        std::unique_ptr<Shape> createShape(ShapeType p_type, Args&&... args);

    private:
        template<typename T, typename... Args>
        std::unique_ptr<T> construct(...)
        {
            return nullptr;
        }

        template<typename T, typename... Args>
        std::enable_if_t<std::is_constructible<T, Args...>::value, std::unique_ptr<T>>
        construct(Args&&... args)
        {
            return std::make_unique<T>(std::forward<Args>(args)...);
        }
};

template<typename... Args>
std::unique_ptr<Shape> ShapeFactory::createShape(ShapeType p_type, Args&&... args)
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
