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
#include <string>

class Test1
{
public:
	Test1(double log) : _log(log)
	{}

	Test1(double&& x) // �ƶ�����
	{
		swap(_log, x);
	}
private:
	double _log;
};

class Test2
{
public:
	Test2(Test1 log) : _log(log)
	{}
private:
	Test1 _log;
};

class Person
{
public:
	Person(double name = 1.1, int age = 0)
		:_name(name)
		, _age(age)
	{}

	void* operator new(size_t size)
	{

	}

	void operator delete(void* p)
	{

	}
private:
	Test2 _name;
	int _age;
};

int main()
{
	Person s1(2.2, 5);
	Person s2 = s1;
	Person s3 = std::move(s1);
	Person s4;
	s4 = std::move(s2);
	return 0;
}