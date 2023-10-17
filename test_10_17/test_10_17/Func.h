#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

class Stack
{
public:
	Stack(int n = 4)
	{
		_a = (int*)malloc(sizeof(int) * n);
		if (_a == nullptr)
		{
			perror("malloc error");
			exit(-1);
		}
		_size = 0;
		_capacity = n;
		cout << "Stack" << endl;
	}

	~Stack()
	{
		free(_a);
		_a = nullptr;
		_size = _capacity = 0;
		cout << "~Stack" << endl;
	}

	Stack(const Stack& x)
	{

		_size = x._size;
		_capacity = x._capacity;

		_a = (int*)malloc(sizeof(int) * _capacity);
		if (_a == nullptr)
		{
			perror("malloc error");
			exit(-1);
		}
		for (int i = 0; i < _size; ++i)
		{
			_a[i] = x._a[i];
		}
	}

	Stack& operator=(Stack& x)
	{
		_size = x._size;
		_capacity = x._capacity;

		_a = (int*)malloc(sizeof(int) * _capacity);
		if (_a == nullptr)
		{
			perror("malloc error");
			exit(-1);
		}
		for (int i = 0; i < _size; ++i)
		{
			_a[i] = x._a[i];
		}

		return *this;

	}


	void Push(int x)
	{
		if (_size == _capacity)
		{
			int* newp = (int*)realloc(_a, sizeof(int) * _capacity * 2);
			if (newp == nullptr)
			{
				perror("malloc error");
				exit(-1);
			}
			_a = newp;
			_capacity *= 2;
		}
		_a[_size++] = x;
	}

	int Pop()
	{
		assert(!Empty());

		return _a[--_size];
	}

	bool Empty()
	{
		return _size == 0;
	}

	void Print()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << _a[i] << " ";
		}
		cout << endl;
	}

private:
	int* _a;
	int _size;
	int _capacity;
};

class Queue
{
public:


	void Push(int x)
	{
		A.Push(x);
	}

	int Pop()
	{
		assert(!Empty());

		if (B.Empty())
		{
			while (!A.Empty())
			{
				B.Push(A.Pop());
			}
		}
		return B.Pop();
	}

	void Print()
	{
		Queue copy = *this;
		while (!copy.Empty())
		{
			cout << copy.Pop() << " ";
		}
		cout << endl;
	}

	bool Empty()
	{
		return A.Empty() && B.Empty();
	}

private:
	Stack A;
	Stack B;
};


class Date
{
public:

	Date(int year = 2023, int month = 10, int day = 14)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& x)
	{
		_year = x._year;
		_month = x._month;
		_day = x._day;
	}

	int MonthDay(int year, int month)
	{
		assert(0 < month < 13);

		int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0))
		{
			day[2]++;
		}
		return day[month];
	}

	Date DaysAfter1(int x)
	{
		/*Date date;
		date._year = _year;
		date._month = _month;
		date._day = _day;*/

		Date date = *this;

		int monthday = 0;
		date._day += x;
		while (date._day > (monthday = MonthDay(date._year, date._month)))
		{
			date._day -= monthday;
			date._month++;
			if (date._month == 13)
			{
				date._year++;
				date._month = 1;
			}
		}

		return date;
	}

	Date& DaysAfter(int x)
	{
		int monthday = 0;
		_day += x;
		while (_day > (monthday = MonthDay(_year, _month)))
		{
			_day -= monthday;
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}

		return *this;
	}

	/*bool operator < (const Date b)
	{
		if (_year < b._year)
		{
			return true;
		}
		else if(_year == b._year && _month < b._month)
		{
			return true;
		}
		else if (_year == b._year && _month == b._month && _day < b._day)
		{
			return true;
		}
		else
		{
			return false;
		}

	}*/

	bool operator < (const Date b)
	{
		return _year < b._year
			|| (_year == b._year && _month < b._month)
			|| (_year == b._year && _month == b._month && _day < b._day);
	}

	void Printf()
	{
		cout << _year << "" << _month << "" << _day << "" << endl;
	}
private:
	int _year = 2023;
	int _month = 10;
	int _day = 15;
};



