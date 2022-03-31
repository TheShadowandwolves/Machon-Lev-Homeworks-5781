#pragma once
class DataBank
{
public:
	void setssn(int number);
	void setname(char name[], int size);
	void sethourlyWage(float hourlyWage);
	void setnumberOfHours(int number);
	void settotalAmount(float amount);
	int getssn();
	char* getname();
	float gethourlyWage();
	int getnumberOfHours();
	float gettotalAmount();
	float formular();

private:
	int _ssn;
	char _name[21];
	float _hourlyWage;
	int _numberOfHours;
	float _totalAmount;
	// my clever function
	float CalcPersentage(int maxValue, float percent, float& totalSalary);
};
