#pragma once 

#include <iostream>
#include "Gear.hpp"

#define GEAR_COUNT 10

class GearController {
public: 
	GearController() {
		currentGearIdx = 0;
	}
	~GearController() {}
	GearController& operator=(const GearController& rhs) {
		if (this == &rhs)
			return *this;
		currentGearIdx = rhs.currentGearIdx;
		for (int i = 0 ; i < GEAR_COUNT ; i++) {
			gear[i] = rhs.gear[i];
		}
		return *this;
	}
	GearController(const GearController& rhs) {
		*this = rhs;
	}

	void shift_gears_up() {
		if (currentGearIdx < GEAR_COUNT - 1) {
			currentGearIdx++;
			std::cout << "GearController: shift gears up to: " << currentGearIdx << std::endl;
		} else {
			std::cout << "GearController: shift gears up ERROR idx: " << currentGearIdx << std::endl;
		}
	}

	void shift_gears_down() {
		if (currentGearIdx > 0) {
			currentGearIdx--;
			std::cout << "GearController: shift gears down to: " << currentGearIdx << std::endl;
		} else {
			std::cout << "GearController: shift gears down ERROR idx: " << currentGearIdx << std::endl;
		}
	}
private: 
	Gear gear[GEAR_COUNT];
	int currentGearIdx;
};