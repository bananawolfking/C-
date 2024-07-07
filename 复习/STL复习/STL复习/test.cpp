#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
#include <list>

#include "my_string.h"


//// 剪去报头 length\r\n*******\r\nlength\r
//std::string Decode(std::string& str)
//{
//	// 判断条件是否满足，不满足返回空串
//	size_t pos = str.find(SEP);
//	if (pos == std::string::npos)
//		return "";
//	size_t lenght = atoi(str.substr(0, pos).c_str());
//
//	if (lenght > str.size() - pos - SEP_LEN * 2)
//		return "";
//
//	str.erase(0, pos + SEP_LEN);
//	std::string ret = str.substr(0, lenght);
//	str.erase(0, lenght + SEP_LEN);
//	return ret;
//}

//template<class T>
//class vector
//{
//public:
//	typedef T* iterator;
//	typedef const T* const_iterator;
//private:
//	iterator _start = nullptr;
//	iterator _finish = nullptr;
//	iterator _end_of_storage = nullptr;
//};

using namespace std;

//int main()
//{
//	//list<int> lt;
//	//lt.push_back(1);
//	//lt.push_back(1);
//	//lt.push_back(1);
//	//lt.push_back(1);
//	//lt.push_back(1);
//
//	//auto it = lt.begin();
//	//it++;
//	kele::string str = "nihao";
//	kele::string str1("kele");
//	cout << (str1 += str) << endl;
//	cout << (str += str1).c_str() << endl;
//
//	int size = str.size();
//	for (int i = 0; i < size; ++i)
//	{
//		str[i] = 'k';
//	}
//	cout << str << endl;
//
//	return 0;
//}

//#include "my_vector.h"
//
//int main()
//{
//	kele::vector<int> v(5, 0);
//	kele::vector<int> v1 = v;
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//	v1.push_back(5);
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//	v1.pop_back();
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//	v1.insert(v1.begain(), 6);
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//	v1.erase(v1.begain());
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//template<class T>
//struct list_node
//{
//	typedef list_node<T> node;
//	node* _next;
//	node* _prev;
//	T _date;
//};
//
//template<class T, class Ref, class Ptr>
//struct __list_iterator
//{
//	typedef list_node<T> node;
//	typedef __list_iterator<T, Ref, Ptr> self;
//	node* _it;
//};
//
//template<class T>
//class list
//{
//	typedef list_node<T> node;
//public:
//	typedef __list_iterator<T, T&, T*> iterator;
//	typedef __list_iterator<T, const T&, const T*> const_iterator;
//private:
//	node* _head;
//};

#include "my_list.h"

int main()
{
	kele::list<int> lt;
	auto it = lt.begin();
	lt.insert(it, 1);

	auto begin = lt.begin();
	auto end = lt.end();

	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.push_back(3);
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.push_front(2);
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_back();
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_front();
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;


	return 0;
}