#include<iostream>
using namespace std;

//int globalVar = 1;
//static int staticGlobalVar = 1;
//
//int main()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//	return 0;
//}



//int main()
//{
//	// ��̬����һ��int���͵Ŀռ�
//	int* p1 = new int;
//
//	// ��̬����10��int���͵Ŀռ�
//	int* p2 = new int[10];
//
//	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ1
//	int* p3 = new int{ 1 };
//
//	// ��̬����10��int���͵Ŀռ䲢��ʼ��
//	int* p4 = new int[10] {1, 2, 3};
//
//
//	delete p1;
//	delete[] p2;
//	delete p3;
//	delete[] p4;
//	return 0;
//}
 
 
//class A
//{
//public:
//    A(int a = 0, int b = 0)
//        : _a(a),
//        _b(b)
//    {
//        cout << "A():" << this << endl;
//    }
//
//    ~A()
//    {
//        cout << "~A():" << this << endl;
//    }
//private:
//    int _a;
//    int _b;
//};

//int main()
//{
//    A* p1 = new A;
//    A* p2 = new A{ 1 };
//    A* p3 = new A{1, 2};
//
//    A* p4 = new A[3]{ {1,2}, 2 };
//
//    delete p1, p2, p3;
//    delete[] p4;
//
//	return 0;
//}

//int main()
//{
//    A* p1 = (A*)malloc(sizeof(A));
//    if (p1 == nullptr)
//    {
//        perror("malloc fail");
//        exit(-1);
//    }
//    new(p1)A(1, 2);
//    p1->~A();
//    free(p1);
//
//    A* p2 = (A*)operator new(sizeof(A));
//
//    new(p2)A();
//    p2->~A();
//    operator delete(p2);
//
//    return 0;
//}



//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Swap(double& a, double& b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//}


//template<class T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	int x = 1;
//	int y = 2;
//	double x1 = 10.11;
//	double y1 = 11.11;
//	Swap(x, y);
//	Swap(x1, y1);
//	//Swap((double)x, x1);
//	Swap<int>(x, y);
//
//	return 0;
//}

//int Add(int left, int right)
//{
//    return left + right;
//}
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//    return left + right;
//}
//
//int main()
//{
//    //int a1 = 10, a2 = 20;
//    //double d1 = 10.0, d2 = 20.0;
//    //Add(a1, a2);//���÷�ģ�庯��
//    //Add(d1, d2);
//    //Add(a1, (int)d1);
//    //Add<int>(a1, d1);//����ģ���
//    Add(1, 2);     // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//    Add(1.0, 2.0);   // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//    return 0;
//}



template<class T>
class List
{
public:
	List(int capacity = 10)
		:_a(new T[capacity]),
		_top(0),
		_capacity(capacity)
	{}

	~List(); // ʹ������������ʾ�������������������ⶨ�塣

private:
	T* _a;
	int _top;
	int _capacity;
};

template<class T>
List<T>::~List()// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
{
	if (_a)
	{
		delete[] _a;
	}
	_top = _capacity = 0;
}

int main()
{
	List<int> a;
	List<double> b;

	return 0;
}