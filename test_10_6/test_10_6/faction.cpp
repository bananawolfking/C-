#include"test.h"

using namespace kele;

//ptr Pushhead()
//{
//
//}

void Swap(int& a, int& b)//Ӧ��
{
	int temp = a;
	a = b;
	b = temp;
}
//��������
void Swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//ȱʡ����
//void Print(int a = 10, int b = 20, int c = 30)
void Print(int a, int b, int c)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}