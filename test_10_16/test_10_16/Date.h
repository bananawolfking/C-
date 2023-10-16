#pragma once

#include<iostream>
#include<assert.h>

using namespace std;

class Date
{
public:

	int MonthDay(int year, int month);
	Date(int year = 2023, int month = 10, int day = 16);
	Date(const Date& x);

	Date& operator=(const Date x);
	bool operator==(const Date x);
	bool operator!=(const Date x);
	bool operator<(const Date x);
	bool operator<=(const Date x);
	bool operator>(const Date x);
	bool operator>=(const Date x);

	Date& operator+=(int x);
	Date operator+(int x);
	Date& operator-=(int x);
	Date operator-(int x);
	int operator-(const Date& x);

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	void Print();

private:
	int _year;
	int _month;
	int _day;
};

//class Date
//{
//public:
//	// 获取某年某月的天数
//	int GetMonthDay(int year, int month)
//	{
//		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,
//31 };
//		int day = days[month];
//		if (month == 2
//			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			day += 1;
//		}
//		return day;
//	}

	//// 全缺省的构造函数
	//Date(int year = 1900, int month = 1, int day = 1);
	//// 拷贝构造函数
	//// d2(d1)
	//Date(const Date& d);

	//// 赋值运算符重载
	//// d2 = d3 -> d2.operator=(&d2, d3)
	//Date& operator=(const Date& d);
	//// 析构函数
	//~Date();
	//// 日期+=天数
	//Date& operator+=(int day);
	//// 日期+天数
	//Date operator+(int day);
	//// 日期-天数
	//Date operator-(int day);
	//// 日期-=天数
	//Date& operator-=(int day);
	//// 前置++
	//Date & operator++();
	//// 后置++
	//Date operator++(int);
	//// 后置-
	//Date operator--(int);
	//// 前置-
	//Date& operator--();

	//// >运算符重载
	//bool operator>(const Date& d);
	//// ==运算符重载
	//bool operator==(const Date& d);
	//// >=运算符重载
	//bool operator >= (const Date& d);

	//// <运算符重载
	//bool operator < (const Date& d);
	//// <=运算符重载
	//bool operator <= (const Date& d);
	//// !=运算符重载
	//bool operator != (const Date& d);
	//// 日期-日期  返回天数