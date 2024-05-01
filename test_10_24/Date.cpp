#include"Date.h"


Date::Date(int i) :Date(0, 0, 0)  {}

Date::Date(int year, int month, int day)
	:_year(year),
	_month(month),
	_day(day)
{}

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}
