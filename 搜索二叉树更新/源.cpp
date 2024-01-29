#include<iostream>
using namespace std;

//class Person
//{
//public:
//	inline virtual void func1()
//	{
//		cout << "inline virtual void func1()" << endl;
//	}
//};
//
//int main()
//{
//	Person p;
//	p.func1();
//	Person* pp = &p;
//	pp->func1();
//
//	return 0;
//}

//class A {
//public:
//	A(const char* s) { cout << s << endl; }
//	~A() {}
//};
//class B :virtual public A
//{
//public:
//	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//class C :virtual public A
//{
//public:
//	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//class D :public B, public C
//{
//public:
//	D(const char* s1, const char* s2, const char* s3, const char* s4) :B(s1, s2), C(s1, s3), A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//int main() {
//	D* p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}

//class A
//{
//	static virtual void func()
//	{
//
//	}
//
//};
//
//int main()
//{
//
//	return 0;
//}


//class A
//{
//public:
//	int _a;
//};
//// class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//// class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	B b;
//	C c;
//	D d;
//
//	b._a = 1;
//	b._b = 2;
//
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}

//class A
//{
//	virtual void func() = 0
//	{
//		cout << endl;
//	}
//};
//
//class B : public A
//{
//	void func1()
//	{
//
//	}
//};
//
//int main()
//{
//
//	return 0;
//}



////////////////////////////////////////
#include<string>
#include<queue>
#include<vector>
#include "BinarySearchTree.h"

void TestBSTree1()
{
	key::BSTree<int> b;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	
	for (auto e : a)
	{
		b.InsertR(e);
	}
	b.InOrder();

	key::BSTree<int> c = b;

	//cout << b.FindR(9) << endl;
	//cout << b.FindR(13) << endl;

	b.EraseR(8);
	b.InOrder();

	b.EraseR(4);
	b.InOrder();

	b.Erase(6);
	b.InOrder();

	b.EraseR(7);
	b.InOrder();
	c.InOrder();
}

void TestBSTree2()
{
	key_value::BSTree<string, string> dict;
	dict.Insert("string", "×Ö·û´®");
	dict.Insert("insert", "²åÈë");
	dict.Insert("erase", "É¾³ý");
	dict.Insert("print", "´òÓ¡");
	dict.Insert("kele", "¿ÉÀÖ");

	string str;
	while (cin >> str)
	{
		auto ptr = dict.Find(str);
		if (ptr == nullptr)
		{
			cout << "Î´ÕÒµ½" << endl;
		}
		else
		{
			cout << ":" << ptr->_value << endl;
		}
	}
}

void TestBSTree3()
{
	string arr[] = { "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï","Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶" };
	key_value::BSTree<string, int> count;
	for (auto e : arr)
	{
		auto ptr = count.Find(e);
		if (ptr == nullptr)
		{
			count.Insert(e, 1);
		}
		else
		{
			ptr->_value++;
		}
	}
	count.InOrder();

}

void test()
{
	key::BSTree<int> b;
	vector<vector<int>> ret;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };

	for (auto e : a)
	{
		b.InsertR(e);
	}
	b.InOrder();
	ret = b.levelOrder();

}

int main()
{
	//TestBSTree3();
	test();
	return 0;
}