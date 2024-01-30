#pragma once 

#include <iostream>

class Wheel {
public: 
	Wheel() {
		angle = 0;
	}
	~Wheel() {}
	Wheel& operator=(const Wheel& rhs) {
		if (this == &rhs)
			return *this;
		return *this;
	}
	Wheel(const Wheel& rhs) {
		*this = rhs;
	}
	
	void changeAngle(float newAngle) {
		std::cout << "Wheel: change angle to: " << newAngle << std::endl;
		angle = newAngle;
	}

private: 
	float angle;
};