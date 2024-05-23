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
	//out << d._year << "��" << d._month << "��" << d._day<<"��";
	//out << d._year << "/" << d._month << "/" << d._day;
	out << d._year << " " << d._month << " " << d._day;

	return out;
}

// �������� <- �Զ�������
//int main()
//{
//	Date d(0,1,1);// ƥ������ʵ�bool
//	int x = d;
//	if(d)
//		cout << x << endl;
//}
//
//// �Զ�����������<<��>>��Ҫ�Լ�ʵ��

// c++����c���Ե�ͬ������
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


// �ļ��Ķ����ƶ�д

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
		// ofs.close();// �����������Զ��ر�
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
//	// ��Ϊstring�����е�ָ��ָ��ѿռ䣬���ͷ����� ���ʣ�ǳ����
//	// ����������ı���д���ַ���IO ���л�/�����л�
//
//	return 0;
//}

//int main()
//{
//	ServerInfo info = { {"https://legacy.cplusplus.com/reference/fstream/ofstream/close/"},
//				{123.456}, {2024,5,22} };
//	ofstream ofs("file.txt", ofstream::out | ofstream::binary);
//	ofs.write((char*)&info, sizeof(info));
//	ofs.close(); // ������ˢ��
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
//	fs.seekg(0, ios::beg);// �ļ�ָ���Ƶ���ͷ�� g��ָ�룬pдָ��
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
//	//ofs.close(); // ������ˢ��
//
//	ServerInfo out; // �����ƶ���ָ���ַ��Ұָ��
//	ifstream ifs("file.txt", ifstream::in | ifstream::binary);
//	ifs.read((char*)&out, sizeof out);
//	cout << out << endl;
//
//	return 0;
//}

// �ı���д��ʽ
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

 // C++ ��������<<>>���Է����Զ������͵��ı���д
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


// �ַ�������
struct ChatInfo
{
	string _name; // ����
	int _id;      // id
	Date _date;   // ʱ��
	string _msg;  // ������Ϣ
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
//	ChatInfo winfo = { "����", 135246, { 2022, 4, 10 }, "����һ�𿴵�Ӱ��" };
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
	ChatInfo winfo = { "����", 135246, { 2022, 4, 10 }, "����һ�𿴵�Ӱ��" };
	ostringstream oss;
	oss << winfo;

	string str = oss.str();
	istringstream iss(oss.str());
	ChatInfo out;
	iss >> out;
	cout << out << endl;

	return 0;
}
