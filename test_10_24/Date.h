#pragma once


#include<iostream>
using namespace std;

class Date
{
public:
	Date(int i = 0);

	Date(int year, int month, int day);

	

	void Print();
private:
	int _year;
	int _month;
	int _day;
};