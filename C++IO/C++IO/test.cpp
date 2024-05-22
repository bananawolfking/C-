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
	string _address;
	double _x;
	Date _date;
};

ostream& operator << (ostream& out, const ServerInfo& d)
{
	out << d._address << " " << d._date << " " << d._date << endl;

	return out;
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


int main()
{
	BinIO bio;
	ServerInfo info = { {"https://legacy.cplusplus.com/reference/fstream/ofstream/close/"},
		{123.456}, {2024,5,22} };
	bio.write(info);

	ServerInfo output;
	bio.read(output);

	cout << output << endl;
	// ��Ϊstring�����е�ָ��ָ��ѿռ䣬���ͷ����� ���ʣ�ǳ����
	// ����������ı���д���ַ���IO ���л�/�����л�

	return 0;
}