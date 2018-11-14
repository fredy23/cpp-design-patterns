#include <iostream>
#include <vector>
#include <memory>

#include "ishape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

using ShapePtr = std::unique_ptr<IShape>;

void printShapesPerimeters(const std::vector<ShapePtr>& p_shapes)
{
    for(const auto& shape : p_shapes)
    {
        std::cout << shape->getPerimeter() << ' ';
    }

    std::cout << '\n';
}

int main()
{
    std::vector<ShapePtr> shapes {};

    shapes.emplace_back(std::make_unique<Rectangle>(5, 8));
    shapes.emplace_back(std::make_unique<Circle>(7));
    shapes.emplace_back(std::make_unique<Rectangle>(4, 4));
    shapes.emplace_back(std::make_unique<Circle>(12));

    std::cout << "Created vector of shapes\n";

    std::vector<ShapePtr> enlargedShapes {};

    auto scaleFactor = 2.0;

    for(const auto& shape : shapes)
    {
        enlargedShapes.emplace_back(shape->clone());
        enlargedShapes.back()->enlarge(scaleFactor);
    }

    std::cout << "Created vector of enlarged shapes with scale factor " << scaleFactor << '\n';

    std::cout << "Shapes perimeters: ";

    printShapesPerimeters(shapes);

    std::cout << "Enlarged shapes perimeters: ";

    printShapesPerimeters(enlargedShapes);
}
