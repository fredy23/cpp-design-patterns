#include <iostream>
#include <vector>

#include "ishape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "right_triangle.hpp"
#include "right_triangle_adapter.hpp"

void printShapeInfo(const IShape& p_shape)
{
    std::cout << p_shape.getName() << " info: \n";
    std::cout << "Area equals " << p_shape.getArea() << '\n';
    std::cout << "Perimeter equals " << p_shape.getPerimeter() << "\n";
}

int main()
{
    Triangle triangle { 3, 4, 5 };
    printShapeInfo(triangle);

    std::cout << '\n';

    Rectangle rectangle { 8, 14 };
    printShapeInfo(rectangle);

    std::cout << '\n';

    RightTriangle rightTriangle { 5, 12 };
    std::cout << "Right triangle hypotenuse equals " << rightTriangle.getHypotenuse() << '\n';

    RightTriangleAdapter rightTriangleAdapter { 5, 12 };
    printShapeInfo(rightTriangleAdapter);
}
