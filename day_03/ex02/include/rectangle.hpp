#pragma once 

#include "shape.hpp"

class Rectangle : public Shape {
	public:
		Rectangle(float width, float height) : width(width), height(height) {}
		virtual ~Rectangle() {}
		Rectangle(const Rectangle& other) : Shape(other), width(other.width), height(other.height) {}
		Rectangle& operator=(const Rectangle& other) {
			if (this == &other) {
				return *this;
			}
			Shape::operator=(other);
			width = other.width;
			height = other.height;
			return *this;
		}

		virtual float getArea() const {
			return width * height;
		}

		virtual float getPerimeter() const {
			return 2 * (width + height);
		}

	private: 
		Rectangle() {}
		float width;
		float height;
};