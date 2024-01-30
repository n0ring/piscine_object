#pragma once 

#include "Brake.hpp"

class BrakeController {
public:
	BrakeController() {}
	~BrakeController() {}
	BrakeController& operator=(const BrakeController& rhs) {
		if (this == &rhs)
			return *this;
		brake = rhs.brake;
		return *this;
	}
	BrakeController(const BrakeController& rhs) {
		*this = rhs;
	}

	void apply_force_on_brakes(int force) {
		std::cout << "BrakeController: apply_force_on_brakes - " << force << std::endl;
		brake.change_current_force(force);
	}

	void apply_emergency_brakes() {
		std::cout << "BrakeController: apply_emergency_brakes" << std::endl;
		brake.change_current_force(100);
	}

private: 
	Brake brake;

};