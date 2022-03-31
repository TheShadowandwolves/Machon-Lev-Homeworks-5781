#pragma once
class Vector
{
public:
	Vector() : Vector(0) {};
	Vector(int capacity);
	~Vector();
	int getCapacity();
	int getSize();
	void print();
	void assign(Vector v);
	bool isEqual(Vector& v);
	int& at(int index);
	int strcatcat(Vector& v);
	Vector strnewcat(Vector v);
	void clear();
	void delLast();
	void insert(int val);

private:
	int* _data;
	int _capacity;
	int _size;
};

