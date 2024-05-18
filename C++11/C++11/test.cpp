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
//	cout << "��ֵ����" << std::endl;
//}
//
//void func(const int& x)
//{
//	cout << "const��ֵ����" << std::endl;
//}
//
//void func(int&& x)
//{
//	cout << "��ֵ����" << std::endl;
//}
//
//void func(const int&& x)
//{
//	cout << "const��ֵ����" << std::endl;
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
//// �ɱ����ģ��
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

//
//int main()
//{
//	kele::list<kele::string> lt;
//	kele::string("nihao");
//	kele::string str = "nihao";
//	cout << endl;
//
//	lt.push_back("nihao");
//	cout << endl;
//
//	lt.emplace_back("nihao");
//	return 0;
//}


//// lambda
//
//int main()
//{
//	//int a = 0, b = 1;
//	//auto f1 = [](int& a, int& b) {
//	//	int tmp = a;
//	//	a = b;
//	//	b = tmp;
//	//};
//	//cout << a << " " << b << endl;
//	//f1(a, b);
//	//cout << a << " " << b << endl;
//
//
//	//int a = 0, b = 1;
//	//auto f1 = [=]()mutable {
//	//	int tmp = a;
//	//	a = b;
//	//	b = tmp;
//	//	};
//	//// [=]��׽��const��׽����׽������ʱ��������mutable��������ʱ�����ǿɱ��
//	//cout << a << " " << b << endl;
//	//f1();
//	//cout << a << " " << b << endl;
//
//	int a = 0, b = 1;
//	auto f1 = [&]() {
//		int tmp = a;
//		a = b;
//		b = tmp;
//		};
//	// ���ò�׽
//	cout << a << " " << b << endl;
//	f1();
//	cout << a << " " << b << endl;
//	cout << typeid(f1).name() << endl; // class `int __cdecl main(void)'::`2'::<lambda_1>
//
//
//	return 0;
//}


//class Sub
//{
//public:
//	int sub(int x, int y)
//	{
//		// = �Ჶ׽thisָ�룬��Ȼthisָ������ʱ��������ָ�����ݲ����޸ģ���thisָ��string���͵�str����û�иı䣬�ı����str�ڲ�������
//		return [=]() { 
//			// x = 6;
//			str = "nihao";
//			cout << str << endl;
//			return x - y; }();
//	}
//
//	static int sub_(int x, int y)
//	{
//		return x - y;
//	}
//private:
//	int x = 5;
//	kele::string str;
//};
//
//int main()
//{
//	Sub sub;
//	
//	sub.sub(2,3);
//	int x = 0;
//
//	return 0;
//}



// functional

//1. ����ָ��  ������д
//2. �º���		���̫��
//3. lambda���ʽ	��������

#include <functional>
#include <string>
#include <map>

typedef function<int(int, int)> func_t;

typedef int(*func_ptr)(int, int);

int sub_fun(int x, int y)
{
	return x - y;
}

//class sub_class
//{
//public:
//	int operator()(int x, int y)
//	{
//		return x - y;
//	}
//};

//int main()
//{
//	auto sub_lambda = [](int x, int y) {return x - y; };
//
//	func_t sub[] = { sub_fun, sub_class(), sub_lambda };
//	cout << sub[0](1, 3) << endl;
//	cout << sub[1](1, 3) << endl;
//	cout << sub[2](1, 3) << endl;
//
//	map<string, func_t> m = {
//		{"����ָ��", sub_fun },
//		{"�º���", sub_class() },
//		{"lambda���ʽ", sub_lambda },
//	};
//	cout << m["����ָ��"](1,3);
//	cout << m["�º���"](1,3);
//	cout << m["lambda���ʽ"](1,3);
//
//
//	return 0;
//}


//class sub_class
//{
//public:
//	static int _sub(int x, int y)
//	{
//		return x - y;
//	}
//	int sub(int x, int y)
//	{
//		return x - y;
//	}
//};
//
//int main()
//{
//	function<int(int, int)> f1 = &sub_class::_sub;// �����ྲ̬��Ա��������Ҫָ�����򣬿��Բ���&
//	cout << f1(1, 3) << endl;
//
//	function<int(sub_class*, int, int)> f2 = &sub_class::sub;// ���ڳ�Ա������������thisָ�룬������Ҫ��&����
//	sub_class pc;
//	cout << f2(&pc, 1, 3) << endl;// ��������������ʱ��������ֵ����ȡ��ַ
//
//	function<int(sub_class, int, int)> f3 = &sub_class::sub;// ���ڳ�Ա������������thisָ�룬������Ҫ��&����
//	cout << f3(sub_class(), 1, 3) << endl;// �����������⴦�������ͣ���ʵ�����Ա����ʹ�������ڳ�Ա����ʱ������
//
//	// ��bind
//	// ���Ըı������λ�ã�Ҳ���Ըı������������ͨ��д��
//	function<int(int, int)> f4 = bind(&sub_class::sub, sub_class(), placeholders::_1, placeholders::_2);
//	cout << f4(1, 3) << endl;
//
//
//
//	return 0;
//}

void func(int a, int b, int c)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

int main()
{
	function<void(int, int, int)> f1 = bind(func, placeholders::_1, placeholders::_2, placeholders::_3);
	f1(1, 2, 3);

	function<void(int, int)> f2 = bind(func, placeholders::_1, 2, placeholders::_2);
	// placeholders�Ĳ������ֶ�Ӧ���Ǻ�������ʱҪ���������˳��͸���
	f2(1, 3);


	return 0;
}