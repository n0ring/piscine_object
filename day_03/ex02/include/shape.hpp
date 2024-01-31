#pragma once 

class Shape {
	public: 
		Shape() {}
		virtual ~Shape() {}
		Shape(const Shape& other) {
			*this = other; // call operator=(other)
		}
		Shape& operator=(const Shape& other) {
			if (this == &other) {
				return *this;
			}
			return *this;
		}

		virtual float getArea() const = 0;
		virtual float getPerimeter() const = 0;
	private: 
};