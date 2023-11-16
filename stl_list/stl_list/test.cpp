#include"list.h"

struct AA
{
	int date1;
	int date2;

	AA(int date1 = 0, int date2 = 0)
		:date1(date1),
		date2(date2)
	{}
};


void Print(const kele::list<int>& lt)
{
	kele::list<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		//(*it)++;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test1()
{
	kele::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	Print(lt);

	lt.insert(lt.begin(), 10);
	Print(lt);
	lt.erase(lt.begin());
	Print(lt);
	lt.push_front(100);
	lt.push_back(1000);
	
	Print(lt);

	lt.pop_back();
	lt.pop_front();

	Print(lt);

}


void test2()
{
	kele::list<AA> lt;
	lt.push_back(AA(1, 1));
	lt.push_back(AA(2, 1));
	lt.push_back(AA(3, 1));
	lt.push_back(AA(4, 1));
	kele::list<AA>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << it->date1 << ":" << it->date2 << endl;
		++it;
	}
	cout << endl;
}


int main()
{
	test1();
	return 0;
}