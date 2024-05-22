#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	operator int()
	{
		return _year + _month + _day;
	}
	operator bool()
	{
		return _year;
	}
private:
	int _year;
	int _month;
	int _day;
};

istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

//ofs << winfo._date;
ostream& operator << (ostream& out, const Date& d)
{
	//out << d._year << "年" << d._month << "月" << d._day<<"日";
	//out << d._year << "/" << d._month << "/" << d._day;
	out << d._year << " " << d._month << " " << d._day;

	return out;
}

// 内置类型 <- 自定义类型
//int main()
//{
//	Date d(0,1,1);// 匹配最合适的bool
//	int x = d;
//	if(d)
//		cout << x << endl;
//}
//
//// 自定义类型重载<<和>>需要自己实现

// c++流和c语言的同步问题
//int main()
//{
//	printf("nihao\n");
//	cout.sync_with_stdio();
//	cout << "nihao" << endl;
//}


struct ServerInfo
{
	friend ostream& operator << (ostream& out, const ServerInfo& d);
	string _address;
	double _x;
	Date _date;
};

ostream& operator << (ostream& out, const ServerInfo& d)
{
	out << d._address << " " << d._date << " " << d._date << endl;

	return out;
}


// 文件的二进制读写

class BinIO
{
public:
	BinIO(const string& name = "file.txt")
		:_filename(name)
	{}

	void write(const ServerInfo& in)
	{
		ofstream ofs;
		ofs.open(_filename.c_str(), ofstream::out | ofstream::binary);
		ofs.write((char*)&in, sizeof(in));
		// ofs.close();// 对象析构会自动关闭
	}

	void read(ServerInfo& out)
	{
		ifstream ifs(_filename.c_str(), ifstream::in | ifstream::binary);
		ifs.read((char*)&out, sizeof out);
	}

private:
	string _filename;
};


int main()
{
	BinIO bio;
	ServerInfo info = { {"https://legacy.cplusplus.com/reference/fstream/ofstream/close/"},
		{123.456}, {2024,5,22} };
	bio.write(info);

	ServerInfo output;
	bio.read(output);

	cout << output << endl;
	// 因为string类型中的指针指向堆空间，会释放两次 本质：浅拷贝
	// 明天继续：文本读写和字符串IO 序列化/反序列化

	return 0;
}