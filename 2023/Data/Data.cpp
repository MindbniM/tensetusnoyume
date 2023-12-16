#include"Data.h"
Data::Data(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (_year < 0 || _month<0 || _day < 0 || _month>12 || _day>GetMonthDay())
	{
		assert(false);
	}
}
Data::Data(const Data& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	if (_year < 0 || _month<0 || _day < 0 || _month>12 || _day>GetMonthDay())
	{
		assert(false);
	}
}
Data::~Data()
{
	_year = 1970;
	_month = 1;
	_day = 1;
}
void Data::Print()
{
	cout << _year << '/' << _month << '/' << _day << endl;
}
int Data::GetMonthDay()
{
	assert(_month > 0 && _month <= 12 && _year > 0);
	int month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0))
		return 29;
	return month[_month - 1];
}
Data& Data::operator=(const Data& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
Data& Data::operator+=(int day)
{
	if (day < 0)
		return *this -= (-day);
	_day += day;
	while (_day > GetMonthDay())
	{
		_day -= GetMonthDay();
		_month += 1;
		if (_month == 13)
		{
			_year += 1;
			_month = 1;
		}
	}
	return *this;
}
Data Data::operator+(int day)
{
	Data d(*this);
	d += day;
	return d;
}
Data& Data::operator-=(int day)
{
	if (day < 0)
		return *this += (-day);
	_day -= day;
	while (_day<=0)
	{
		_month -= 1;
		if (_month == 0)
		{
			_year -= 1;
			_month = 12;
		}
		_day += GetMonthDay();
	}
	return *this;
}
Data Data::operator-(int day)
{
	Data d(*this);
	d -= day;
	return d;
}
Data& Data::operator++()
{
	this->operator+=(1);
	return *this;
}
Data& Data::operator--()
{
	this->operator-=(1);
	return *this;
}
Data Data::operator++(int)
{
	Data d(*this);
	this->operator+=(1);
	return d;
}
Data Data::operator--(int)
{
	Data d(*this);
	this->operator-=(1);
	return d;
}
bool Data::operator==(const Data& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Data::operator>(const Data& d)
{
	if (_year > d._year)
		return true;
	if (_year == d._year)
	{
		if (_month > d._month)
			return true;
		if (_month == d._month)
		{
			if (_day >d._day)
				return true;
		}
	}
	return false;
}

bool Data::operator>=(const Data& d)
{
	return *this > d || *this == d;
}
bool Data::operator<(const Data& d)
{
	return !(*this >= d);
}
bool Data::operator<=(const Data& d)
{
	return !(*this > d);
}
bool Data::operator!=(const Data& d)
{
	return !(*this == d);
}









