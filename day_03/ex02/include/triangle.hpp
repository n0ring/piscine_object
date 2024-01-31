#pragma once 

#include <cmath>

class Triangle : public Shape {
	public: 
		Triangle(float _a, float _b, float _c) : a(_a), b(_b), c(_c) {}
		virtual ~Triangle() {}
		Triangle(const Triangle& other) : a(other.a), b(other.b), c(other.c) {}
		Triangle& operator=(const Triangle& other) {
			if (this == &other) {
				return *this;
			}
			a = other.a;
			b = other.b;
			c = other.c;
			return *this;
		}

		float getArea() const {
			double s = (a + b + c) / 2;
   			return sqrt(s * (s - a) * (s - b) * (s - c));
		}

		float getPerimeter() const {
			return a + b + c;
		}

	private:
		Triangle() {}
		float a;
		float b;
		float c;
};