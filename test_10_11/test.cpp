//#include"Func.h"

//int main()
//{
//	int ret = ADD(1, 2);//
//	return 0;
//}

//#define ADD(x, y) ((x) + (y))
//
//int main()
//{
//	int ret = ADD(1, 2);//
//	return 0;
//}

//typedef char* pstring;
//int main()
//{
//    const pstring p1 = nullptr;    // ����ɹ�����ʧ�ܣ�
//    const pstring* p2;   // ����ɹ�����ʧ�ܣ�
//
//    char* const pt = nullptr;
//    char* const* pt1;
//
//    char const* pt1;
//    return 0;
//}


//int main()
//{
//	int x = 0;
//
//	auto* a = &x;
//	auto& b = x;
//	auto c = &x;
//
//	return 0;
//}

#include<iostream>
using namespace std;

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,6 };
//
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//	for (int x : arr)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//
//	for (auto x : arr)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//
//	for (auto& x : arr)
//	{
//		x *= 2;
//		cout << x << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	cout << sizeof(nullptr) << endl;
//	cout << sizeof((void*)(0)) << endl;
//	return 0;
//}

//#include"Func.h"
//
//int main()
//{
//	Time time;
//	time.Init( 2023, 10, 11);
//	time.Print();
//	return 0;
//}


//// ���м��г�Ա���������г�Ա����
//class A1 
//{
//public:
//	void f1() {}
//private:
//	int _a;
//};
//
//// ���н��г�Ա����
//class A2 {
//public:
//	void f2() {}
//};
//// ����ʲô��û��---����
//class A3
//{};



class A
{
public:
    void Print()
    {
        cout << "Print()" << endl;
    }
private:
    int _a;
};

int main()
{
    A* p = nullptr;
    p->Print();
    return 0;
}


// 1.�������������н���ǣ�  A�����뱨��  B�����б���  C����������
class B
{
public:
    void PrintB()
    {
        cout << _a << endl;
    }
private:
    int _a;
};


int main()
{
    B* p = nullptr;
    p->PrintB();
    return 0;
}
