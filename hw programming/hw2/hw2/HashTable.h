#pragma once
#include <iostream>
#include <string>
using namespace std;



template <class T, class K>
class HashTable
{
protected:

	enum state { empty, full, deleted };
	template <class T, class K>
	class Item
	{
	public:
		T data;
		K key;
		state flag;
		Item() {}
		Item(T d, K k, state f) { data = d; key = k; flag = f; }
	};


	int size;
	Item<T, K>* arr;
	bool prime(int n);
	int hash(K key, int i);
	virtual int h1(K key) = 0;
	virtual int h2(K key) = 0;
public:
	HashTable(int m = 10);
	~HashTable();
	void add(K& key, T& dat);
	int remove(K key);
	int search(K key);
	T* entryData(K i)
	{
		int ind = search(i);
		if (ind == -1)
			return NULL;
		else
			return &(arr[ind].data);
	}
	void print();

	int findSpecialPrime(int);
};

template<class T, class K>
inline bool HashTable<T, K>::prime(int n)
{
	bool isPrime = true;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) {
			isPrime = false;
			break;
		}

	}
	return isPrime;
}

template<class T, class K>
inline int HashTable<T, K>::hash(K key, int i)
{
    return 0;
}

template<class T, class K>
inline HashTable<T, K>::HashTable(int m)
{
    int prime = findSpecialPrime(m);
}

template<class T, class K>
inline HashTable<T, K>::~HashTable()
{
}

template<class T, class K>
inline void HashTable<T, K>::add(K& key, T& dat)
{
}

template<class T, class K>
inline int HashTable<T, K>::remove(K key)
{
    return 0;
}

template<class T, class K>
inline int HashTable<T, K>::search(K key)
{
    return 0;
}

template<class T, class K>
inline void HashTable<T, K>::print()
{
}


template<class T, class K>
inline int HashTable<T, K>::findSpecialPrime(int N)
{
	for (int i = N; ; i++)
	{
		if (prime(i)) {
			return i;
		}
	}

}
