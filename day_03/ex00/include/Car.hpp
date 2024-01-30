#pragma once 

#include "Engine.hpp"
#include "BrakeController.hpp"
#include "GearController.hpp"
#include "Transmition.hpp"
#include "SteeringGear.hpp"

class Car {
public:
	Car() : currentSpeed(0) {}
	~Car() {}
	Car& operator=(const Car& rhs) {
		if (this == &rhs)
			return *this;
		engine = rhs.engine;
		brakeController = rhs.brakeController;
		gearController = rhs.gearController;
		transmition = rhs.transmition;
		steeringGear = rhs.steeringGear;
		currentSpeed = rhs.currentSpeed;
		return *this;
	}
	Car(const Car& rhs) {
		*this = rhs;
	}

	void start() {
		engine.start();
		transmition.drive();
	}

	void stop() {
		brakeController.apply_force_on_brakes(50);
		transmition.parking();
		engine.stop();
	}
	/// @brief sets the current speed of the car
	/// @param speed 
	void accelerate(int speed) {
		if (speed < 0) {
			std::cout << "Car: speed can't be negative\n";
			return;
		}
		if (speed > currentSpeed) {
			gearController.shift_gears_up();
		} else {
			gearController.shift_gears_down();
		}
		currentSpeed = speed;
	}
	void turn_wheel(float angle) {
		steeringGear.turn_wheel(angle);
	}

	void straighten_wheels() {
		steeringGear.turn_wheel(0);
	}

private: 
	Engine			engine;
	BrakeController	brakeController;
	GearController	gearController;
	Transmition		transmition;
	SteeringGear	steeringGear;
	int				currentSpeed; // km/h
};