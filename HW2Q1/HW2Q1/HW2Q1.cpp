// HW2Q1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
/* Leonard Blam
* 900086
* Workshop C++
* Homework 2 Question 1
* 
*/

#include <iostream>
#include "Plane.h"
#include "Polygon.h"
using namespace std;

int main()
{
	int side1, side2;
	char bracket;
	int numA, numB;
	cout << "enter number of sides: " << endl;
	cin >> side1;
	Polygon P1(side1);
	Point po1, po2;
	cout << "enter the point values: " << endl;
	for (int i = 0; i < side1; i++)
	{
		cin >> bracket >> numA >> bracket >> numB >> bracket;
		po1.setPoint(numA, numB);
		P1.addPoint(i, po1);
	}
	cout << "enter number of sides: " << endl;
	cin >> side2;
	Polygon* P2 = new Polygon(side2);
	cout << "enter the point values: " << endl;
	for (int i = 0; i < side2; i++)
	{
		cin >> bracket >> numA >> bracket >> numB >> bracket;
		po2.setPoint(numA, numB);
		P2->addPoint(i, po2);
	}
	Polygon P3(*P2);
	delete P2;
	if (P1.isEqual(P3)) {
		cout << "equal. perimeter: " << P1.computePerimeter() << endl;
	}
	else
	{
		cout << "perimeter: " << P1.computePerimeter() << endl;
		cout << "perimeter: " << P3.computePerimeter() << endl;
	}
}

/*enter number of sides:
4
in constructor
enter the point values:
(10,10)
(13,10)
(10,14)
(11,13)
enter number of sides:
4
in constructor
enter the point values:
(13,10)
(11,13)
(10,10)
(10,14)
in copy constructor
in destructor
equal. perimeter: 12.5765
in destructor
in destructor

E:\Dokumente\Workshop c++\Homeworks\HW2Q1\x64\Debug\HW2Q1.exe (Prozess "26948") wurde mit Code "0" beendet.
Um die Konsole beim Beenden des Debuggens automatisch zu schließen, aktivieren Sie "Extras" > "Optionen" > "Debuggen" > "Konsole beim Beenden des Debuggings automatisch schließen".
Drücken Sie eine beliebige Taste, um dieses Fenster zu schließen.
*/
