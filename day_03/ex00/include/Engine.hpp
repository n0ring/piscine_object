#pragma once 

#include <iostream>

enum ENGINE_STATE {
	ENGINE_OFF = 0,
	ENGINE_ON = 1
};

class Engine {
public: 
	Engine() {
		engineState = ENGINE_OFF;
	}
	~Engine() {}
	Engine& operator=(const Engine& rhs) {
		if (this == &rhs)
			return *this;
		engineState = rhs.engineState;
		return *this;
	}
	Engine(const Engine& rhs) {
		*this = rhs;
	}

	void start() {
		if (engineState == ENGINE_OFF) {
			engineState = ENGINE_ON;
			std::cout << "Engine: starts\n";
		}
	}

	void stop() {
		if (engineState == ENGINE_ON) {
			engineState = ENGINE_OFF;
			std::cout << "Engine: off\n";
		}
	}

private: 
	ENGINE_STATE engineState;
};