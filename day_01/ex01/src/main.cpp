#include "Graph.hpp"


int main() {
	Graph graph;
	// graph.addPoint(1.1, 1);
	graph.addPoint(1, 2);
	graph.addPoint(2, 1);
	graph.addPoint(2, 0);
	graph.print();


	return 0;
}