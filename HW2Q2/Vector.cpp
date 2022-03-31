#include "Vector.h"
#include <iostream>
using namespace std;
Vector::Vector(int capacity)
{
	if (capacity)
	{
		_data = new int[capacity];
	}
	else
	{
		_data = new int[2];
	}
	_capacity = capacity;
	_size = 0;
}

Vector::~Vector()
{
	Vector::clear();
}

int Vector::getCapacity()
{
	return _capacity;
}

int Vector::getSize()
{
	return _size;
}

void Vector::print()
{
	cout << "capacity: " << _capacity << " size: " << _size << " val:";
	for (int i = 0; i < _size; i++)
	{
		cout << " " << _data[i];
	}
}

void Vector::assign(Vector v)
{
	for (int i = 0; i < _size; i++)
	{
		_data[i] = v._data[i];
	}
	
	_capacity = v._capacity;
	_size = v._size+1;
}

bool Vector::isEqual(Vector& v)
{
	bool compare = false;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < v._size; j++) {
			if (_data[i] == v._data[j]) {
				compare = true;
			}
			else
			{
				return false;
			}
		}
	}
	return compare;

}

int& Vector::at(int index)
{
	if (_data[index])
	{
		return _data[index];
	}
	else
	{
		cout << "ERROR" << endl;
		int error = -1;
		return error;
	}
}

int Vector::strcatcat(Vector& v)
{
	int sum = 0;
	if (_size == v._size)
	{
		for (int i = 0; i < _size; i++)
		{
			sum += _data[i] * v._data[i];
		}
		return sum;
	}
	else
	{
		cout << "ERROR" << endl;
		return -1;
	}
}

Vector Vector::strnewcat(Vector v)
{
	int newVectorSize = _size + v._size;
	int newVectorCapazity =  _capacity + v._capacity;
	Vector newVector(newVectorCapazity);
	int lastcurrentNum = 0;
	for (int i =0; i < _size; i++)
	{
		newVector._data[i] = _data[i];
	}
	newVector._size = newVectorSize;
	newVector._capacity = newVectorCapazity;
	int i = _size + 1;;
	int j = 0;
	for ( i; i < newVectorSize; i++)
	{
		newVector._data[i] = v._data[j];
		j++;
	}
		
	
	return newVector;
}

void Vector::clear()
{
	delete _data;
	_capacity = 0;
	_size = 0;
}

void Vector::delLast()
{
	if (!_data) {
		cout << "ERROR" << endl;
	}
	else
	{
		_data[_size] = 0;
	}
}

void Vector::insert(int val)
{
	if (_data[_capacity])
	{
		Vector newVector(_capacity * 2);
		assign(newVector);
		for (int i = 0; i < newVector._size; i++)
		{
			if (!newVector._data[i])
			{
				newVector._data[i] = val;
				Vector::~Vector();
				break;
			}
		}
	}
	else
	{
		for (int j = 0; j < _size; j++)
		{
			if (!_data[j])
			{
				_data[j] = val;
				break;
			}
		}
	}

}
