#include<iostream>
using namespace std;
#include"Bitmap.h"

int main()
{
	kele::bitset<20> s;
	s.set(1);
	s.set(2);
	s.set(3);
	s.set(4);
	s.set(5);
	s.reset(5);
	cout << s.test(5);
	cout << s.test(6);

	return 0;
}