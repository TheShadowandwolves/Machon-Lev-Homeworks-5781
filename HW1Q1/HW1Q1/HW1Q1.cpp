// HW1Q1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
/* Leonard Blam
* 900086
* Workshop C++
* Homework 1 Question 1
* adds two given rational number together and prints it in their smallest possible reduction
* 
*/
#include"Rational.h"
#include <iostream>
using namespace std;

int main()
{
	int numerator, denominator;
	char tav;
	cout << "enter two rational numbers:" << endl;
	cin >> numerator >> tav >> denominator;
	Rational r1;
	r1.setNumerator(numerator);
	r1.setDenominator(denominator);
	cin >> numerator >> tav >> denominator;
	Rational r2;
	r2.setNumerator(numerator);
	r2.setDenominator(denominator);
	Rational ans = r1.add(r2);
	r1.print();
	cout << "+ ";
	r2.print();
	cout << "= ";
	ans.printReduced();
	cout << endl;
	if (r1.equal(r2))
		cout << "The two numbers are equal" << endl;
	else
	{
		cout << "The two numbers are different" << endl;
		r1.print();
		r2.print();
		cout << endl;
	}
	return 0;
}

/*enter two rational numbers:
240
/
480
12
/
24
240/480 + 12/24 = 1/1
The two numbers are equal

E:\Dokumente\Workshop c++\Homeworks\HW1Q1\Debug\HW1Q1.exe (Prozess "35692") wurde mit Code "0" beendet.
Drücken Sie eine beliebige Taste, um dieses Fenster zu schließen.



*/