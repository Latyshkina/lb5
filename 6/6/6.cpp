// 6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Set
{
	int *d = new int [0], size = 0;

public:
	Set() {
		cout << "Set constructor" << endl;
		cout << "Size=";
		cin >> size;
		d = new  int[size];
		for (int i = 0; i < size; i++)
		{
			d[i] = rand() % 10;
		}
	};
	int operator [](int i) { //доступ к элементу 
		return d[i];
	}
	Set(int m)
	{
		delete[]d;
		d = new int[m];
		size = m;
	}
	operator int();
	friend Set operator *(const Set &a, const Set&b){
		int k = 0; 
		for (int i = 0; i < a.size; i++)
		{
			bool y = 1;
			for (int n = 0; n < i; n++)
			{
				if (a.d[i] == a.d[n]) // берем у а массив д
					y = 0;
			}
			if (y == 1)
			{

				for (int n = 0; n < b.size; n++)
				{
					 y = 1;
					for (int p = 0; p < n; p++)
					{
						if (b.d[n] == b.d[p]) // берем у а массив д
							y = 0;
					}
					if (y == 1)
					{
						if (a.d[i] == b.d[n])
						{
							k++;
						}
					}
				}
			}
				
		}
		Set c(k); 
		k = 0;
		for (int i = 0; i < a.size; i++)
		{
			bool y = 1;
			for (int n = 0; n < i; n++)
			{
				if (a.d[i] == a.d[n]) // берем у а массив д
					y = 0;
			}
			if (y == 1)
			{
				for (int n = 0; n < b.size; n++)
				{
					y = 1;
					for (int p = 0; p < n; p++)
					{
						if (b.d[n] == b.d[p]) // берем у а массив д
							y = 0;
					}
					if (y == 1)
					{
						if (a.d[i] == b.d[n])
						{
							c.d[k] = a.d[i];
							k++;
						}
					}
				}
			}
		}
		return c;
	};
	Set(const Set &t){
		delete[]d;
		size = t.size;
		d = new int[size];
		for (int i = 0; i<size; i++)
		{
			d[i] = t.d[i];
		}

	};
	void print();
	~Set();
	friend bool operator >(const Set &a, const Set&b){
		for (int i = 0; i < b.size; i++)
		{
			bool y = 0;
			for (int n = 0; n < a.size; n++)
			{
				if (b.d[i] == a.d[n])
				{
					y = 1;
					break;
				}
			
			}
			if (y == 0)
			{
				return 0;
			}
		}
		return 1;
	}
	friend bool operator <(const Set &a, const Set&b){
		return (b>a);
	}
};
void Set::print()
{
	cout << "{";
	for (int i = 0; i < size; i++)
	{
			if (i != (size-1))
				cout << d[i] << ", ";
			else 
				cout << d[i];
	}
	cout << "}";
}
Set::~Set()
{
	delete  []d;
}
Set::operator int()
{
	return size;
}
int _tmain(int argc, _TCHAR* argv[])
{ 
	setlocale(LC_ALL, "rus");
	Set a;
	a.print();
	cout << endl;
	cout << "Полученный элемент = ";
	cout << a[3];
	cout << endl;
	cout << "Мощность =" << (int)a << endl;
	Set b;
	b.print();
	cout << endl;
	Set v((Set)(a*b));
	cout << "a*b=";	
	v.print(); 
	cout << endl;
	cout << "Проверка на принадлежность:"<< endl;
	cout << (a > b);
	cout << endl;
	cout << (b > v);
	cout << endl;
	cout << "Проверка на подмножество:"<< endl;
	cout << (a < b);
	cout << endl;
	cout << (v < b); //  меньше, больше
	cout << endl;
	return 0;
}
