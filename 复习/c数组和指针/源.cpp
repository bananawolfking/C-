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

#include <string.h>

int main()
{
	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a)); 
	//printf("%d\n", sizeof(a + 0));
	//printf("%d\n", sizeof(*a));
	//printf("%d\n", sizeof(a + 1));
	//printf("%d\n", sizeof(a[1]));
	//printf("%d\n", sizeof(&a));
	//printf("%d\n", sizeof(*&a));
	//printf("%d\n", sizeof(&a + 1));
	//printf("%d\n", sizeof(&a[0]));
	//printf("%d\n", sizeof(&a[0] + 1));

	//char arr[] = { 'a','b','c','d','e','f' };
	////printf("%d\n", strlen(arr));
	//printf("%lld\n", strlen(&arr[0] + 1)); // [] > * > &

	//const char* p = "abcdef";

	//int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a[0] + 1));

	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));			// 48
	printf("%d\n", sizeof(a[0][0]));		// 4
	printf("%d\n", sizeof(a[0]));		// 16
	printf("%d\n", sizeof(a[0] + 1));		// 4/8 (ָ��)
	// ����a[0] ��ʾa���׸�Ԫ�أ���Ϊsizeof���������Ա��������������С +1 ����������û��
	printf("%d\n", sizeof(*(a[0] + 1)));	// 4
	printf("%d\n", sizeof(a + 1));			// 4/8
	printf("%d\n", sizeof(*(a + 1)));		// 4/8 16
	printf("%d\n", sizeof(&a[0] + 1));		// 4/8 
	printf("%d\n", sizeof(*(&a[0] + 1)));	// 4 16
	printf("%d\n", sizeof(*a));			// 4/8 16
	printf("%d\n", sizeof(a[3]));		// 4/8 16
	return 0;
}