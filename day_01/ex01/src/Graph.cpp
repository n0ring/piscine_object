#include "Graph.hpp"

Graph::Graph() : kEmptyCell('.'), kPointCell('X') {
	graphSize = -1;
	graphWidth	= -1;
	maxLenOfFloatPart = 0;
}

Graph::~Graph() {
}

Graph::Graph(Graph const & src) {
	*this = src;
}

Graph& Graph::operator=(Graph const & rhs) {
	if (this != &rhs)
	{
		points = rhs.points;
		graphSize = rhs.graphSize;
		graphWidth = rhs.graphWidth;
		maxLenOfFloatPart = rhs.maxLenOfFloatPart;
		kEmptyCell = rhs.kEmptyCell;
		kPointCell = rhs.kPointCell;
	}
	return *this;
}

int Graph::addPoint(Vector2 point) {
	addPoint(point.x, point.y);
	return 0;
}


int Graph::addPoint(float x, float y) {
	if (x < 0 || y < 0)
		return -1;
	if (points.count(y) && points[y].count(x)) {
		std::cout << "Point already exists\n";
		return -1;
	}
	points[y].insert(x);
	graphSize = std::max(graphSize, y);
	graphWidth = std::max(graphWidth, static_cast<int>(x) + X_SHIFT);
	maxLenOfFloatPart = std::max(maxLenOfFloatPart, findLenOfFloatPart(y)) + 1;
	return 0;
}

/*
>& 5 . . . . . .
>& 4 . . X . . .
>& 3 . . . . . .
>& 2 . . X . X .
>& 1 . . . . . .
>& 0 X . . . . .
>& 0 1 2 3 4 5 6
*/

void Graph::print() {
	std::map<float, std::set<float> >::reverse_iterator it = points.rbegin();
	std::map<float, std::set<float> >::reverse_iterator ite = points.rend();
	while (graphSize >= 0) {
		if (it != ite && it->first >= graphSize) { // need set
			printLine(it->first, it->second);
			if (it->first == graphSize)
				graphSize--;
			it++;
		} else {
			printLine(graphSize--);
		}
	}
	printXAxis();
}

int Graph::setSize(int size) {
	if (size < 0)
		return -1;
	graphSize = size;
	return 0;
}

void Graph::printLine(float y, std::set<float> &currentSet) {
	printYAxis(y);
	for (int i = 0; i < graphWidth; i++) {
		if (currentSet.count(i))
			std::cout << kPointCell << ' ';
		else
			std::cout << kEmptyCell << ' ';
	}
	std::cout << '\n';
}

void Graph::printLine(float y) {
	printYAxis(y);	
	for (int i = 0; i < graphWidth; i++) {
		std::cout << kEmptyCell << ' ';
	}
	std::cout << '\n';
}

void Graph::printXAxis() {
	printYAxis(0); // TODO
	for (int i = 0; i < graphWidth; i++) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

int Graph::findLenOfFloatPart(float num) {
	int len = 0;
	while (num - static_cast<int>(num) > 0) {
		num *= 10;
		len++;
	}
	return len;
}


// align to right 
void Graph::printYAxis(float y) {
	std::cout << ">& " << std::left << std::setw(maxLenOfFloatPart) << y << "  ";

}