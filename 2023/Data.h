#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class Data
{
public:
	Data(int year = 1970, int month = 1, int day = 1);
	Data(const Data& d);
	~Data();

	void Print();
	int GetMonthDay();

	Data& operator=(const Data& d);
	Data operator+(int day);
	Data operator-(int day);
	Data& operator+=(int day);
	Data& operator-=(int day);
	Data& operator++();
	Data& operator--();
	Data operator++(int);
	Data operator--(int);
	bool operator==(const Data& d);
	bool operator>=(const Data& d);
	bool operator<=(const Data& d);
	bool operator>(const Data& d);
	bool operator<(const Data& d);
	bool operator!=(const Data& d);





private:
	int _year;
	int _month;
	int _day;
};
