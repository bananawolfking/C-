#pragma once
#include<iostream>
#include<stdlib.h>

using namespace std;

class Stack
{
public:
	void Init(int n = 4);

	void Push(int i);

	void Print();
private:
	int* _arr;
	int _size;
	int _capacity;
};