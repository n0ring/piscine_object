#include "Graph.hpp"


int main() {
	Graph graph;
	// graph.addPoint(1.1, 1);
	// graph.addPoint(1.11, 1);
	// graph.addPoint(1.11, 1.12);
	graph.addPoint(0, 0);
	graph.addPoint(10, 2);
	graph.addPoint(2, 1);
	graph.addPoint(2, 0);
	graph.print();


	return 0;
}