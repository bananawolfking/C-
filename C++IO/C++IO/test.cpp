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
	friend istream& operator >> (istream& in, ServerInfo& d);
	string _address;
	double _x;
	Date _date;
};

ostream& operator << (ostream& out, const ServerInfo& d)
{
	out << d._address << " " << d._x << " " << d._date << endl;

	return out;
}

istream& operator >> (istream& in, ServerInfo& d)
{
	in >> d._address >> d._x >> d._date;

	return in;
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


//int main()
//{
//	BinIO bio;
//	ServerInfo info = { {"https://legacy.cplusplus.com/reference/fstream/ofstream/close/"},
//		{123.456}, {2024,5,22} };
//	bio.write(info);
//
//	ServerInfo output;
//	bio.read(output);
//
//	cout << output << endl;
//	// 因为string类型中的指针指向堆空间，会释放两次 本质：浅拷贝
//	// 明天继续：文本读写和字符串IO 序列化/反序列化
//
//	return 0;
//}

//int main()
//{
//	ServerInfo info = { {"https://legacy.cplusplus.com/reference/fstream/ofstream/close/"},
//				{123.456}, {2024,5,22} };
//	ofstream ofs("file.txt", ofstream::out | ofstream::binary);
//	ofs.write((char*)&info, sizeof(info));
//	ofs.close(); // 缓冲区刷新
//
//	ServerInfo out;
//	ifstream ifs("file.txt", ifstream::in | ifstream::binary);
//	ifs.read((char*)&out, sizeof out);
//	cout << out << endl;
//
//	return 0;
//}

//int main()
//{
//	ServerInfo info = { {"https://legacy.cplusplus.com/reference/fstream/ofstream/close/"},
//				{123.456}, {2024,5,22} };
//	fstream fs("file.txt", fstream::in | fstream::out | fstream::binary);
//	fs.write((char*)&info, sizeof(info));
//	fs.flush();
//	fs.seekg(0, ios::beg);// 文件指针移到开头处 g读指针，p写指针
//	ServerInfo out;
//	fs.read((char*)&out, sizeof out);
//	cout << out << endl;
//
//	return 0;
//}


//int main()
//{
//	//ServerInfo info = { {"https://legacy.cplusplus.com/reference/fstream/ofstream/close/"},
//	//			{123.456}, {2024,5,22} };
//	//ofstream ofs("file.txt", ofstream::out | ofstream::binary);
//	//ofs.write((char*)&info, sizeof(info));
//	//ofs.close(); // 缓冲区刷新
//
//	ServerInfo out; // 二进制读的指针地址是野指针
//	ifstream ifs("file.txt", ifstream::in | ifstream::binary);
//	ifs.read((char*)&out, sizeof out);
//	cout << out << endl;
//
//	return 0;
//}

// 文本读写方式
class TextIO
{
public:
	TextIO(const char* filename = "file.txt")
		:_filename(filename)
	{}

	void write(const ServerInfo& in)
	{
		ofstream ofs(_filename);
		ofs << in << endl;
	}

	void read(ServerInfo& out)
	{
		ifstream ifs(_filename);
		ifs >> out;
	}

private:
	string _filename;
};

//int main()
//{
//	TextIO tio;
//	ServerInfo info = { {"https://legacy.cplusplus.com/reference/fstream/ofstream/close/"},
//			{123.456}, {2024,5,22} };
//	tio.write(info);
//
//	ServerInfo out;
//	tio.read(out);
//	cout << out << endl;
//}

 // C++ 利用重载<<>>可以方便自定义类型的文本读写
//int main()
//{
//	fstream fs("file.txt");
//	ServerInfo info = { {"https://legacy.cplusplus.com/reference/fstream/ofstream/close/"},
//			{123.456}, {2024,5,22} };
//	fs << info._address << endl;
//	fs << info._x << endl;
//	fs << info._date << endl;
//	fs.seekg(0, ios::beg);
//	ServerInfo out;
//	fs >> out._address >> out._x >> out._date;
//	cout << out << endl;
//}

//int main()
//{
//	fstream fs("file.txt");
//	ServerInfo info = { {"https://legacy.cplusplus.com/reference/fstream/ofstream/close/"},
//			{123.456}, {2024,5,22} };
//	fs << info << endl;
//	fs.seekg(0, ios::beg);
//	ServerInfo out;
//	fs >> out;
//	cout << out << endl;
//}


// 字符串载入
struct ChatInfo
{
	string _name; // 名字
	int _id;      // id
	Date _date;   // 时间
	string _msg;  // 聊天信息
};

ostream& operator << (ostream& out, const ChatInfo& d)
{
	out << d._name << " " << d._id << " " << d._date << " " << d._msg << endl;

	return out;
}

istream& operator >> (istream& out, ChatInfo& d)
{
	out >> d._name >> d._id >> d._date >> d._msg;

	return out;
}

//int main()
//{
//	ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧" };
//	stringstream ss;
//	ss << winfo;
//
//	ss.seekg(0, ios::beg);
//
//	ChatInfo out;
//	ss >> out;
//	cout << out << endl;
//
//	return 0;
//}

int main()
{
	ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧" };
	ostringstream oss;
	oss << winfo;

	string str = oss.str();
	istringstream iss(oss.str());
	ChatInfo out;
	iss >> out;
	cout << out << endl;

	return 0;
}
