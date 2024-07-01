#include <iostream>
using namespace std;

//// 测试快排
//template<class T>
//void MyQuickSort(T* left, T* right)
//{
//	if (left >= right)
//		return;
//	size_t size = right - left;
//	T* tar = left;
//	size_t l = 0;
//	size_t r = size;
//	while (l < r)
//	{
//		while (*tar < *(left+r) && l < r)
//		{
//			r--;
//		}
//		while (*(left+l) < *tar && l < r)
//		{
//			l++;
//		}
//		
//		swap(*(left + l), *(left + r));
//	}
//	swap(*tar, *(left + l));
//	MyQuickSort(left, left + l);
//	MyQuickSort(left + l + 1, right);
//}
//
//int main()
//{
//
//	
//	int arr[] = { 1,4,5,67,2,3 };
//	MyQuickSort(arr, arr+sizeof(arr)/sizeof(arr[0]) - 1);
//	for (auto it : arr)
//	{
//		cout << it << " ";
//	}
//	return 0;
//}

// 数组传参

//void test(int(*arr)[10], int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		cout << ((int*)arr)[i] << " ";
//	}
//	cout << endl;
//}
//
//
//int main()
//{
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;
//	test(p, 10);
//	return 0;
//}

//#include <stdio.h>
//
//void test(int* arr)//ok?
//{}
//void test2(int* arr[20])//ok?
//{
//	for (int i = 0; i < 20; ++i)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//}
//
//void test(int arr[3][5])//ok？
//{}
//void test(int arr[][])//ok？ X
//{}
//void test(int arr[][5])//ok？
//{}
////总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
////因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
////这样才方便运算。
//void test(int* arr)//ok？X
//{}
//void test(int* arr[5])//ok？
//{}
//void test(int(*arr)[5])//ok？arr是指向一个大小为5的一维数组
//{}
//void test(int** arr)//ok？
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//}
//#include <stdio.h>
//void test()
//{}
//
//int main()
//{
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	cout << typeid(test).name() << endl; // void __cdecl(void) 函数名
//	cout << typeid(&test).name() << endl; // void (__cdecl*)(void) 函数指针
//	void(*p1)(void) = test;
//	void(*p2)(void) = &test; // 一样的
//	return 0;
//}

//typedef void(*handler)(void);
//
//int main()
//{
//	handler arr[12] = { 0 };
//	void(*arr1[12])(void)  = { 0 };
//}

//int main()
//{
//	const int* p = nullptr;
//	int const* p = nullptr;
//	int* const p = nullptr;
//}

//#include <string.h>
//
//int main()
//{
//	//int a[] = { 1,2,3,4 };
//	//printf("%d\n", sizeof(a)); 
//	//printf("%d\n", sizeof(a + 0));
//	//printf("%d\n", sizeof(*a));
//	//printf("%d\n", sizeof(a + 1));
//	//printf("%d\n", sizeof(a[1]));
//	//printf("%d\n", sizeof(&a));
//	//printf("%d\n", sizeof(*&a));
//	//printf("%d\n", sizeof(&a + 1));
//	//printf("%d\n", sizeof(&a[0]));
//	//printf("%d\n", sizeof(&a[0] + 1));
//
//	//char arr[] = { 'a','b','c','d','e','f' };
//	////printf("%d\n", strlen(arr));
//	//printf("%lld\n", strlen(&arr[0] + 1)); // [] > * > &
//
//	//const char* p = "abcdef";
//
//	//int a[3][4] = { 0 };
//	//printf("%d\n", sizeof(a[0] + 1));
//
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));			// 48
//	printf("%d\n", sizeof(a[0][0]));		// 4
//	printf("%d\n", sizeof(a[0]));		// 16
//	printf("%d\n", sizeof(a[0] + 1));		// 4/8 (指针)
//	// 这里a[0] 表示a的首个元素，因为sizeof的特殊所以被当成整个数组大小 +1 后这个特殊就没了
//	printf("%d\n", sizeof(*(a[0] + 1)));	// 4
//	printf("%d\n", sizeof(a + 1));			// 4/8
//	printf("%d\n", sizeof(*(a + 1)));		// 4/8 16
//	printf("%d\n", sizeof(&a[0] + 1));		// 4/8 
//	printf("%d\n", sizeof(*(&a[0] + 1)));	// 4 16
//	printf("%d\n", sizeof(*a));			// 4/8 16
//	printf("%d\n", sizeof(a[3]));		// 4/8 16
//	return 0;
//}


