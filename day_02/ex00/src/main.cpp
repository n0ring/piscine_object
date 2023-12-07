#include "Worker.h"
#include "Shovel.h"
#include "Hammer.h"
#include "Workshop.h"

int main() {
	{
		Shovel s1;
		Shovel s2;
		Hammer h1;

		{
			Worker w1("Bob");
			Worker w2("Alice");
			w1.setTool(&s1);
			w1.setTool(&s2);
			w1.setTool(&h1);
			

			w1.useTools();
			w2.setTool(&s1);
			w1.useTools();
		}
		std::cout << "--end of worker scope--" << std::endl;
	}
	std::cout << "--end of tool scope--" << std::endl;

	std::cout << "\n\n--start test of workshop--" << std::endl;
	{
		Shovel s1;
		Worker w1("Bob");
		Worker w2("Alice");
		Worker w3("John");
		Workshop ws;
		Workshop ws2;
		ws.registerWorker(&w1);
		ws.registerWorker(&w2);
		ws.registerWorker(&w3);
		ws2.registerWorker(&w1);

		w1.setTool(&s1);

		ws.executeWorkDay();

		ws.unregisterWorker(&w1);
		w2.unregisterFromWorkshopByrequest(&ws);
	}


	return 0;
}