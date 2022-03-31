#include "Rational.h"
#include <iostream>
using namespace std;
//set the denominator
void Rational::setDenominator(int n) {
	//if input was 0 what is illegal it going to input 1 instead
	if (!n) {
		_denominator = 1;
	}
	else
	{
		_denominator = n;
	}
}
//gets the denminator
int Rational::getDenominater() {
	return _denominator;
}
void Rational::setNumerator(int n) {
	_numerator = n;
}
int Rational::getNumerater() {
	return _numerator;;
}
//print the number
void Rational::printReduced() {
	//needed to first reduce the number in his smallest possible way and then output it
	Rational printNumber = Rational::reduction(_numerator, _denominator);
	cout << printNumber._numerator << "/" << printNumber._denominator << " ";
	//cout <<_numerator << "/" << _denominator << " ";
}
void Rational::print() {
	cout <<_numerator << "/" << _denominator << " ";
}
Rational Rational::reduction(int _numerator, int _denominator) {
	int max;
	//max what is the size is going to be the greatest number one of them
	
	if (_numerator > _denominator)
	{
		max = _numerator;
	}
	else
	{
		max = _denominator;
	}
	
	//one loop is not enough since after one loop it could still be not reduced number, this loop goes 2 times to check if it is possible another reduction
	for (int j = 0; j < 2; j++)
	{
		for (int i = 1; i <= max / 2; i++)
		{
				//checks if the number can be reduced and which one
			if (_numerator % i == 0 && _denominator % i == 0)
			{
					_numerator /= i;
					_denominator /= i;
			}
		}
	}
	if (_numerator == _denominator) {
		_numerator = 1;
		_denominator = 1;
	}
	//doing a new type, to set it together and return one parameter that is needed
	Rational Result;
	Result._numerator = _numerator;
	Result._denominator = _denominator;
	return Result;
}
//adds the two given numbers
Rational Rational::add(Rational number) {
	Rational sum;
	//math
	sum._numerator = (_numerator * number._denominator) + (number._numerator * _denominator);
	sum._denominator = (_denominator * number._denominator);
	return sum;
}
bool Rational::equal(Rational number) {
	// first needs to reduce it into the smallest possible reduction, than compare it
	Rational R1 = Rational::reduction(_numerator, _denominator);
	Rational R2 = Rational::reduction(number._numerator, number._denominator);
	if (R1._numerator == R2._numerator && R1._denominator == R2._denominator) {
	
		return true;
	}
	return false;
}
