#include"test.h"



//int main()
//{
//	Stack st(5);
//
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//	cout << st.Pop() << endl;
//	st.Print();
//
//	return 0;
//}



//int main()
//{
//	Queue Q;
//
//	Q.Push(1);
//	Q.Push(2);
//	Q.Push(3);
//	Q.Push(4);
//	cout << Q.Pop() << endl;
//	Q.Push(1);
//	Q.Push(2);
//	Q.Print();
//	return 0;
//}




//int main()
//{
//	Date a;
//	a.Printf();
//	return 0;
//}

//int main()
//{
//	Date a;
//	Date b = a.DaysAfter1(100);
//	b.Printf();
//	a.Printf();
//
//	return 0;
//}


//int main()
//{
//	Date a;
//
//	a.Printf();
//	return 0;
//}

//class Time
//{
//public:
//    Time()
//    {
//        cout << "Time()" << endl;
//        _hour = 0;
//        _minute = 0;
//        _second = 0;
//    }
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//class Date
//{
//private:
//    // 基本类型(内置类型)
//    int _year;
//    int _month;
//    int _day;
//    // 自定义类型
//    Time _t;
//};
//int main()
//{
//    Date d;
//    return 0;
//}

//class Date
//{
//public:
//	Date(int year = 2023, int month = 10, int day = 14)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(Date x)
//	{
//		_year = x._year;
//		_month = x._month;
//		_day = x._day;
//	}
//
//	//void Printf()
//	//{
//	//	cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	//}
//private:
//	int _year = 2023;
//	int _month = 10;
//	int _day = 15;
//};
//
//int main()
//{
//	Date a;
//	Date b(a);
//	return 0;
//}


//int main()
//{
//	Date a;
//	Date b(2023, 1, 1);
//	a.Printf();
//	b.Printf();
//	cout << (b <a) << endl;
//
//	return 0;
//}

//int main()
//{
//	Queue Q ;
//
//	Q.Push(1);
//	Q.Push(2);
//	Q.Push(3);
//	Q.Push(4);
//	cout << Q.Pop() << endl;
//	Q.Push(1);
//	Q.Push(2);
//	Queue a = Q;
//	Q.Print();
//	a.Print();
//
//	return 0;
//}


//int main()
//{
//	Date a;
//	Date b = a;
//	a == b;
//	operator==(a, b);
//	a < b;
//	a.operator<(b);
//	return 0;
//}


//int main()
//{
//	Date a;
//	Date b = a;//拷贝
//	Date c;
//	c = a;//赋值
//	c.operator=(a);//赋值
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//// 前置++：返回+1之后的结果
//// 注意：this指向的对象函数结束后不会销毁，故以引用方式返回提高效率
//	Date& operator++()
//	{
//		_day += 1;
//		return *this;
//	}
//// 后置++：
//// 前置++和后置++都是一元运算符，为了让前置++与后置++形成能正确重载
//// C++规定：后置++重载时多增加一个int类型的参数，但调用函数时该参数不用传递，编译器自动传递
//// 注意：后置++是先使用后+1，因此需要返回+1之前的旧值，故需在实现时需要先将this保存一份，然后给this + 1
//// 而temp是临时对象，因此只能以值的方式返回，不能返回引用
//	Date operator++(int)
//	{
//		Date temp(*this);
//		_day += 1;
//		return temp;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	Date d;
//	Date d1(2023, 10, 16);
//	d = d1++;    // d: 2023,10,17   d1:2023,10,16
//	d = ++d1;    // d: 2023,10,17   d1:2023,10,17
//	return 0;
//}

int main()
{
	Date a;
	a.Printf();
	a.DaysAfter(5000);
	a.Printf();
	return 0;
}