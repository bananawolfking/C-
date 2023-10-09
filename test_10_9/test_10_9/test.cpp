//#include<stdio.h>
//#include<stdlib.h>
//
//int rand = 10;
//
//int main()
//{
//	printf("%d\n", rand);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//namespace kele
//{
//	int rand = 10;
//
//	int ADD(int x, int y)
//	{
//		return x + y;
//	}
//	namespace coco
//	{
//		int x = 0;
//	}
//}
//
//using namespace kele;
//
//int main()
//{
//	cout << coco::x << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << "hellow world" << endl;
//	return 0;
//}

#include<iostream>
#include<assert.h>
using namespace std;

//typedef struct SepList
//{
//	int* arr;
//	int capacity;
//}SL;
//
//void SListInit(SL* sl, int n = 4)
//{
//	assert(sl);
//
//	int* newlist = (int*)malloc(sizeof(int) * n);
//	assert(newlist);
//
//	sl->capacity = n;
//	sl->arr = newlist;
//}
//
//int main()
//{
//	SL sl;
//	SListInit(&sl,5);
//	return 0;
//}

//void Function(int a = 10, int b = 20, int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
//int main()
//{
//	Function();
//	return 0;
//}

//void Function(int a = 10, int b = 20, int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
//int main()
//{
//	Function(40);
//	return 0;
//}

//int ADD(int a, int b)
//{
//	return a + b;
//}
//
//double ADD(double a, double b)
//{
//	return a + b;
//}
//
//int main()
//{
//	cout << ADD(1, 2) << endl;
//	cout << ADD(1.5, 1.3) << endl;
//	return 0;
//}
//

//
//int main()
//{
//	int a = 0;
//	int c = 2;
//	int& b = a;	
//	&b = c;
//	b = c;
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int& ra = a;
//
//	cout << &a << endl;
//	cout << &ra << endl;
//	return 0;
//}

//int main()
//{
//
//	int a = 10;
//	const double& ra = (double)a;
//
//	const double& Ra = a;
//	
//
//	double& ra = static_cast<double>(a);
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	cout << (double)a / 2 << endl;
//	cout << static_cast<double>(a) / 2 << endl;
//	cout << a/2 << endl;
//	cout << (double)a << endl;
//	return 0;
//}

//int ADD(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int& a = ADD(1, 2);
//	const int& ra = ADD(1, 2);
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}


int& Count()
{
	static int n = 0;
	n++;
	return n;
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		Count();
	}
	int& count = Count();
	cout << count << endl;
	cout << Count() << endl;   //   ૮₍ ˃ ⤙ ˂ ₎ა
	cout << count << endl;

	return 0;
}