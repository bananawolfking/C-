#pragma once

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

namespace kele//命名空间
{
	typedef struct Node 
	{
		struct Node* next;
		int val;
	}Node, *ptr;

	//ptr Pushhead();

	//void Swap(int& a, int& b);//引用
	//
	////函数重载
	//void Swap(double& a, double& b);
	//

	////缺省参数
	//void Print(int a = 10, int b = 20, int c = 30);
}

void Swap(int& a, int& b);//引用

//函数重载
void Swap(double& a, double& b);


//缺省参数
void Print(int a = 10, int b = 20, int c = 30);