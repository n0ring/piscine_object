#pragma once 

#include "shape.hpp"

#define PI 3.14159265

class Circle : public Shape {
	public:
		Circle(float radius) : radius(radius) {}
		virtual ~Circle() {}
		Circle(const Circle& other) : Shape(other), radius(other.radius) {}
		Circle& operator=(const Circle& other) {
			if (this == &other) {
				return *this;
			}
			Shape::operator=(other);
			radius = other.radius;
			return *this;
		}

		virtual float getArea() const {
			return PI * radius * radius;
		}

		virtual float getPerimeter() const {
			return 2 * PI * radius;
		}
	private: 
		Circle() {}
		float radius;
};