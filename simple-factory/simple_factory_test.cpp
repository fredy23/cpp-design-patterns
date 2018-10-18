#include <iostream>
#include <memory>

#include "shape_factory.hpp"

int main()
{
    ShapeFactory factory {};

    std::cout << "Creating rectangle with width 6 and height 8\n";

    auto rectangleShape = factory.createShape(ShapeFactory::ShapeType::TYPE_RECTANGLE, 6, 8);
    std::cout << "Rectangle area is " << rectangleShape->getArea() << '\n';

    std::cout << "Creating circle with radius 5\n";

    auto circleShape = factory.createShape(ShapeFactory::ShapeType::TYPE_CIRCLE, 5);
    std::cout << "Circle area is " << circleShape->getArea() << '\n';
}
