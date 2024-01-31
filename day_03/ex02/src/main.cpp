
#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void test(Shape *shape, std::string name) {
	std::cout << "Shape: " << name << std::endl;
	std::cout << "Area: " << shape->getArea() << std::endl;
	std::cout << "Perimeter: " << shape->getPerimeter() << std::endl;
}

int main() {
	Rectangle r(10, 20);
	Circle c(10);
	Triangle t(7, 10, 12);
	test(&r, "Rectangle");
	test(&c, "Circle");
	test(&t, "Triangle");


	return 0;
}