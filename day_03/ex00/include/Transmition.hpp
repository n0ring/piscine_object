#pragma once 

#include <iostream>

enum TRANSMITION_STATE {
	REVERSE = 0,
	DRIVE = 1,
	PARKING = 2
};

class Transmition {

public:
	Transmition() {
		currentState = PARKING;
	}
	
	~Transmition() {}

	Transmition& operator=(const Transmition& rhs) {
		if (this == &rhs)
			return *this;
		currentState = rhs.currentState;
		return *this;
	}

	Transmition(const Transmition& rhs) {
		*this = rhs;
	}

	void reverse() {
		if (currentState != REVERSE) {
			currentState = REVERSE;
			std::cout << "Transmition: reverse\n";
		}
	}

	void drive() {
		if (currentState != DRIVE) {
			currentState = DRIVE;
			std::cout << "Transmition: drive\n";
		}
	}

	void parking() {
		if (currentState != PARKING) {
			currentState = PARKING;
			std::cout << "Transmition: parking\n";
		}
	}

private: 
	TRANSMITION_STATE currentState; 

};