//#include <iostream>
//#include <cassert>
//
//using namespace std;
//
//namespace kele
//{
//	static void* memcpy(void* dest, const void* src, size_t num)
//	{
//		assert(dest && src);
//		char* d = (char*)dest;
//		const char* s = (const char*)src;
//		while (num--)
//		{
//			*d++ = *s++;
//		}
//		return dest;
//	}
//
//	static void* memmove(void* dest, const void* src, size_t num)
//	{
//		assert(dest && src);
//		char* d = (char*)dest;
//		const char* s = (const char*)src;
//		while (num--)
//		{
//			if (dest < src)
//			{
//				*d++ = *s++;
//			}
//			else
//			{
//				*((char*)(d++ + num)) = *(s++ + num);
//			}
//		}
//		return dest;
//	}
//
//}
//
//int main()
//{
//
//
//	return 0;
//}


//static int Test()
//{
//	union test
//	{
//		char ch;
//		int a;
//	};
//	test t;
//	t.a = 1;
//	return t.ch;
//}
//
//int main()
//{
//	// 大小端
//
//	int ret = Test();
//	if (ret == 1)
//	{
//		cout << "小端" << endl;
//	}
//	else
//	{
//		cout << "大端" << endl;
//	}
//
//	return 0;
//}


//class A
//{
//public:
//    void Print()
//    {
//        cout << "Print()" << endl;
//    }
//private:
//    int _a;
//};
//
//int main()
//{
//    //A a; // 创建一个A类的实例  
//    A* p = nullptr; // 让指针p指向这个实例  
//    p->Print(); // 现在可以通过p调用Print函数  
//    return 0;
//}
//#include <string>
//
//class Test1
//{
//public:
//	Test1(double log) : _log(log)
//	{}
//
//	Test1(double&& x) // 移动构造
//	{
//		swap(_log, x);
//	}
//private:
//	double _log;
//};
//
//class Test2
//{
//public:
//	Test2(Test1 log) : _log(log)
//	{}
//private:
//	Test1 _log;
//};
//
//class Person
//{
//public:
//	Person(double name = 1.1, int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//
//	void* operator new(size_t size)
//	{
//
//	}
//
//	void operator delete(void* p)
//	{
//
//	}
//private:
//	Test2 _name;
//	int _age;
//};
//
//int main()
//{
//	Person s1(2.2, 5);
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//	Person s4;
//	s4 = std::move(s2);
//	return 0;
//}

//namespace kele
//{
//	template<class T>
//	bool less(T a, T b)
//	{
//		return a < b;
//	}
//
//	template<>
//	bool less<int*>(int* a, int* b)
//	{
//		return *a < *b;
//	}
//
//	bool less(int* left, int* right)
//	{
//		return *left < *right;
//	}
//}
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	cout << kele::less<int>(a, b) << endl; // 显示指定类型
//	cout << kele::less(&a, &b) << endl; // 显示指定类型
//
//	return 0;
//}

//// 类继承
//class Person
//{
//public:
//	void print()
//	{
//		cout << _name << _age << endl;
//	}
//protected:
//	string _name = "kele";
//	int _age = 21;
//};
//
//class Student :public Person
//{
//public:
//	void print()
//	{
//		cout << _name << _age << _stdid << endl;
//	}
//protected:
//	string _name = "lihua";
//	int _stdid = 1111;
//};
//
//int main()
//{
//	Student s;
//	s.print();
//	s.Person::print();//显示访问基类print函数
//	return 0;
//}

//class Person
//{
//public:
//	Person(string name, int age)
//		:_name(name),
//		_age(age)
//	{
//		cout << "Person(string name, int age) 基类构造" << endl;
//	}
//
//	Person(const Person& t): _name(t._name),_age(t._age)
//	{
//		cout << "Person(const Person & t) 基类拷贝构造" << endl;
//	}
//
//	Person& operator==(const Person& t)
//	{
//		if (this != &t)
//		{
//			_name = t._name;
//			_age = t._age;
//		}
//		cout << "Person& operator==(const Person& t) 基类赋值" << endl;
//		return *this;
//	}
//
//	Person(Person&& t)
//		:_name(std::forward<std::string>(t._name)),_age(t._age)
//	{
//		cout << "Person(Person&& t) 基类移动构造" << endl;
//	}
//
//	Person& operator==(Person&& t)
//	{
//		if (this != &t)
//		{
//			_name = std::forward<std::string>(t._name);
//			_age = t._age;
//		}
//		cout << "Person& operator==(const Person& t) 基类移动赋值" << endl;
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person() 基类析构" << endl;
//	}
//
//	void print()
//	{
//		cout << _name << endl << _age << endl;
//	}
//protected:
//	string _name;
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	Student(string name, int age, int stdid)
//		:Person(name, age),
//		_stdid(stdid)
//	{
//		cout << "Student(string name, int age, int stdid) 派生类构造" << endl;
//	}
//
//	Student(const Student& s)
//		:Person(s), // 利用&引用切片
//		_stdid(s._stdid)
//	{
//		cout << "Student(const Student & s) 派生类拷贝构造" << endl;
//	}
//
//	Student& operator==(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator==(s); // 利用&引用切片
//			_stdid = s._stdid;
//		}
//		cout << "Student& operator==(const Student& s) 派生类赋值" << endl;
//		return *this;
//	}
//
//	Student(Student&& s):Person(std::forward<Person>(s)), _stdid(s._stdid)
//	{
//		cout << "Student(Student&& s) 派生类移动构造" << endl;
//	}
//
//	Student& operator==(Student&& s)
//	{
//		if (this != &s)
//		{
//			Person::operator==(std::forward<Person>(s)); // 利用&引用切片
//			_stdid = s._stdid;
//		}
//		cout << "Student& operator==(Student&& s) 派生类移动赋值" << endl;
//		return *this;
//	}
//
//	~Student()
//	{
//		cout << "~Student() 派生类析构" << endl;
//	}
//
//	void print()
//	{
//		cout << _name << _age << _stdid << endl;
//	}
//protected:
//	int _stdid;
//};
//
//int main()
//{
//	Student s("coke", 22, 21);
//	cout << "-------------------------------------" << endl;
//	Student s1 = s; // 拷贝构造
//	cout << "-------------------------------------" << endl;
//	s == s1;		// 赋值
//	cout << "-------------------------------------" << endl;
//	Student s2(move(s));
//	cout << "-------------------------------------" << endl;
//	s1 == move(s2);
//	cout << "-------------------------------------" << endl;
//
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//public:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//public:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//public:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	//a._name = "peter";
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a._id = 1;
//	a.Teacher::_name = "yyy";
//	a._num = 2;
//	a._majorCourse = "kele";
//}

