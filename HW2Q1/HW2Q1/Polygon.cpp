#include "Polygon.h"
#include "Plane.h"
#include <iostream>
using namespace std;

Polygon::Polygon() :Polygon(0)
{
	cout << "in constructor" << endl;
}

Polygon::Polygon(int num) : _numOfVertices(num)
{
	cout << "in constructor" << endl;
	if (num) {
		_vertices = new Point[num];
	}
	else {
		_vertices = nullptr;
	}
}

Polygon::Polygon(Polygon& pol) :_numOfVertices(pol._numOfVertices) {
	cout << "in copy constructor" << endl;
	if (_numOfVertices) {
		_vertices = new Point[_numOfVertices];
		for (int i = 0; i < _numOfVertices; i++)
		{
			_vertices[i].setPoint(pol._vertices[i].getX(), pol._vertices[i].getY());
		}
	}
	else {
		_vertices = nullptr;
	}
}

Point Polygon::getVertices(int index)
{
	return _vertices[index];
}

Polygon::~Polygon()
{
	delete _vertices;
	cout << "in destructor" << endl;
}

void Polygon::addPoint(int index, Point& vertex)
{
	_vertices[index].setPoint(vertex.getX(), vertex.getY());
}

double Polygon::computePerimeter()
{
	double perimeter = 0;
	for (int i = 0; i < _numOfVertices - 1; i++) {
		perimeter += _vertices[i].distance(_vertices[i + 1]);
	}
	perimeter += _vertices[_numOfVertices - 1].distance(_vertices[0]);
	return perimeter;
}

bool Polygon::isEqual(Polygon& pol)
{
	bool found;
	if (_numOfVertices == pol._numOfVertices) {
		for (int i = 0; i < _numOfVertices; i++)
		{
			Point curPoint = _vertices[i];
			found = false;
			for (int j = 0; j < _numOfVertices; j++)
			{
				if (curPoint.isEqual(pol._vertices[j]))
				{
					found = true;
					break;
				}
			}
			if (!found) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}