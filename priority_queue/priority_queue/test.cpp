#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

#include"priority_queue.h"
#include"list.h"
#include"vector.h"

void test1()
{
	kele::priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(1);
	pq.push(7);
	pq.push(4);
	pq.push(6);
	pq.push(9);
	pq.push(8);
	pq.push(0);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

void test2()
{
	int arr[] = { 1,7,4,6,9,8,0 };
	//vector<int> arr1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	kele::priority_queue<int> pq(arr, arr + sizeof(arr) / sizeof(arr[0]));
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

void test3()
{
	int arr[] = { 1,7,4,6,9,8,0 };
	const kele::list<int> t(arr, arr + 7);

	kele::list<int>::const_reverse_iterator rit = t.rbegin();
	while (rit != t.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	kele::vector<int> v(arr, arr + 7);
	kele::vector<int>::reverse_iterator rrit = v.rbegin();
	while (rrit != v.rend())
	{
		cout << *rrit << " ";
		++rrit;
	}
	cout << endl;
}

struct s
{
	s(int date1 = 0, int date2 = 0)
		:_date1(date1),
		_date2(date2)
	{}

	int _date1;
	int _date2;
};

void test4()
{
	kele::vector<s> v;
	v.push_back(s(1, 2));
	v.push_back(s(2, 3));
	kele::vector<s>::reverse_iterator rrit = v.rbegin();
	while (rrit != v.rend())
	{
		cout << rrit->_date1 << " " << rrit->_date2 << endl;
		++rrit;
	}
	cout << endl;
}

void test5()
{
	int arr[] = { 1,7,4,6,9,8,0 };
	kele::list<int> t(arr, arr + 7);

	kele::list<int>::const_iterator rit = t.begin();
	while (rit != t.end())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	kele::vector<int> v(arr, arr + 7);
	kele::vector<int>::reverse_iterator rrit = v.rbegin();
	while (rrit != v.rend())
	{
		cout << *rrit << " ";
		++rrit;
	}
	cout << endl;
}


int main()
{
	test5();
	return 0;
}