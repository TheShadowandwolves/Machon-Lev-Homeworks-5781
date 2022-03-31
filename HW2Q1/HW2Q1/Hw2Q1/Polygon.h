#pragma once
#include "Plane.h"
class Polygon
{
public:
	Polygon();
	Polygon(int num);
	Point getVertices(int index);
	Polygon(Polygon& pol);
	~Polygon();
	void addPoint(int index, Point& vertex);
	double computePerimeter();
	bool isEqual(Polygon& vertices);
private:
	Point* _vertices;
	int _numOfVertices;
};

