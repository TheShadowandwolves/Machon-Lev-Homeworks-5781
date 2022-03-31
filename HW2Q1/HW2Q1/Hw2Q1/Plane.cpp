#include "Plane.h"
#include <cmath>

void Point::setX(int x) {
	_x = x;
}
void Point::setY(int y) {
	_y = y;
}
int Point::getX() {
	return _x;
}
int Point::getY() {
	return _y;
}
void Point::setPoint(int x, int y) {
	_x = x;
	_y = y;
}

Point::Point() :Point(0, 0) {
}

Point::Point(int x, int y) : _x(x), _y(y) {
}

bool Point::isEqual(const Point& p) {
	return (_x == p._x && _y == p._y);
}

double Point::distance(Point& point) {
	return sqrt(pow(_x - point.getX(), 2) + pow(_y - point.getY(), 2));
}