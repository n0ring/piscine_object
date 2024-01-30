#pragma once 

#include <iostream>
#include "Wheel.hpp"

#define WHEEL_COUNT 2

class SteeringGear {
public: 
	SteeringGear() {
	}
	~SteeringGear() {}
	SteeringGear& operator=(const SteeringGear& rhs) {
		if (this == &rhs)
			return *this;
		wheel[0] = rhs.wheel[0];
		wheel[1] = rhs.wheel[1];
		return *this;
	}
	SteeringGear(const SteeringGear& rhs) {
		*this = rhs;
	}
	
	void turn_wheel(float angle) {
		for (int i = 0 ; i < WHEEL_COUNT ; i++) {
			wheel[i].changeAngle(angle);
		}
	}
private:
	Wheel wheel[WHEEL_COUNT];
};