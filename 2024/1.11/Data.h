#pragma once
#include<iostream>
#include<assert.h>
#include<list>
namespace MindbniM
{
	class Data
	{
	public:
		Data(int year = 1970, int month = 1, int day = 1);
		Data(const Data& d);
		~Data();

		void Print();
		int GetMonthDay();

		Data& operator=(const Data& d);
		Data operator+(int day) const;
		Data operator-(int day) const;
		Data& operator+=(int day);
		Data& operator-=(int day);
		Data& operator++();
		Data& operator--();
		Data operator++(int);
		Data operator--(int);
		bool operator==(const Data& d) const;
		bool operator>=(const Data& d) const;
		bool operator<=(const Data& d) const;
		bool operator>(const Data& d) const;
		bool operator<(const Data& d) const;
		bool operator!=(const Data& d) const;
		Data* operator&();
		const Data* operator&() const;


		friend std::ostream& operator<<(std::ostream& out, const Data& d);
		friend std::istream& operator>>(std::istream& in, Data& d);

	private:
		int _year;
		int _month;
		int _day;
	};
	std::ostream& operator<<(std::ostream& out, const Data& d);
	std::istream& operator>>(std::istream& in,  Data& d);
}
using namespace MindbniM;