//
//class SLNode
//{
//public:
//	SLNode(int x = 0)
//	{
//		SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
//		if (newnode == nullptr)
//		{
//			perror("malloc error");
//			exit(-1);
//		}
//		newnode->_next = nullptr;
//		newnode->_val = x;
//	}
//
//	SLNode& BuyNode(int x)
//	{
//		_val = x;
//		return *this;
//	}
//
//	~SLNode()
//	{
//		free(_next);
//		_next = nullptr;
//		_val = 0;
//		cout << "~SLNode" << endl;
//	}
//
//private:
//	int _val;
//	SLNode* _next;
//};

struct Node
{
	int _val;
	Node* _next;
};


class Slist
{
public:
	Slist()
	{
		_head = nullptr;
		_tail = nullptr;
	}

	Node* BuyNode(int x)
	{
		Node* newnode = (Node*)malloc(sizeof(Node));
		if (newnode == nullptr)
		{
			perror("malloc error");
			exit(-1);
		}
		newnode->_next = nullptr;
		newnode->_val = x;
		return newnode;
	}

	void PushBack(int x)
	{
		//Node* newnode = BuyNode(x);

		//if (!_tail)
		//{
		//	_head = _tail = newnode;
		//}
		//else
		//{
		//	_tail->_next = newnode;
		//	_tail = _tail->_next;
		//}
		Insert(_tail, x);
	}

	void PushFront(int x)
	{
		//Node* newnode = BuyNode(x);

		//if (!_head)
		//{
		//	_head = _tail = newnode;
		//}
		//else
		//{
		//	Node* temp = _head;
		//	_head = newnode;
		//	newnode->_next = temp;
		//}
		Insert(nullptr, x);
	}

	bool Empty()
	{
		return _head == NULL;
	}

	void PopBack()
	{
		//assert(!Empty());

		//if (_tail == _head)
		//{
		//	free(_head);
		//	_head = _tail = nullptr;
		//}
		//else
		//{
		//	Node* cur = _head;
		//	while (cur->_next != _tail)
		//	{
		//		cur = cur->_next;
		//	}
		//	free(_tail);
		//	_tail = cur;
		//	_tail->_next = nullptr;
		//}
		Erase(_tail);

	}

	void PopFront()
	{
		//assert(!Empty());

		//if (!_head->_next)
		//{
		//	free(_head);
		//	_head = _tail = nullptr;
		//}
		//else
		//{
		//	Node* temp = _head;
		//	_head = _head->_next;
		//	free(temp);
		//	temp = nullptr;
		//}
		Erase(_head);
	}

	void Insert(Node* pos, int x)
	{
		Node* newnode = BuyNode(x);
		if (pos == nullptr)
		{
			if (_head == nullptr)
			{
				_head = _tail = newnode;
			}
			else
			{
				Node* temp = _head;
				_head = newnode;
				_head->_next = temp;
			}
		}
		else
		{
			Node* temp = pos->_next;
			pos->_next = newnode;
			newnode->_next = temp;
			if (temp == nullptr)
			{
				_tail = newnode;
			}
		}
	}

	void Erase(Node* pos)
	{
		assert(!Empty());

		if (pos == nullptr)
		{
			return;
		}

		if (pos == _head)
		{
			if (_head == _tail)
			{
				free(pos);
				_head = _tail = nullptr;
			}
			else
			{
				Node* temp = pos->_next;
				free(pos);
				_head = temp;
			}
		}
		else
		{
			Node* temp = pos->_next;
			Node* cur = _head;
			while (cur->_next != pos)
			{
				cur = cur->_next;
			}
			free(pos);
			cur->_next = temp;
			if (temp == nullptr)
			{
				_tail = cur;
			}
		}
	}

	Node* Find(int x)
	{
		Node* cur = _head;
		while (cur && cur->_val != x)
		{
			cur = cur->_next;
		}
		if (cur)
		{
			return cur;
		}
	}

	void Destroy()
	{
		Node* cur = _head;
		while (cur)
		{
			Node* temp = cur->_next;
			free(cur);
			cur = temp;
		}
		_head = _tail = nullptr;
	}

	void Print()
	{
		Node* cur = _head;

		while (cur)
		{
			cout << cur->_val << "->";
			cur = cur->_next;
		}
		cout <<"nullptr" << endl;
	}

private:
	Node* _head;
	Node* _tail;
};



