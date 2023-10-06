

#include"test.h"

//using namespace std;

using namespace kele;

int Add(int a, int b)
{
	std :: cout << "int Add(int a, int b)" << std :: endl;
	return a + b;
}

double Add(double a, double b)
{
	cout << "double Add(double a, double b)" << endl;
	return a + b;
}

int main()
{
	cout << "hellow word" << endl;

	cout << Add(1, 2) << endl;
	cout << Add(1.1, 2.2) << endl;
	double x = 1.5;
	double y = 5.5;
	//cin >> x;
	Swap(x, y);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	Print(0);

	return 0;
}