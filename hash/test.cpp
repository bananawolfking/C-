#include<iostream>
#include<vector>
using namespace std;
#include"hash.h"


void test1()
{
	Hash<int, int> h;
	int arr[] = { 1,2,3,4,5,6,77 ,88, 99, 66, 44};
	for (auto e : arr)
	{
		h.Insert(make_pair(e, e));
	}
	auto x = h.Find(77);
	if (x)
		cout << "77存在" << endl;
	else
		cout << "77不存在" << endl;
	h.Erase(77);
	auto a = h.Find(77);
	if (a)
		cout << "77存在" << endl;
	else
		cout << "77不存在" << endl;
}


int main()
{
	test1();

	return 0;
}