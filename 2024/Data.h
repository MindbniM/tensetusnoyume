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

	protected:
		int _year;
		int _month;
		int _day;
	};

	class Time : public Data
	{
	public:
		Time(int year = 1970, int month = 1, int day = 1,int hour=0,int m=0)
			:Data(year,month,day)
			,_h(hour),_m(m)
		{
		}
		Time(const Time& t)
			:Data(t),_h(t._h),_m(t._m)
		{
		}
		Time& operator=(const Time& t)
		{
			Data::operator=(t);
			_h = t._h;
			_m = t._m;
		}
		bool operator==(const Time& t)
		{
			return Data::operator==(t) && _h == t._h && _m == t._m;
		}
		friend std::ostream& operator<<(std::ostream& out, const Time& t);
	protected:
		int _h;
		int _m;
	};
	std::ostream& operator<<(std::ostream& out, const Time& t);
	std::ostream& operator<<(std::ostream& out, const Data& d);
	std::istream& operator>>(std::istream& in, Data& d);
}
using namespace MindbniM;
