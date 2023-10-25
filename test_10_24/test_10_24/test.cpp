//#include<iostream>
//using namespace std;
#include"Date.h"

//class A
//{
//public:
//	A(int i = 0)	{count++;}
//	A(const A& x)	{count++;}
////private:
//	static int count;
//	int i = 0;
//};
//int A::count = 0;
//
//int main()
//{
//	A a(1);
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



//class A
//{
//public:
//	A() { ++_scount; }
//
//	A(const A& t) { ++_scount; }
//
//	static int GetACount() { return _scount; }
//private:
//	static int _scount;
//};
//
//int A::_scount = 0;
//
//int main()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//	return 0;
//}


//class A
//{
//public:
//	A()	{count++;}
//
//	A(const A& x)	{count++;}
//
//	int Get()//非静态成员函数可以调用静态成员函数
//	{
//		return GetCount();
//	}
//
//	static int GetCount()	{return count;}
//private:
//	static int count;
//};
//
//int A::count = 0;
//
//int main()
//{
//	A a;
//	cout << a.GetCount() << endl;
//	cout << A().GetCount() << endl;
//	cout << A::GetCount() << endl;
//	cout << a.Get() << endl;
//
//	return 0;
//}



//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}


//class Time
//{
//    friend class Date;
//    // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//    Time(int hour = 0, int minute = 0, int second = 0)
//        : _hour(hour)
//        , _minute(minute)
//        , _second(second)
//    {}
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//
//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//        :
//        _year(year),
//        _month(month),
//        _day(day)
//    {}
//
//    void SetTimeOfDate(int hour, int minute, int second)
//    {
//        // 直接访问时间类私有的成员变量
//        _t._hour = hour;
//        _t._minute = minute;
//        _t._second = second;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//    Time _t;
//};

//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        //...
//        return n;
//    }
//};
//
//int main()
//{
//    cout << Solution().Sum_Solution(10) << endl;
//    return 0;
//}


class A
{
public:
	A(int n = 0)
		:_a(n)
	{
		cout << "A(int n)" << endl;
	}

	/*~A()
	{
		cout << "~A()" << endl;
	}*/

	A(const A& x)
		:_a(x._a)
	{
		cout << "A(const A& x)" << endl;
	}

	A& operator=(const A& x)
	{
		_a = x._a;

		cout << "A& operator=(const A& x)" << endl;
		return *this;
	}

private:
	int _a;
};

void func1(A a1){}

A func2()
{
	return 1;
}


A func3()
{
	return A(1);
}

A func4()
{
	A temp(1);
	int a = 0;
	return temp;
}

int main()
{
	////隐式类型转换
	//A b = 1;// 1 -> A类型定义构造函数 temp(1) -> b赋值构造
	//cout << "------------------------------" << endl;
	////等价于
	//A temp(1);
	//A d = temp;

	//func1(1);//隐形类型转换构造+拷贝构造
	//cout << "------------------------------" << endl;
	//func1(A(1));//构造+拷贝构造
	//cout << "------------------------------" << endl;
	//A temp(1);
	//func1(temp);

	func4();//隐形类型转换构造+拷贝构造
	cout << "------------------------------" << endl;
	A ref1 = func2();//隐形类型转换构造+拷贝构造+拷贝构造
	cout << "------------------------------" << endl;
	A ref2 = func3(); //构造 + 拷贝构造 + 拷贝构造
	cout << "------------------------------" << endl;
	A ref3 = func4(); //构造 + 拷贝构造 + 拷贝构造


	return 0;
}



