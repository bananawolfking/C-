#pragma once

#include<iostream>
#include<assert.h>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out,const Date& x);
	friend istream& operator>>(istream& in, Date& x);
public:

	int MonthDay(int year, int month) const;
	Date(int year = 2023, int month = 10, int day = 16);
	Date(const Date& x);

	Date& operator=(const Date x);
	bool operator==(const Date x) const;
	bool operator!=(const Date x) const;
	bool operator<(const Date x) const;
	bool operator<=(const Date x) const;
	bool operator>(const Date x) const;
	bool operator>=(const Date x) const;

	Date& operator+=(int x);
	Date operator+(int x) const;
	Date& operator-=(int x);
	Date operator-(int x) const;
	int operator-(const Date& x) const;

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	void Print() const;

private:
	int _year;
	int _month;
	int _day;
};

