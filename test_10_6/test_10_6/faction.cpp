#include"test.h"

using namespace kele;

//ptr Pushhead()
//{
//
//}

void Swap(int& a, int& b)//应用
{
	int temp = a;
	a = b;
	b = temp;
}
//函数重载
void Swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//缺省参数
//void Print(int a = 10, int b = 20, int c = 30)
void Print(int a, int b, int c)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}