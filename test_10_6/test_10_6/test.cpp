#include<iostream>

using namespace std;

int Add(int a, int b)
{
	cout << "int Add(int a, int b)" << endl;
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

	return 0;
}