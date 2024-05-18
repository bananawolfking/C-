#include <iostream>
#include <string>

using namespace std;

//double Division(int x, int y)
//{
//	if (y == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	else
//	{
//		return (double)x / y;
//	}
//}
//
//void func()
//{
//	int x, y;
//	cin >> x >> y;
//	double ret = Division(x, y);
//	cout << ret << endl;
//	cout << "Division sucess" << endl;
//}
//
//int main()
//{
//	try
//	{
//		while (true)
//		{
//			func();
//		}
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//
//	return 0;
//}


//double Division(int x, int y)
//{
//	if (y == 0)
//	{
//		throw string("Division by zero condition!");
//	}
//	else
//	{
//		return (double)x / y;
//	}
//}
//
//void func()
//{
//	int x, y;
//	cin >> x >> y;
//	try {
//		double ret = Division(x, y);
//		cout << ret << endl;
//		cout << "Division sucess" << endl;
//	}
//	catch (const string& str) // 返回类型是不支持构造的，只有类型匹配
//	{
//		cout << str << endl;
//	}
//
//}
//
//int main()
//{
//	//try
//	//{
//	//	while (true)
//	//	{
//	//		func();
//	//	}
//	//}
//	//catch (const char* str)
//	//{
//	//	cout << str << endl;
//	//}
//
//	while (true)
//	{
//		func();
//	}
//
//
//	return 0;
//}


////double Division(int x, int y) throw(const char*) // 异常规范，但是不强制，没有检测throw（）也没啥
////double Division(int x, int y) noexcept //虽然在编译时不会报错，但是它默认为不会有异常，所有产生了异常就会直接崩溃 
//double Division(int x, int y)
//{
//	if (y == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	else
//	{
//		return (double)x / y;
//	}
//}
//
//void func()
//{
//	int* ptr = new int[4];
//	int x, y;
//	cin >> x >> y;
//	try {
//		double ret = Division(x, y);
//		cout << ret << endl;
//		cout << "Division sucess" << endl;
//	}
//	catch (...) 
//	{
//		delete[] ptr;
//		throw; // 重新抛出异常
//	}
//
//}
//
//int main()
//{
//	try
//	{
//		while (true)
//		{
//			func();
//		}
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//
//
//	return 0;
//}


// 传派生类，基类接受，利用多态
//class Exception
//{
//public:
//	Exception(size_t errid, const string& errmsg)
//		:_errid(errid),
//		_errmsg(errmsg)
//	{}
//
//	virtual string what() const
//	{
//		return _errmsg;
//	}
//protected:
//	size_t _errid;
//	string _errmsg;
//};
//
//class Sql_Exception : public Exception
//{
//public:
//	Sql_Exception(size_t id, const string& errmsg, const string& sql)
//		:Exception(id,errmsg),
//		_sql(sql)
//	{}
//
//	virtual string what() const
//	{
//		string str;
//		str += _errmsg;
//		str += " : ";
//		str += _sql;
//		return str;
//	}
//
//private:
//	string _sql;
//};
//
//int main()
//{
//	try {
//		Sql_Exception p(1, "写错了", "qeqawr");
//		throw p;
//	}
//	catch (Exception& str)
//	{
//		cout << str.what() << endl;
//	}
//	
//
//	return 0;
//}

//#include <vector>
//
//int main()
//{
//	try {
//		vector<int> v(10, 5);
//		// 这里如果系统内存不够也会抛异常
//		v.reserve(1000000000);
//		// 这里越界会抛异常
//		v.at(10) = 100;
//	}
//	catch (const exception& e) // 这里捕获父类对象就可以
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}
//	return 0;
//}


// 智能指针，对象的生命周期结束会自动析构，释放空间
template<class T>
class SmartPtr
{
public:
	SmartPtr(const T ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		delete[] _ptr;
		cout << "delete[] _ptr" << endl;
	}

private:
	T _ptr;
};



//double Division(int x, int y) throw(const char*) // 异常规范，但是不强制，没有检测throw（）也没啥
//double Division(int x, int y) noexcept //虽然在编译时不会报错，但是它默认为不会有异常，所有产生了异常就会直接崩溃 
double Division(int x, int y)
{
	if (y == 0)
	{
		throw "Division by zero condition!";
	}
	else
	{
		return (double)x / y;
	}
}

void func()
{
	int* ptr = new int[4];
	SmartPtr<int*> p(ptr);
	SmartPtr<int*> p1(new int[10]);
	int x, y;
	cin >> x >> y;
	try {
		double ret = Division(x, y);
		cout << ret << endl;
		cout << "Division sucess" << endl;
	}
	catch (...) 
	{
		throw; // 重新抛出异常
	}

}

int main()
{
	try
	{
		while (true)
		{
			func();
		}
	}
	catch (const char* str)
	{
		cout << str << endl;
	}


	return 0;
}