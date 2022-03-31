#include <cmath>
#include "Circle.h"
#include "Point.h"
void Circle::setCenter(int x, int y)
{
	_Center.setX(x);
	_Center.setY(y);
}
void Circle::setRadius(float number) {
	_radius = number;
}
Point Circle::getCenter() {
	return _Center;
}
float Circle::getRadius() {
	return _radius;
}
float Circle::area()
{
	float area = PI * (_radius * _radius);
	return area;
	this->getRadius()
}
float Circle::circum() {
	float circum = 2 * PI * _radius;
	return circum;
}

int Circle::isThePointInTheCircle(Point point) {
	double distance = sqrt(pow(_Center.getX() - point.getX(), 2) + pow(_Center.getY() - point.getY(), 2));
	if (distance < _radius)
	{
		return -1;
	}
	else if (distance == _radius)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}