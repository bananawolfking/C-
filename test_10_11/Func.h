//#pragma once
//
//#include<iostream>
//
////inline int ADD(int a, int b);
//
////int ADD(int a, int b)
////{
////	return a + b;
////}


#include<iostream>
using namespace std;

class Time
{
public:
	void Print();

	void Init(int year, int month, int day);

private:
	int _year;
	int _month;
	int _day;
};