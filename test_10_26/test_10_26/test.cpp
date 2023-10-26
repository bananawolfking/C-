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
//	// 动态申请一个int类型的空间
//	int* p1 = new int;
//
//	// 动态申请10个int类型的空间
//	int* p2 = new int[10];
//
//	// 动态申请一个int类型的空间并初始化为1
//	int* p3 = new int{ 1 };
//
//	// 动态申请10个int类型的空间并初始化
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
//    //Add(a1, a2);//调用非模板函数
//    //Add(d1, d2);
//    //Add(a1, (int)d1);
//    //Add<int>(a1, d1);//调用模板的
//    Add(1, 2);     // 与非函数模板类型完全匹配，不需要函数模板实例化
//    Add(1.0, 2.0);   // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
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

	~List(); // 使用析构函数演示：在类中声明，在类外定义。

private:
	T* _a;
	int _top;
	int _capacity;
};

template<class T>
List<T>::~List()// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
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