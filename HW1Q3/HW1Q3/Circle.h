#include "Point.h"
const float PI = 3.14f;

class Circle
{
public:
	void setCenter(int x, int y);
	void setRadius(float number);
	Point getCenter();
	float getRadius();
	float area();
	float circum();
	int isThePointInTheCircle(Point point);
private:
	Point _Center;
	float _radius;
};


