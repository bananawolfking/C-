#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a;
	string b = "abcdefg";
	string c = "hello word";
	string d = c;

	cout << c.size() << endl;
	cout << c.capacity() << endl;
	c.resize(5, '0');
	cout << c << b << d << endl;
	for (auto x : c)
	{
		cout << x << " ";
	}
	cout << endl;

	for (int i = 0; i < c.size(); ++i)
	{
		cout << c[i];
	}
	cout << endl;

	c.push_back(' ');
	c.append("word");
	cout << c << endl;

	c.resize(5, ' ');
	c += " word";
	cout << c << endl;

	return 0;
}