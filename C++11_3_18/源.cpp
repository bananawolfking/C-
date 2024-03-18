#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//struct Point
//{
//	int x;
//	int y;
//};
//
//int main()
//{
//
//	int arr1[]{ 1, 2, 3 };
//	int arr2[2]{ 0 };
//	Point p{ 1, 2 };
//
//	int* ptr = new int[4] {0};
//	return 0;
//}

//class Date
//{
//public:
//	Date(size_t year, size_t month, size_t day)
//		:_year(year),
//		_month(month),
//		_day(day)
//	{}
//private:
//	size_t _year;
//	size_t _month;
//	size_t _day;
//};
//
//int main()
//{
//	Date d1(2024, 3, 18);
//	Date d2 = { 2024, 3, 18 };
//	Date d2{ 2024, 3, 18 };
//	return 0;
//}

//#include<list>
//#include<string>
//#include<map>
//#include<vector>
//
//int main()
//{
//	auto il = { 1,2,3 };
//	cout << typeid(il).name() << endl;
//	initializer_list<int> il2 = { 1,2,3 };
//
//	list<int> lt = { 1,2,3 };
//	initializer_list<char> il4 = { 'a', 'b', 'c' };
//	string s = { 'a', 'b', 'c' };
//	string s2 = { "hello word"};
//
//	initializer_list<const char*> il3 = { "hello word" , "abc"};
//
//	map<int, int> m = { make_pair(1,1), make_pair(2,2) ,make_pair(3,3) };
//	return 0;
//}


//namespace kele
//{
//    template<class T>
//    class vector {
//    public:
//        typedef T* iterator;
//        iterator begin(){return _start;}
//        iterator end(){return _finish;}
// 
//        vector(initializer_list<T> l)
//        {
//            _start = new T[l.size()];
//            _finish = _start + l.size();
//            _endofstorage = _start + l.size();
//            iterator vit = _start;
//            
//            for (auto e : l)
//               *vit++ = e;
//        }
//        vector<T>& operator=(initializer_list<T> l) {
//            vector<T> tmp(l);
//            swap(_start, tmp._start);
//            swap(_finish, tmp._finish);
//            swap(_endofstorage, tmp._endofstorage);
//            return *this;
//        }
//    private:
//        iterator _start;
//        iterator _finish;
//        iterator _endofstorage;
//    };
//}
//
//int main()
//{
//    kele::vector<int> v = { 1,2,3 };
//    for (auto e : v)
//    {
//        cout << e << endl;
//    }
//    return 0;
//}


//template <typename _Tx, typename _Ty>
//auto multiply(_Tx x, _Ty y)
//{
//	return x * y;
//}
//
//int main()
//{
//	int x = 1;
//	char y = 'a';
//	decltype(x * y) z;//z int
//	cout << typeid(z).name() << endl;
//
//	double a = 0.25;
//	decltype(multiply(a, x)) m;//m double
//	cout << typeid(m).name() << endl;
//
//	return 0;
//}



//int main()
//{
//	// 以下的p、b、c、*p都是左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//
//	// 以下几个是对上面左值的左值引用
//	int*& rp = p;
//	int& rb = b;
//	const int& rc = c;
//	int& pvalue = *p;
//	return 0;
//}

//int main()
//{
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
//	10 = 1;
//	x + y = 1;
//	fmin(x, y) = 1;
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	int& z = x;//左值引用
//	int&& y = 10;//右值引用
//
//	int&& yy = move(x);//右值引用左值
//	const int& xx = 10;//左值引用右值
//	return 0;
//}


#include"string.h"


//int main()
//{
//	kele::string s1 = "hello word";
//	kele::string s2 = (s1 + "!");
//	kele::string s3 = s2;
//	return 0;
//}

void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }

void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }

template<typename T>
void PerfectForward(T&& t)
{
	Fun(forward<T>(t));
}
int main()
{
	PerfectForward(10);           // 右值
	int a;
	PerfectForward(a);            // 左值
	PerfectForward(std::move(a)); // 右值
	const int b = 8;
	PerfectForward(b);      // const 左值
	PerfectForward(std::move(b)); // const 右值
	return 0;
}