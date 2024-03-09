#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include"hash.h"


void test1()
{
	HashClose::HashTable<int, int> h;
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

void test2()
{
	typedef HashOpen::HashTableNode<int, int> Node;
	vector<Node*> table;
	table.resize(10);
	
	Node* newnode = new Node(make_pair(2, 2));
	table[2] = newnode;
	for (auto& cur : table)
	{

	}
}

void test3()
{
	HashOpen::HashTable<int, int> hs;
	int arr[] = { 1,2,3,4,5,6,77 ,88, 99, 66, 44 };
	for (auto e : arr)
	{
		hs.Insert(make_pair(e, e));
	}
	HashOpen::HashTable<int, int> hs1 = hs;
	
}

void test4()
{
	HashOpen::HashTable<string, string> hs;

	hs.Insert(make_pair("kele", "可乐"));
	hs.Insert(make_pair("left", "左"));
	hs.Insert(make_pair("right", "右"));
	hs.Insert(make_pair("string", "字符串"));
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}