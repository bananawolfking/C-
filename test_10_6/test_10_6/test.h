#pragma once

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

namespace kele//�����ռ�
{
	typedef struct Node 
	{
		struct Node* next;
		int val;
	}Node, *ptr;

	//ptr Pushhead();

	//void Swap(int& a, int& b);//����
	//
	////��������
	//void Swap(double& a, double& b);
	//

	////ȱʡ����
	//void Print(int a = 10, int b = 20, int c = 30);
}

void Swap(int& a, int& b);//����

//��������
void Swap(double& a, double& b);


//ȱʡ����
void Print(int a = 10, int b = 20, int c = 30);