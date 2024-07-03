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

//class A {
//public:
//	A(char* s) { cout << s << endl; }
//	~A() {}
//};
//class B :virtual public A
//{
//public:
//	B(char* s1, char* s2) :A(s1) { cout << s2 << endl; }
//};
//class C :virtual public A
//{
//public:
//	C(char* s1, char* s2) :A(s1) { cout << s2 << endl; }
//};
//class D :public B, public C
//{
//public:
//	D(char* s1, char* s2, char* s3, char* s4) :B(s2, s2), C(s3, s3), A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//int main() {
//	char a[] = "class A";
//	char b[] = "class B";
//	char c[] = "class C";
//	char d[] = "class D";
//
//	D* p = new D(a, b, c, d);
//	delete p;
//	return 0;
//}

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

#include <vector>

//int main()
//{
//	vector<int> v = { 1,2,3,4,5 };
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	return 0;
//}
//// 右值引用
//
//int main()
//{
//	int _x = 1;
//	int _y = 2;
//	int& rx = _x;
//	int& ry = _y;
//	cout << &_x << endl;
//	cout << &rx << endl;
//	cout << &_y << endl;
//	cout << &ry << endl;
//
//
//	double x = 1.1, y = 2.2;
//	// 以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//	// 以下几个都是对右值的右值引用
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	// 这里编译会报错：error C2106: “=”: 左操作数必须为左值
//	//10 = 1;
//	//x + y = 1;
//	//fmin(x, y) = 1;
//	cout << &x << endl;
//	cout << &rr1 << endl; // 栈上
//	cout << &rr2 << endl;
//	cout << &rr3 << endl;
//	rr1++;
//
//	const int& _rr1 = 10;
//	const double& _rr2 = x + y;
//	const double& _rr3 = fmin(x, y);
//
//	cout << &_rr1 << endl; // 栈上
//	cout << &_rr2 << endl;
//	cout << &_rr3 << endl;
//
//	return 0;
//}


// lambda
//int y = 0;
//
//int main()
//{
//	auto lambda_add = [](int x, int y)->int {return x + y; };
//	cout << typeid(lambda_add).name() << endl;
//
//	return 0;
//}




//指向类成员函数的函数指针
//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//class A
//{
//public:
//    A(int aa = 0) :a(aa) {}
//
//    ~A() {}
//
//    void setA(int aa = 1)
//    {
//        a = aa;
//    }
//
//    virtual void print()
//    {
//        cout << "A: " << a << endl;
//    }
//
//    virtual void printa()
//    {
//        cout << "A1: " << a << endl;
//    }
//private:
//    int a;
//};
//
//class B :public A
//{
//public:
//    B() :A(), b(0) {}
//
//    B(int aa, int bb) :A(aa), b(bb) {}
//
//    ~B() {}
//
//    virtual void print()
//    {
//        A::print();
//        cout << "B: " << b << endl;
//    }
//
//    virtual void printa()
//    {
//        A::printa();
//        cout << "B: " << b << endl;
//    }
//private:
//    int b;
//};
//
//int main(void)
//{
//    A a;
//    B b;
//    void (A:: * ptr)(int) = &A::setA;
//    A* pa = &a;
//
//    //对于非虚函数，返回其在内存的真实地址
//    printf("A::set(): %p\n", &A::setA);
//    //对于虚函数， 返回其在虚函数表的偏移位置
//    printf("B::print(): %p\n", &A::print);
//    printf("B::print(): %p\n", &A::printa);
//
//    a.print();
//
//    a.setA(10);
//
//    a.print();
//
//    a.setA(100);
//
//    a.print();
//    //对于指向类成员函数的函数指针，引用时必须传入一个类对象的this指针，所以必须由类实体调用
//    (pa->*ptr)(1000);
//
//    a.print();
//
//    (a.*ptr)(10000);
//
//    a.print();
//    return 0;
//}


