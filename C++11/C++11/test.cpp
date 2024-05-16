#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include "string.h"
#include "vector.h"
#include "list.h"

using namespace std;

//int main()
//{
//	//kele::string str;
//	//str = kele::to_string(-123);
//
//	kele::string str = "11111111";
//	cout << str << endl;
//	return 0;
//}

//void func(int& x)
//{
//	cout << "左值引用" << std::endl;
//}
//
//void func(const int& x)
//{
//	cout << "const左值引用" << std::endl;
//}
//
//void func(int&& x)
//{
//	cout << "右值引用" << std::endl;
//}
//
//void func(const int&& x)
//{
//	cout << "const右值引用" << std::endl;
//}
//
//
//template<class T>
//void PerfectForward(T&& t)
//{
//	func(forward<T>(t));
//	cout << typeid(t).name() << endl;
//}
//
//
//int main()
//{
//	int x = 8;
//	PerfectForward(x);
//	const int& y = x;
//	PerfectForward(y);
//	PerfectForward(8);
//	const int&& z = 8;
//	PerfectForward(z);
//	PerfectForward(move(y));
//	return 0;
//}

//void _func()
//{
//	cout << endl;
//}
//
//template<class T,class... Args>
//void _func(const T& x ,Args... args)
//{
//	cout << x << " ";
//	_func(args...);
//}
//
//
//// 可变参数模板
//template<class... Args>
//void func(Args... args)
//{
//	cout << sizeof...(args) << endl;
//	_func(args...);
//}
//
//
//
//int main()
//{
//	func(1, 2, 3, "111");
//
//	return 0;
//}



//int main()
//{
//	kele::list<kele::string> lt;
//	kele::string("nihao");
//	kele::string str = "nihao";
//	cout << endl;
//
//	lt.push_back("nihao");
//	return 0;
//}

//template<class T>
//void Printargs(const T& t)
//{
//	cout << t << " ";
//}
//
//
//template<class... Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (Printargs(args), 0)... };
//}
//
//int main()
//{
//	ShowList(1, 2, 3, "1111111");
//	return 0;
//}


int main()
{
	kele::list<kele::string> lt;
	kele::string("nihao");
	kele::string str = "nihao";
	cout << endl;

	lt.push_back("nihao");
	cout << endl;

	lt.emplace_back("nihao");
	return 0;
}