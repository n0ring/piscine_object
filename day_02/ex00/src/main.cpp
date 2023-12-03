#include "Worker.h"


int main() {
	{
		Shovel s1;
		{
			Worker w1("Bob");
			Worker w2("Alice");

			w1.setShovel(&s1);
			w2.setShovel(&s1);
		}
		std::cout << "--end of worker scope--" << std::endl;
	}
	std::cout << "--end of shovel scope--" << std::endl;
	return 0;
}