//// bind example
//#include <iostream>     // std::cout
//#include <functional>   // std::bind
//
//// a function: (also works with function object: std::divides<double> my_divide;)
//double my_divide(double x, double y) { return x / y; }
//
//struct MyPair {
//	MyPair(double _a, double _b):a(_a),b(_b)
//	{}
//	double a, b;
//	double multiply() { return a * b; }
//};
//
//int main() {
//	using namespace std::placeholders;    // adds visibility of _1, _2, _3,...
//
//	// binding functions:
//	auto fn_five = std::bind(my_divide, 10, 2);               // returns 10/2
//	std::cout << fn_five() << '\n';                          // 5
//
//	auto fn_half = std::bind(my_divide, _1, 2);               // returns x/2
//	std::cout << fn_half(10) << '\n';                        // 5
//
//	auto fn_invert = std::bind(my_divide, _2, _1);            // returns y/x
//	std::cout << fn_invert(10, 2) << '\n';                    // 0.2
//
//	auto fn_rounding = std::bind<int>(my_divide, _1, _2);     // returns int(x/y)
//	std::cout << fn_rounding(10, 3) << '\n';                  // 3
//
//	MyPair ten_two{ 10,2 };
//
//	// binding members:
//	//auto bound_member_fn = std::bind(&MyPair::multiply, _1); // returns x.multiply()
//	//std::cout << bound_member_fn(ten_two) << '\n';           // 20
//
//	//auto bound_member_data = std::bind(&MyPair::a, ten_two); // returns ten_two.a
//	//std::cout << bound_member_data() << '\n';                // 10
//
//	std::cout << typeid(&MyPair::a).name() << endl;
//
//	std::function<double(MyPair)> func = &MyPair::a;
//
//
//	std::cout << func(MyPair(10,2)) << endl;
//
//
//	return 0;
//}


//#include <thread>
//
//void func()
//{
//	cout << this_thread::get_id();
//}
//
//int main()
//{
//	cout << this_thread::get_id() << endl;
//	thread th(func);
//	th.join();
//	return 0;
//}

//#include <thread>
//#include <mutex>
//#include <condition_variable>
//void two_thread_print()
//{
//	std::mutex mtx;
//	condition_variable c;
//	int n = 100;
//	bool flag = true;
//	thread t1([&]() {
//		int i = 0;
//		while (i < n)
//		{
//			unique_lock<mutex> lock(mtx);
//			c.wait(lock, [&]()->bool {return flag; });
//			cout << i << endl;
//			flag = false;
//			i += 2; // 偶数
//			c.notify_one();
//		}
//	});
//	thread t2([&]() {
//		int j = 1;
//		while (j < n)
//		{
//			unique_lock<mutex> lock(mtx);
//			c.wait(lock, [&]()->bool {return !flag; });
//			cout << j << endl;
//			j += 2; // 奇数
//			flag = true;
//			c.notify_one();
//		}
//	});
//	t1.join();
//	t2.join();
//}
//int main()
//{
//	two_thread_print();
//	return 0;
//}



//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//void Func()
//{
//	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
//   // 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
//   // 重新抛出去。
//	int* array = new int[10];
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//		throw;
//	}
//	// ...
//	cout << "delete []" << array << endl;
//	delete[] array;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	return 0;
//}

//#include <memory>
//
//int main()
//{
//	unique_ptr<int> ptr1(new int(1));
//	unique_ptr<int> ptr2 = move(ptr1);
//
//
//	return 0;
//}

#include "./smartptr.h"

//namespace kele
//{
//	struct data
//	{
//		int a = 0;
//		double b = 1.1;
//	};
//}

//int main()
//{
//	//kele::auto_ptr<int> ptr1(new int(1));
//	//cout << *ptr1 << endl;
//
//	//auto ptr3 = ptr1;
//	//kele::auto_ptr<kele::data> ptr2(new kele::data);
//
//	//cout << ptr2->a << ptr2->b << endl;
//
//	//{
//	//	kele::unique_ptr<kele::data> ptr1(new kele::data[5], [](kele::data* ptr) {delete[] ptr; });
//	//	auto ptr2 = move(ptr1);
//	//}
//
//	//kele::shared_ptr<kele::data> ptr1(new kele::data[5], [](kele::data* ptr) {
//	//	cout << "delete[]" << endl;
//	//	delete[] ptr; 
//	//});
//	//auto ptr2 = move(ptr1);
//
//	return 0;
//}

//namespace kele
//{
//	struct data
//	{
//		int a = 0;
//		kele::weak_ptr<kele::data> next = nullptr;
//		kele::weak_ptr<kele::data> prev = nullptr;
//	};
//}
//
//int main()
//{
//	kele::shared_ptr<kele::data> ptr1(new kele::data);
//	kele::shared_ptr<kele::data> ptr2(new kele::data);
//
//	ptr1->next = ptr2;
//	ptr2->next = ptr1;
//
//	return 0;
//}


//class A
//{
//public:
//	virtual void f() {}
//};
//class B : public A
//{};
//void fun(A* pa)
//{
//	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
//	B* pb1 = static_cast<B*>(pa);
//	B* pb2 = dynamic_cast<B*>(pa);
//	cout << "pb1:" << pb1 << endl;
//	cout << "pb2:" << pb2 << endl;
//}
//int main()
//{
//	A a;
//	B b;
//	fun(&a);
//	fun(&b);
//	return 0;
//}

int main()
{
	int a = 12;
	// 这里使用static_cast会报错，应该使用reinterpret_cast
	//int *p = static_cast<int*>(a);
	int* p = reinterpret_cast<int*>(a);
	cout << p << endl;
	return 0;
}