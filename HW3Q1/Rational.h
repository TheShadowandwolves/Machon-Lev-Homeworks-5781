#pragma once
class Rational
{
public:
	Rational(int numinator, int denominator);
	Rational();
	// assignment operators (including +=, etc)
		Rational operator=(const Rational& r);
		Rational operator+=(const Rational& r);
		Rational operator-=(const Rational& r);


	// arithmetic operators (add, subtract, multiply, divide, incr, decr)
		Rational operator+(const Rational& r);
		Rational& operator++(); // pre auto-increment
		Rational operator++(int);
		Rational operator-(const Rational& r);
		Rational& operator--();
		Rational operator--(int);
		Rational operator*(const Rational& r);
		Rational operator/(const Rational& r);
	//Rational operator(int)    // post auto-increment
	// comparison operators (==, !=, <, <=, >, >=)
		bool operator==(const Rational& r); 
		bool operator!=(const Rational& r);
		
		bool operator<=(const Rational& r);
		bool operator>=(const Rational& r);

		bool operator<(const Rational& r);
		bool operator>(const Rational& r);
	// logical operators
		bool operator!() const;
		void print();
		Rational reduction(int _numerator, int _denominator);
private:
	int num;
	int denom;

};

