#include "Rational.h"
#include <iostream>
using namespace std;

Rational::Rational(int numinater, int denominater)
{
	num = numinater;
	if (!denominater)
	{
		cout << "ERROR" << endl;
		denom = 1;
	}
	else
	{
		denom = denominater;
	}
}

Rational::Rational()
{
	num = 0;
	denom = 0;
}

Rational Rational::operator=(const Rational& r)
{
	denom = r.denom;
	num = r.num;
	return *this;
}

Rational Rational::operator+=(const Rational& r)
{
	denom += r.denom;
	num += r.num;
	return *this;
}

Rational Rational::operator-=(const Rational& r)
{
	denom -= r.denom;
	num -= r.num;
	return *this;
}

Rational Rational::operator+(const Rational& r)
{
	Rational sum;
	sum.num = (num * r.denom)+ (r.num*denom);
	sum.denom = denom * r.denom;
	return sum;
}

Rational& Rational::operator++()
{
	num += denom;
	return *this;
}

Rational Rational::operator++(int) {
	Rational old = *this; // copy old value
	operator++();  // prefix increment
	return old;    // return old value
}

Rational Rational::operator-(const Rational& r)
{
	Rational sum;
	sum.num = (num*r.denom) - (r.num*denom);
	sum.denom = (denom*r.denom);
	Rational reducedSum = reduction(sum.num, sum.denom);
	return reducedSum;
}

Rational& Rational::operator--()
{
	num -= denom;
	return *this;
}

Rational Rational::operator--(int) {
	Rational old = *this; // copy old value
	operator--();  // prefix increment
	return old;    // return old value
}


Rational Rational::operator*(const Rational& r)
{
	Rational sum;
	sum.num = num * r.num;
	sum.denom = denom * r.denom;
	return sum;
}

Rational Rational::operator/(const Rational& r)
{
	Rational sum;
	sum.num = num * r.denom;
	sum.denom = denom * r.num;
	return sum;
}

bool Rational::operator==(const Rational& r)
{
	if (num == r.num && denom == r.denom)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Rational::operator!=(const Rational& r)
{
	if (num == r.num && denom == r.denom)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Rational::operator<=(const Rational& r)
{
	Rational first, last;
	first.num = num * r.denom;
	first.denom = denom * r.denom;
	last.num = r.num * denom;
	last.denom = denom * r.denom;
	if (first.num <= last.num)
	{
		return true;
	}
	return false;
}

bool Rational::operator>=(const Rational& r)
{
	Rational first, last;
	first.num = num * r.denom;
	first.denom = denom * r.denom;
	last.num = r.num * denom;
	last.denom = denom * r.denom;
	if (first.num >= last.num)
	{
		return true;
	}
	return false;
}

bool Rational::operator<(const Rational& r)
{
	Rational first, last;
	first.num = num * r.denom;
	first.denom = denom * r.denom;
	last.num = r.num * denom;
	last.denom = denom * r.denom;
	if (first.num < last.num)
	{
		return true;
	}
	return false;
}

bool Rational::operator>(const Rational& r)
{
	Rational first, last;
	first.num = num * r.denom;
	first.denom = denom * r.denom;
	last.num = r.num * denom;
	last.denom = denom * r.denom;
	if (first.num > last.num)
	{
		return true;
	}
	return false;
}

bool Rational::operator!() const
{
	if (!num || !denom)
	{
		return true;
	}
	return false;
}

void Rational::print()
{
	Rational shortRationalNumber = reduction(num, denom);
	if (shortRationalNumber.num)
	{
		if (shortRationalNumber.denom == 1) {
			cout << shortRationalNumber.num;
		}
		else
		{
			cout << shortRationalNumber.num << "/" << shortRationalNumber.denom;
		}
	}
	else
	{
		cout << 0;
	}
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
	Result.num = _numerator;
	Result.denom = _denominator;
	return Result;
}
