#include <iostream>
using namespace std;

//// ���Կ���
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

// ���鴫��

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
//void test(int arr[3][5])//ok��
//{}
//void test(int arr[][])//ok�� X
//{}
//void test(int arr[][5])//ok��
//{}
////�ܽ᣺��ά���鴫�Σ������βε����ֻ��ʡ�Ե�һ��[]�����֡�
////��Ϊ��һ����ά���飬���Բ�֪���ж����У����Ǳ���֪��һ�ж���Ԫ�ء�
////�����ŷ������㡣
//void test(int* arr)//ok��X
//{}
//void test(int* arr[5])//ok��
//{}
//void test(int(*arr)[5])//ok��arr��ָ��һ����СΪ5��һά����
//{}
//void test(int** arr)//ok��
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
//	cout << typeid(test).name() << endl; // void __cdecl(void) ������
//	cout << typeid(&test).name() << endl; // void (__cdecl*)(void) ����ָ��
//	void(*p1)(void) = test;
//	void(*p2)(void) = &test; // һ����
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
//	printf("%d\n", sizeof(a[0] + 1));		// 4/8 (ָ��)
//	// ����a[0] ��ʾa���׸�Ԫ�أ���Ϊsizeof���������Ա��������������С +1 ����������û��
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
//	// ��С��
//
//	int ret = Test();
//	if (ret == 1)
//	{
//		cout << "С��" << endl;
//	}
//	else
//	{
//		cout << "���" << endl;
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
//    //A a; // ����һ��A���ʵ��  
//    A* p = nullptr; // ��ָ��pָ�����ʵ��  
//    p->Print(); // ���ڿ���ͨ��p����Print����  
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
//	Test1(double&& x) // �ƶ�����
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
//	cout << kele::less<int>(a, b) << endl; // ��ʾָ������
//	cout << kele::less(&a, &b) << endl; // ��ʾָ������
//
//	return 0;
//}

//// ��̳�
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
//	s.Person::print();//��ʾ���ʻ���print����
//	return 0;
//}

//class Person
//{
//public:
//	Person(string name, int age)
//		:_name(name),
//		_age(age)
//	{
//		cout << "Person(string name, int age) ���๹��" << endl;
//	}
//
//	Person(const Person& t): _name(t._name),_age(t._age)
//	{
//		cout << "Person(const Person & t) ���࿽������" << endl;
//	}
//
//	Person& operator==(const Person& t)
//	{
//		if (this != &t)
//		{
//			_name = t._name;
//			_age = t._age;
//		}
//		cout << "Person& operator==(const Person& t) ���ำֵ" << endl;
//		return *this;
//	}
//
//	Person(Person&& t)
//		:_name(std::forward<std::string>(t._name)),_age(t._age)
//	{
//		cout << "Person(Person&& t) �����ƶ�����" << endl;
//	}
//
//	Person& operator==(Person&& t)
//	{
//		if (this != &t)
//		{
//			_name = std::forward<std::string>(t._name);
//			_age = t._age;
//		}
//		cout << "Person& operator==(const Person& t) �����ƶ���ֵ" << endl;
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person() ��������" << endl;
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
//		cout << "Student(string name, int age, int stdid) �����๹��" << endl;
//	}
//
//	Student(const Student& s)
//		:Person(s), // ����&������Ƭ
//		_stdid(s._stdid)
//	{
//		cout << "Student(const Student & s) �����࿽������" << endl;
//	}
//
//	Student& operator==(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator==(s); // ����&������Ƭ
//			_stdid = s._stdid;
//		}
//		cout << "Student& operator==(const Student& s) �����ำֵ" << endl;
//		return *this;
//	}
//
//	Student(Student&& s):Person(std::forward<Person>(s)), _stdid(s._stdid)
//	{
//		cout << "Student(Student&& s) �������ƶ�����" << endl;
//	}
//
//	Student& operator==(Student&& s)
//	{
//		if (this != &s)
//		{
//			Person::operator==(std::forward<Person>(s)); // ����&������Ƭ
//			_stdid = s._stdid;
//		}
//		cout << "Student& operator==(Student&& s) �������ƶ���ֵ" << endl;
//		return *this;
//	}
//
//	~Student()
//	{
//		cout << "~Student() ����������" << endl;
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
//	Student s1 = s; // ��������
//	cout << "-------------------------------------" << endl;
//	s == s1;		// ��ֵ
//	cout << "-------------------------------------" << endl;
//	Student s2(move(s));
//	cout << "-------------------------------------" << endl;
//	s1 == move(s2);
//	cout << "-------------------------------------" << endl;
//
//	return 0;
//}

class Person
{
public:
	string _name; // ����
};
class Student : virtual public Person
{
public:
	int _num; //ѧ��
};
class Teacher : virtual public Person
{
public:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
public:
	string _majorCourse; // ���޿γ�
};
void Test()
{
	// �������ж������޷���ȷ֪�����ʵ�����һ��
	Assistant a;
	//a._name = "peter";
	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
	a.Student::_name = "xxx";
	a._id = 1;
	a.Teacher::_name = "yyy";
	a._num = 2;
	a._majorCourse = "kele";
}

int main()
{
	Test();
	return 0;
}