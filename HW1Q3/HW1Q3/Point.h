#pragma once
class Point
{
public:
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void setPoint(int x, int y);
private:
	int _x;
	int _y;
};

