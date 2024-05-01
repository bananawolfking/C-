#include"Date.h"

void test1()
{
	//Date a;
	//Date b(1,1,1);
	//b = a;
	//a = b + 5000;
	//cout <<( a != b ) << endl;
	//a.Print();
	//b.Print();
	//cout << a - b << endl;
	//a++;
	//a.Print();
	//b.Print();

	Date a(2003, 1, 5);
	Date b(2023, 10, 18);
	cout << a << endl;
	cout << b << endl;

	cout << b - a << endl;
	
	
	cout << (a - -500) << endl;
	cout << b << endl;
	cout << "ÎÒÕæNB" << endl;
}

void test2()
{
	Date a;
	cout << a << endl;

	cin >> a;
	cout << a << endl;
}

int main()
{
	test2();
	return 0;
}