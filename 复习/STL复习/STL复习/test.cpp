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

int main()
{
	//list<int> lt;
	//lt.push_back(1);
	//lt.push_back(1);
	//lt.push_back(1);
	//lt.push_back(1);
	//lt.push_back(1);

	//auto it = lt.begin();
	//it++;
	kele::string str = "nihao";
	kele::string str1("kele");
	cout << (str1 += str) << endl;
	cout << (str += str1).c_str() << endl;

	return 0;
}