//#include<iostream>
//using namespace std;

//class A
//{
//public:
//	A(int i = 0)
//	{
//		count++;
//	}
//	A(const A& x)
//	{
//		count++;
//	}
////private:
//	static int count;
//	int i = 0;
//};
//int A::count = 0;
//
//void func(A& x)
//{}
//
//int main()
//{
//	A a(1);
//	A b = a;
//	A c = 1;
//	func(a);
//	cout << A::count << endl;
//	//cout << A::i << endl;
//	A* p = nullptr;
//	cout << p->count << endl;
//	//cout << p->i << endl;
//	return 0;
//}


//class Date
//{
//public:
//	Date()  
//	{
//		Date(0, 0, 0);//这里其实是定义了一个匿名对象
//	}
//
//	Date(int year, int month, int day)
//		:_year(year),
//		_month(month),
//		_day(day)
//	{}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

#include"Date.h"

//int main()
//{
//	Date a;
//	a.Print();
//	return 0;
//}


//class A
//{
//public:
//	A(int n = 0)
//		:_a(n)
//	{
//		cout << "A(int n)" << endl;
//	}
//
//	A(const A& x)
//		:_a(x._a)
//	{
//		cout << "A(const A& x)" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A a(1);
//	//隐式类型转换
//	A b = 1;// 1 -> A类型定义构造函数 temp(1) -> b赋值构造
//	//等价于
//	A temp(1);
//	A d = temp;
//
//	//A& c = 1;
//	const A& c = 1;//加const就可以，说明存在temp（1）常性的临时变量，证明发生了隐式类型转换
//	return 0;
//}


//class A
//{
//public:
//	explicit A(int n = 0, int b = 0)
//		:_a(n),
//		_b(b)
//	{
//		cout << "A(int n = 0, int b = 0)" << endl;
//	}
//
//	A(const A& x)
//		:_a(x._a),
//		_b(x._b)
//	{
//		cout << "A(const A& x)" << endl;
//	}
//
//private:
//	int _a;
//	int _b;
//};
//
//int main()
//{
//	A a(1, 2);
//	//A b = { 1, 2 };
//	return 0;
//}



class A
{
public:
	A() { ++_scount; }

	A(const A& t) { ++_scount; }

	static int GetACount() { return _scount; }
private:
	static int _scount;
};

int A::_scount = 0;

int main()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
	return 0;
}