// HW1Q3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
/* Leonard Blam
* 900086
* Workshop C++
* Homework 1 Question 3
*finds out if the points are in a one of three given circles or not
*/


#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;

//calculates how many times the point is in a circle
int sumOfNumbersThatPointExistInCircle(Circle p, int pointsize, Point* points) {
	int sum = 0;
	for (int i = 0; i < pointsize; i++)
	{
		if (p.isThePointInTheCircle(points[i]) <= 0) {
			sum++;
		}

	}
	return sum;
}

int main()
{
	Circle p1, p2, p3;
	int c1x, c2x, c3x, c1y, c2y, c3y;
	float r1, r2, r3;
	float perimeter1, perimeter2, perimeter3;
	float area1, area2, area3;
	const int MAXSIZE = 1000;
	Point points[MAXSIZE];

	cout << "enter the center point and radius of 3 circles: " << endl;
	cin >> c1x;
	cin >> c1y;
	cin >> r1;
	p1.setRadius(r1);
	p1.setCenter(c1x, c1y);
	cin >> c2x;
	cin >> c2y;
	cin >> r2;
	p2.setRadius(r2);
	p2.setCenter(c2x, c2y);
	cin >> c3x;
	cin >> c3y;
	cin >> r3;
	p3.setRadius(r3);
	p3.setCenter(c3x, c3y);

	perimeter1 = p1.circum();
	perimeter2 = p2.circum();
	perimeter3 = p3.circum();
	area1 = p1.area();
	area2 = p2.area();
	area3 = p3.area();
	cout << "perimeter: A: " << perimeter1 << " " << "B: " << perimeter2 << " " << "C: " << perimeter3 << endl;
	cout << "area: A: " << area1 << " " << "B: " << area2 << " " << "C: " << area3 << endl;
	cout << "enter points until (0,0): " << endl;
	int size = 0;
	int x, y;
	do
	{
		cin >> x;
		cin >> y;
		points[size].setPoint(x, y);
		size++;
	} while (x || y);

	//we only need to check the array until there is a number, taken that both arrays have the same input length we need to check only ones
	//for each circle we look how many times its inside or on circle
	cout << "num of points in circle: ";
	cout << "A: " << sumOfNumbersThatPointExistInCircle(p1, size - 1, points);
	cout << " B: " << sumOfNumbersThatPointExistInCircle(p2, size - 1, points);
	cout << " C: " << sumOfNumbersThatPointExistInCircle(p3, size - 1, points);
}

/*enter the center point and radius of 3 circles:
0
0
3
1
1
2
5
5
2
perimeter: A: 18.84 B: 12.56 C: 12.56
area: A: 28.26 B: 12.56 C: 12.56
enter points until (0,0):
0
1
1
0
0
4
0
0
num of points in circle: A: 2 B: 2 C: 0
E:\Dokumente\Workshop c++\Homeworks\HW1Q3\Debug\HW1Q3.exe (Prozess "45332") wurde mit Code "0" beendet.
Um die Konsole beim Beenden des Debuggens automatisch zu schließen, aktivieren Sie "Extras" > "Optionen" > "Debuggen" > "Konsole beim Beenden des Debuggings automatisch schließen".
Drücken Sie eine beliebige Taste, um dieses Fenster zu schließen.
*/