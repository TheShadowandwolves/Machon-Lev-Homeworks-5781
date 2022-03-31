#include "DataBank.h"
#include <cstring>
#include <iostream>
using namespace std;

void DataBank::setssn(int number)
{
	_ssn = number;
}

void DataBank::setname(char name[], int size)
{
	strcpy(_name, name);
	
}

void DataBank::sethourlyWage(float hourlyWage)
{
	if (hourlyWage >=0)
	{
		_hourlyWage = hourlyWage;
	}
	else
	{
		cout << "ERROR" << endl;
		_hourlyWage = 0;
	}
}

void DataBank::setnumberOfHours(int number)
{
	if (number <0)
	{
		_numberOfHours = 0;
		cout << "ERROR" << endl;
	}
	else
	{
		_numberOfHours = number;
	}

}

void DataBank::settotalAmount(float amount)
{
	if (amount < 0)
	{
		cout << "ERROR " << endl;
		amount = 0;
	}
	_totalAmount = amount;
}

int DataBank::getssn()
{
	return _ssn;
}

char* DataBank::getname()
{
	return _name;
}

float DataBank::gethourlyWage()
{
	return _hourlyWage;
}
int DataBank::getnumberOfHours()
{
	return _numberOfHours;
}
float DataBank::gettotalAmount()
{
	return _totalAmount;
}
float DataBank::formular()
{
	// at first percentage is going to be 0
	float percentage = 0.0f;
	//we need a special float since _totalAmount should not be changed
	float totalSalary = _totalAmount;
	//maxLimits is an Array that contains the different Salary option
	int maxLimits[5] = { 5000,4000,2000,1000,0 };
	//the same we do for the % of each option
	float percentArr[5] = { 0.4f,0.3f,0.2f,0.15f,0.1f };
	for (int i = 0; i < 5; i++)
	{
		//separate function to calculate the equation, since without taking the inputs, its the same
		percentage += CalcPersentage(maxLimits[i], percentArr[i], totalSalary);
	}
	
	return _hourlyWage * _numberOfHours + percentage;

}

// my clever function
float DataBank::CalcPersentage(int maxValue, float percent, float& totalSalary)
{
	float percentage = 0.0f;
	if (totalSalary > maxValue)
	{
		percentage = (totalSalary - maxValue) * percent;
		totalSalary = maxValue;
	}
	return percentage;

}

