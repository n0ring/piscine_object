#include "Car.hpp"


int main() {
	Car car;

	car.start();

	car.accelerate(10);
	car.straighten_wheels();
	car.accelerate(20);
	car.turn_wheel(90);
	car.accelerate(5);
	car.stop();
	return 0;
}