#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include"hashtable.h"
#include"unorderedset.h"
#include"unorderedmap.h"


void test_map1()
{
	kele::unorder_map<int, int> m;
	int arr[] = { 1, 2, 3, 4,5,55,15,46,66 ,1,22,2,2,55};
	for (auto e : arr)
	{
		//m.insert(make_pair(e,e));
		m[e]++;
	}

	//kele::unorder_map<int, int>::iterator it = m.begin();
	//while (it != m.end())
	//{
	//	cout << it->first << ":" << it->second << endl;
	//	++it;
	//}

	for (auto it : m)
	{
		cout << it.first << ":" << it.second << endl;
	}

}

class Date
{
	friend struct HashFunc;
	friend ostream& operator<<(ostream& out, const Date& x);
public:

	Date(int year, int month, int day)
		:_year(year),
		_month(month),
		_day(day)
	{}

	bool operator==(const Date x) const
	{
		return _year == x._year
			&& _month == x._month
			&& _day == x._day;
	}


private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& x)
{
	out << x._year << "/" << x._month << "/" << x._day;
	return out;
}

struct HashFunc
{
	size_t operator()(const Date* date)
	{
		size_t ret = 0;
		ret = (ret + date->_year) * 31;
		ret = (ret + date->_month) * 31;
		ret = (ret + date->_day) * 31;

		return ret;
	}
};

struct Equal
{
	bool operator()(const Date* date1, const Date* date2)
	{
		return *date1 == *date2;
	}
};

void test_map2()
{
	kele::unorder_map<Date*, int, HashFunc, Equal> m;
	Date d1(2024, 3, 10);
	Date d2(2024, 3, 11);
	Date d3(2024, 3, 10);
	Date d4(2024, 3, 12);
	Date d5(2024, 3, 12);

	Date* a[] = { &d1,&d2,&d3,&d4,&d5 };
	for (auto e : a)
	{
		m[e]++;
	}

	for (auto e : m)
	{
		cout << *(e.first) << ":" << e.second << endl;
	}
}

template<class K>
void print(const kele::unorder_set<int>& s)
{
	for (auto& e : s)
	{
		//e++;
		cout << e << " ";
	}
}

void test_set1()
{
	kele::unorder_set<int> s;
	int arr[] = { 1, 2, 3, 4,5,55,15,46,66 ,1,22,2,2,55 };
	for (auto e : arr)
	{
		s.insert(e);
	}
	print<int>(s);
}

template<class K, class V>
void print(const kele::unorder_map<int, int>& m)
{
	for (auto& e : m)
	{
		//e.second++;
		cout << e.first << ":" << e.second << " ";
	}
}

int main()
{
	//test_map1();
	//test_map2();
	test_set1();
	return 0;
}