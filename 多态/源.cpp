#include<iostream>
using namespace std;

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "ÂòÆ±È«¼Û" << endl;
//	}
//
//	virtual void Func()
//	{
//		cout << _id << endl;
//		BuyTicket();
//	}
//protected:
//	int _id = 1;
//};
//
//class Student :public Person
//{
//public:
//	void BuyTicket()
//	{
//		cout << "ÂòÆ±°ë¼Û" << endl;
//	}
//
//
//protected:
//	int _id = 2;
//};
//
//class X :public Student
//{
//	void BuyTicket()
//	{
//		cout << "ÂòÆ±1/4¼Û" << endl;
//	}
//};

//int main()
//{
//	Person* p = new Person;
//	Person* s = new Student;
//	X x;
//	p->Func();
//	s->Func();
//
//
//	return 0;
//}

//
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual ~Student() override { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}


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
//		cout << "Benz-ÊæÊÊ" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-²Ù¿Ø" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}

//class A
//{
//public:
//    virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//    virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//    void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//
//int main()
//{
//    B* p = new B;
//    p->test();
//    return 0;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	Base b;
//	cout << sizeof(Base) << endl;
//	return 0;
//}


//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "ÂòÆ±È«¼Û" << endl;
//	}
//
//	virtual void Func()
//	{
//		cout << _id << endl;
//		BuyTicket();
//	}
//protected:
//	int _id = 1;
//};
//
//class Student :public Person
//{
//public:
//	void BuyTicket()
//	{
//		cout << "ÂòÆ±°ë¼Û" << endl;
//	}
//
//protected:
//	int _id = 2;
//};
//
//typedef void(*VFPtr) ();
//
//void PrintVFTable(VFPtr* p)
//{
//	for (int i = 0; p[i] != nullptr; ++i)
//	{
//		printf("[%d] -> %p\n", i, p[i]);
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	
//	Person* pp = &s;
//	pp->BuyTicket();
//
//	s.BuyTicket();
//
//	PrintVFTable(*(VFPtr**)&p);
//	PrintVFTable(*(VFPtr**)&s);
//	return 0;
//}



class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1 = 1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2 = 2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1 = 3;
};

typedef void(*VFPtr) ();

void PrintVFTable(VFPtr* p)
{
	cout << " Ðé±íµØÖ·:" << p << endl;
	for (int i = 0; p[i] != nullptr; ++i)
	{
		printf("[%d] -> %p ", i, p[i]);
		VFPtr f = p[i];
		f();
	}
	cout << endl;
}

int main()
{
	Base1 b1;
	Base2 b2;
	PrintVFTable(*(VFPtr**)&b1);
	PrintVFTable(*(VFPtr**)&b2);

	Derive d;
	VFPtr* vTableb1 = *(VFPtr**)&d;
	PrintVFTable(vTableb1);

	Base2* b = &d;
	VFPtr* vTableb2 = *(VFPtr**)b;
	PrintVFTable(vTableb2);
	return 0;
}


