#pragma once
class Rational
{
public:
	void setDenominator(int n);
	int getDenominater();
	void setNumerator(int n);
	int getNumerater();
	void printReduced();
	void print();
	Rational add(Rational number);
	bool equal(Rational number);
private:
	int _numerator;
	int _denominator;
	Rational reduction(int _nominator, int _denominator);

};

