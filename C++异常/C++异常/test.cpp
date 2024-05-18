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
//	catch (const string& str) // ���������ǲ�֧�ֹ���ģ�ֻ������ƥ��
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


////double Division(int x, int y) throw(const char*) // �쳣�淶�����ǲ�ǿ�ƣ�û�м��throw����Ҳûɶ
////double Division(int x, int y) noexcept //��Ȼ�ڱ���ʱ���ᱨ��������Ĭ��Ϊ�������쳣�����в������쳣�ͻ�ֱ�ӱ��� 
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
//		throw; // �����׳��쳣
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


// �������࣬������ܣ����ö�̬
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
//		Sql_Exception p(1, "д����", "qeqawr");
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
//		// �������ϵͳ�ڴ治��Ҳ�����쳣
//		v.reserve(1000000000);
//		// ����Խ������쳣
//		v.at(10) = 100;
//	}
//	catch (const exception& e) // ���ﲶ�������Ϳ���
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}
//	return 0;
//}


// ����ָ�룬������������ڽ������Զ��������ͷſռ�
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



//double Division(int x, int y) throw(const char*) // �쳣�淶�����ǲ�ǿ�ƣ�û�м��throw����Ҳûɶ
//double Division(int x, int y) noexcept //��Ȼ�ڱ���ʱ���ᱨ��������Ĭ��Ϊ�������쳣�����в������쳣�ͻ�ֱ�ӱ��� 
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
		throw; // �����׳��쳣
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