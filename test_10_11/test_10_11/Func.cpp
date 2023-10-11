//#include"Func.h"

//extern int ADD(int a, int b)
//{
//	return a + b;
//}

#include"Func.h"

void Time::Print()
{
	cout << _year << _month << _day << endl;
}

void Time::Init(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}