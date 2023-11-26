#pragma once 

#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
#include <set>
#include <iomanip>
#include "Vector2.hpp"

#define X_SHIFT 1

class Graph
{
public: 
	Graph();
	~Graph();
	Graph(Graph const & src);
	Graph & operator=(Graph const & rhs);

	void print();
	int addPoint(Vector2 point);
	int addPoint(float x, float y);
	int setSize(int size);

private: 
	std::map<float, std::set<float> > points; // x, y
	float graphSize;
	int graphWidth;
	int maxLenOfFloatPart;
	char kEmptyCell;
	char kPointCell;

	void printLine(float y, std::set<float> &currentSet);
	void printLine(float y);
	void printXAxis();
	int findLenOfFloatPart(float num);
	void printYAxis(float y);
};