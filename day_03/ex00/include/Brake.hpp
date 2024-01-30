#pragma once 

#include <iostream>

class Brake {	
	public:
		Brake() {
			currentForce = 0;
		}
		~Brake() {}
		Brake& operator=(const Brake& rhs) {
			if (this == &rhs)
				return *this;
			currentForce = rhs.currentForce;
			return *this;
		}
		Brake(const Brake& rhs) {
			*this = rhs;
		}

		void change_current_force(float percent_force) {
			std::cout << "Brake: change current force to: " << percent_force << std::endl;
			currentForce = percent_force;
		}

	private: 
		int currentForce;
};