#pragma once

class Point
{
public:
	Point();
	Point(int x, int y);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void setPoint(int x, int y);
	double distance(Point& point);
	bool isEqual(const Point& p);
private:
	int _x;
	int _y;
};