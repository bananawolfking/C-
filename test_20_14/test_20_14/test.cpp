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


int main()
{
	Date a;
	Date b(2023, 1, 1);
	a.Printf();
	b.Printf();
	cout << (b <a) << endl;

	return 0;
}