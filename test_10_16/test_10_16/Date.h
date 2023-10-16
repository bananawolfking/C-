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
//	// ��ȡĳ��ĳ�µ�����
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

	//// ȫȱʡ�Ĺ��캯��
	//Date(int year = 1900, int month = 1, int day = 1);
	//// �������캯��
	//// d2(d1)
	//Date(const Date& d);

	//// ��ֵ���������
	//// d2 = d3 -> d2.operator=(&d2, d3)
	//Date& operator=(const Date& d);
	//// ��������
	//~Date();
	//// ����+=����
	//Date& operator+=(int day);
	//// ����+����
	//Date operator+(int day);
	//// ����-����
	//Date operator-(int day);
	//// ����-=����
	//Date& operator-=(int day);
	//// ǰ��++
	//Date & operator++();
	//// ����++
	//Date operator++(int);
	//// ����-
	//Date operator--(int);
	//// ǰ��-
	//Date& operator--();

	//// >���������
	//bool operator>(const Date& d);
	//// ==���������
	//bool operator==(const Date& d);
	//// >=���������
	//bool operator >= (const Date& d);

	//// <���������
	//bool operator < (const Date& d);
	//// <=���������
	//bool operator <= (const Date& d);
	//// !=���������
	//bool operator != (const Date& d);
	//// ����-����  ��������