//int main()
//{
//	Test();
//	return 0;
//}

//class B
//{
//public:
//    int ib;
//    //char cb;
//public:
//    B() :ib(0) {}
//
//    //virtual void f() { cout << "B::f()" << endl; }
//    //virtual void Bf() { cout << "B::Bf()" << endl; }
//};
//class B1 : virtual public B
//{
//public:
//    int ib1;
//    char cb1;
//public:
//    B1() :ib1(11), cb1('1') {}
//
//    //virtual void f() { cout << "B1::f()" << endl; }
//    //virtual void f1() { cout << "B1::f1()" << endl; }
//    //virtual void Bf1() { cout << "B1::Bf1()" << endl; }
//
//
//};
//class B2 : virtual public B
//{
//public:
//    int ib2;
//    char cb2;
//public:
//    B2() :ib2(12), cb2('2') {}
//
//    //virtual void f() { cout << "B2::f()" << endl; }
//    //virtual void f2() { cout << "B2::f2()" << endl; }
//    //virtual void Bf2() { cout << "B2::Bf2()" << endl; }
//
//};
//
//class D : public B1, public B2
//{
//public:
//    int id;
//    char cd;
//public:
//    D() :id(100), cd('D') {}
//
//    //virtual void f() { cout << "D::f()" << endl; }
//    //virtual void f1() { cout << "D::f1()" << endl; }
//    //virtual void f2() { cout << "D::f2()" << endl; }
//    //virtual void Df() { cout << "D::Df()" << endl; }
//
//};
//
//int main()
//{
//    D d;
//
//    int* op = reinterpret_cast<int*>(&d);        //1
//    int* vbptr = reinterpret_cast<int*>(*op);//2
//    const int offset = *(vbptr + 1);                         //3
//
//    std::cout << offset << endl;
//
//    return 0;
//}

// 多态

//class Person 
//{
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person 
//{
//public:
//	void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}

// 抽象类

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//
//void func(Car* car)
//{
//	car->Drive();
//}
//
//void Test()
//{
//	Benz* pBenz = new Benz;
//	BMW* pBMW = new BMW;
//	func(pBenz);
//	func(pBMW);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

class A {
public:
	A(char* s) { cout << s << endl; }
	~A() {}
};
class B :virtual public A
{
public:
	B(char* s1, char* s2) :A(s1) { cout << s2 << endl; }
};
class C :virtual public A
{
public:
	C(char* s1, char* s2) :A(s1) { cout << s2 << endl; }
};
class D :public B, public C
{
public:
	D(char* s1, char* s2, char* s3, char* s4) :B(s2, s2), C(s3, s3), A(s1)
	{
		cout << s4 << endl;
	}
};
int main() {
	char a[] = "class A";
	char b[] = "class B";
	char c[] = "class C";
	char d[] = "class D";

	D* p = new D(a, b, c, d);
	delete p;
	return 0;
}

//class Base1 { public:  int _b1; };
//class Base2 { public:  int _b2; };
//class Derive : public Base1, public Base2 { public: int _d; };
//int main() {
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	cout << p1 << endl;
//	cout << p2 << endl;
//	cout << p3 << endl;
//	return 0;
//}