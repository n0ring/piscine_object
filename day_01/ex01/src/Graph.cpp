#include "Graph.hpp"

Graph::Graph() : kEmptyCell('.'), kPointCell('X') {
	graphSize = -1;
	graphWidth	= -1;
	maxLenOfFloatPartY = 0;
	maxLenOfFloatPartX = 0;
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
		maxLenOfFloatPartY = rhs.maxLenOfFloatPartY;
		kEmptyCell = rhs.kEmptyCell;
		kPointCell = rhs.kPointCell;
		maxLenOfFloatPartX = rhs.maxLenOfFloatPartX;
	}
	return *this;
}

int Graph::addPoint(Vector2 point) {
	addPoint(point.x, point.y);
	return 0;
}

void printMap(std::map<float, std::set<float> > &points) {
	std::map<float, std::set<float> >::iterator it = points.begin();
	std::map<float, std::set<float> >::iterator ite = points.end();
	std::set<float>::iterator it2;
	std::set<float>::iterator ite2;

	while (it != ite) {
		std::cout << it->first << ": ";
		it2 = it->second.begin();
		ite2 = it->second.end();
		while (it2 != ite2) {
			std::cout << *it2 << ' ';
			it2++;
		}
		std::cout << '\n';
		it++;
	}
}

int Graph::addPoint(float x, float y) {
	if (x < 0 || y < 0)
		return -1;
	if (points.count(y) && points[y].count(x)) {
		std::cout << "Point already exists\n";
		return -1;
	}
	points[y].insert(x);
	xSet.insert(x); // add x of point for x axis line

	graphSize = std::max(static_cast<float>(graphSize), y);
	graphWidth = std::max(graphWidth, static_cast<int>(x) + X_SHIFT);
	maxLenOfFloatPartY = std::max(maxLenOfFloatPartY, findLenOfFloatPart(y)) + 1;
	maxLenOfFloatPartX = std::max(maxLenOfFloatPartX, findLenOfFloatPart(x)) + 1;
	return 0;
}

void Graph::print() {
	std::map<float, std::set<float> >::reverse_iterator it = points.rbegin();
	std::map<float, std::set<float> >::reverse_iterator ite = points.rend();

	// printMap(points);
	// std::cout << maxLenOfFloatPartX  << " " << maxLenOfFloatPartY << '\n';
	while (graphSize >= 0) {
		if (it != ite && it->first >= static_cast<float>(graphSize)) {
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
	std::set<float>::iterator it = xSet.begin();
	std::set<float>::iterator ite = xSet.end();
	int idx  = 0;

	while (idx < graphWidth || it != ite) {

		if (it != ite && *it <= idx) {
			if (currentSet.count(*it))
				printSymbol(kPointCell);
			else
				printSymbol(kEmptyCell);
			if (*it == idx)
				idx++;
			it++;
		} else {
			printSymbol(kEmptyCell);
			idx++;
		}
	}
	std::cout << '\n';
}

void Graph::printLine(float y) {
	printYAxis(y);
	std::set<float>::iterator it = xSet.begin();
	std::set<float>::iterator ite = xSet.end();
	int idx  = 0;

	while (idx < graphWidth || it != ite) {
		if (it != ite && *it <= idx) {
			if (*it == idx)
				idx++;
			it++;
		} else {
			idx++;
		}
		printSymbol(kEmptyCell);
	}
	std::cout << '\n';
}

void Graph::printXAxis() {
	std::cout << ">& ";
	printSymbol(' ');
	std::set<float>::iterator it = xSet.begin();
	std::set<float>::iterator ite = xSet.end();
	float idx = 0;
	
	while (idx < graphWidth || it != ite) {
		if (it != ite && *it <= idx ) {
			printSymbol(*it);
			if (*it == idx)
				idx++;
			it++;
		} else {
			printSymbol(idx);
			idx++;
		}
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
	// std::cout << ">& " << std::left << std::setw(maxLenOfFloatPartY) << y;
	std::cout << ">& ";
	printSymbol(y);

}

void Graph::printSymbol(char symbol) {
	std::cout << std::left << std::setw(maxLenOfFloatPartX) << symbol << ' ';
}

void Graph::printSymbol(float symbol) {
	std::cout << std::left << std::setw(maxLenOfFloatPartX) << symbol << ' ';
}