// HW1Q2.cpp :
/* Leonard Blam
* 900086
* Workshop C++
* Homework 1 Question 2
*input a database of employees and find the highest and lowest person with salary
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "DataBank.h"
using namespace std;

//searches for the highest salary
DataBank highestSalaryPerson(DataBank* Person, int size) {
	int highestPersonIndex = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (Person[highestPersonIndex].formular() < Person[i + 1].formular()) {
			highestPersonIndex = i + 1;
		}
	}
	return Person[highestPersonIndex];
}
//searching for the person with smallest salary
DataBank smallestSalaryPerson(DataBank* Person, int size) {
	int smallestPersonIndex = 0;
	for (int i = 0; i < size - 1; i++)
	{
		//smallestPersonIndex is going to be the smallest index as long as i +1 is not smaller 
		if (Person[smallestPersonIndex].gettotalAmount() > Person[i + 1].gettotalAmount()) {
			smallestPersonIndex = i + 1;
		}
	}
	return Person[smallestPersonIndex];
}

int main()
{
	int ssn = 1;
	const int nameLength = 21;
	char name[nameLength];
	const int MAXSIZE = 1000;
	int personsNumber = 0;
	float hourlyWage, amount;
	int hours;



	int i = 0;
	DataBank* Person = new DataBank[MAXSIZE];
	cout << "enter details, to end enter 0: " << endl;
	while (ssn)
	{
		cin >> ssn;
		if (ssn) {
			Person[i].setssn(ssn);
			int j = 0;
			//cout << "name:";
			cin >> setw(nameLength) >> name;
			//cin.getline(name, 20);
			Person[i].setname(name, nameLength);
			//cout << "hour wage:";
			cin >> hourlyWage;
			Person[i].sethourlyWage(hourlyWage);
			//cout << "hours";
			cin >> hours;
			Person[i].setnumberOfHours(hours);
			//cout << "amount: ";
			cin >> amount;
			Person[i].settotalAmount(amount);
			i++;
			personsNumber++;
		}
	}

	DataBank SmallestPerson = smallestSalaryPerson(Person, personsNumber);
	DataBank HighestPerson = highestSalaryPerson(Person, personsNumber);
	
	cout << "minimum collected: " <<  SmallestPerson.getssn() << " " << SmallestPerson.getname() << " "<< SmallestPerson.gettotalAmount() << endl;
	cout << "highest salary: " << HighestPerson.getssn() << " " << HighestPerson.getname() << " " << HighestPerson.formular() << endl;

	delete Person;
}
/*enter details, to end enter 0:
12345
Leib
55
270
4000
65363
Alex
13
55
987.50
53345
Sven
50
100
10000
0
minimum sum: 987.5 Alex 65363
highest salary: 15500 Leib 12345

E:\Dokumente\Workshop c++\Homeworks\HW1Q2\Debug\HW1Q2.exe (Prozess "19548") wurde mit Code "0" beendet.
Drücken Sie eine beliebige Taste, um dieses Fenster zu schließen.


*/