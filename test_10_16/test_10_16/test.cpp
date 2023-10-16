#include"Date.h"

void test1()
{
	Date a;
	Date b(1,1,1);
	b = a;
	a = b + 500;
	cout <<( a != b ) << endl;
	a.Print();
	b.Print();
	cout << b - b << endl;
	a++;
	a.Print();
	b.Print();

	cout << "ÎÒÕæNB" << endl;
}

int main()
{
	test1();
	return 0;
}