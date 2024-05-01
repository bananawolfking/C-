#include<iostream>
#include<assert.h>

using namespace std;

//int main()
//{
//	int a = 0;
//	int& b = a;
//	int& c = b;
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//
//	int x = 5;
//	c = x;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//
//	return 0;
//}

//int& Count()
//{
//	static int n = 0;
//	n++;
//	return n;
//}
//
//#define N 10
//
//typedef struct Posy
//{
//	int a[N];
//
//}Py;
//
//int& PosAt(Py& py, int i)
//{
//	assert(i < 10);
//
//	return py.a[i];
//}
//
//int main()
//{
//	int ret = Count();
//	cout << ret << endl;
//
//	Py py;
//
//	for (int i = 0; i < N; i++)
//	{
//		PosAt(py, i) = i * 10;
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << PosAt(py, i) << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = 0;
//	c = a + b;
//	return c;
//}
//
//
//int main()
//{
//	int& x = Add(1, 2);
//	cout << x << endl;
//	Add(2, 2);
//	cout << x << endl;
//	cout << x << endl;
//	
//	return 0;
//}

//int Add(int a, int b)
//{
//	int c = 0;
//	c = a + b;
//	return c;
//}
//
//int main()
//{
//	int a = 0;
//	int& b = a;
//
//	const int& bz = a;
//
//	//const int a1 = 0;
//	//int& b1 = a1;
//
//	const int a1 = 0;
//	const int& b1 = a1;
//
//	const int a2 = 0;
//	int b2 = a2;
//  
//	/*int& c = Add(1, 2);*/
//	const int& c = Add(1, 2);//返回值是临时变量是不能被修改的
//
//	int x = 0;
//	//double& y = x;
//	const double& y = x;//x由int类型隐形转化为double类型，中间产生临时变量是不能被修改的
//
//	return 0;
//}


#define ADD(x,y) ((x)+(y))

int main()
{
	cout << ADD(1, 2) << endl;
	return 0;
}