#include"Date.h"

int Date::MonthDay(int year, int month)
{
	assert(0 < month < 13);

	int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year % 4 == 0 || (year % 400 == 0 && year % 100 != 0))
	{
		day[2]++;
	}
	return day[month];
}

Date::Date(int year, int month, int day)
{
	if ((0 < month < 13) && (0 <= day <= MonthDay(year, month)))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "日期格式错误" << endl;
		_year = 0;
		_month = 0;
		_day = 0;
	}
}

Date::Date(const Date& x)
{
	_year = x._year;
	_month = x._month;
	_day = x._day;
}

Date& Date::operator=(const Date x)
{
	if (this != &x)
	{
		_year = x._year;
		_month = x._month;
		_day = x._day;
	}

	return *this;
}

bool Date::operator==(const Date x)
{
	return _year == x._year
		&& _month == x._month
		&& _day == x._day;
}

bool Date::operator!=(const Date x)
{
	return _year != x._year
		|| _month != x._month
		|| _day != x._day;
}

bool Date::operator<(const Date x)
{
	return _year < x._year
		|| _year == x._year && _month < x._month
		|| _year == x._year && _month == x._month && _day < x._day;
}

bool Date::operator<=(const Date x)
{
	return *this < x || *this == x;
}

bool Date::operator>(const Date x)
{
	return !(*this <= x);
}

bool Date::operator>=(const Date x)
{
	return *this > x || *this == x;
}

Date& Date::operator+=(int x)
{
	_day += x;
	int monthday = 0;
	while (_day > (monthday = MonthDay(_year, _month)))
	{
		_day -= monthday;
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}


Date Date::operator+(int x)
{
	Date copy = *this;
	copy += x;
	return copy;
}

Date& Date::operator-=(int x)
{
	_day -= x;
	while (_day < 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += MonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int x)
{
	Date copy = *this;
	copy -= x;
	return copy;
}

int Date::operator-(const Date& x)//传统计算差值的实现，不好理解，但效率高
{
	int ret = 0;
	int flag = 1;
	Date max = *this;
	Date min = x;
	
	if (max < min)
	{
		max = x;
		min = *this;
		flag = -1;
	}

	while (max._year > min._year)
	{
		if (max._month > 0)
		{
			max._month--;
			if (max._month == 0)
			{
				max._month = 12;
				max._year--;
			}
			max._day += MonthDay(max._year, max._month);
		}
	}
	while (max._month > min._month)
	{
		max._month--;
		max._day += MonthDay(max._year, max._month);
	}
	if (max._day > min._day)
	{
		ret = max._day - min._day;
		max._day = min._day;
	}

	return ret * flag;
}

Date& Date::operator++()
{
	int monthday = 0;
	_day++;
	if (_day > (monthday = MonthDay(_year, _month)))
	{
		_month++;
		_day -= monthday;
		if (_month == 13)
		{
			_month = 12;
			_year++;
		}
	}
	return *this;
}

Date Date::operator++(int)
{
	Date copy = *this;
	++(*this);
	return copy;
}

Date& Date::operator--()
{
	int monthday = 0;
	_day--;
	if (_day == 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day = MonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator--(int)
{
	Date copy = *this;
	--(*this);
	return copy;
}

//int Date::operator-(const Date& x)//追赶的思想，方便理解，但效率不如上面的
//{
//	int ret = 0;
//	int flag = 1;
//	Date max = *this;
//	Date min = x;
//
//	if (max < min)
//	{
//		max = x;
//		min = *this;
//		flag = -1;
//	}
//
//	while (max != min)
//	{
//		++min;
//		++ret;
//	}
//
//	return ret * flag;
//}


void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}