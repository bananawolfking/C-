#include <iostream>
#include <cassert>

using namespace std;

#define OFFSETOF(struct_name, member_name) ((size_t)&(((struct_name*)0)->member_name))

namespace kele
{
	static void* memcpy(void* dest, const void* src, size_t num)
	{
		assert(dest && src);
		char* d = (char*)dest;
		const char* s = (const char*)src;
		while (num--)
		{
			*d++ = *s++;
		}
		return dest;
	}

	static void* memmove(void* dest, const void* src, size_t num)
	{
		assert(dest && src);
		char* d = static_cast<char*>(dest);
		const char* s = static_cast<const char*>(src);
		while (num--)
		{
			if (dest < src)
			{
				*d++ = *s++;
			}
			else
			{
				*((char*)(d + num)) = *(s + num);
			}
		}
		return dest;
	}

	// 从目的字符串中找src字符串
	static char* strstr(const char* dest, const char* src)
	{
		assert(dest && src);
		const char* left = dest, * right = dest;
		const char* cur = src;
		while (true)
		{
			while (*left != '\0' && *left != *cur) left++;
			if (*left == '\0')
				break;
			// *left == *cur
			right = left;
			while (*right == *cur)
			{
				right++;
				cur++;
				if (*cur == '\0')
					return const_cast<char*>(left);
			}
			cur = src; // cur 回执
			left++;
		}
		return nullptr;
	}

	void* memset(void* ptr, int val, size_t num)
	{
		assert(ptr);
		char* cur = static_cast<char*>(ptr);
		while (num--)
		{
			*cur++ = val;
		}
		return ptr;
	}

	int strcmp(const char* str1, const char* str2)
	{
		assert(str1 && str2);
		while (*str1 != '\0' && *str2 != '\0' && *str1++ == *str2++);
		//if (*str1 < *str2)
		//	return -1;
		//else if (*str1 > *str2)
		//	return 1;
		//else return 0;
		return *str1 - *str2;
	}
}

struct hh
{
	char name;
	int i;
};

//int main()
//{
//	//const char* ptr = "abcd";
//	//while (*ptr != '\0')
//	//{
//	//	cout << *ptr << " ";
//	//	ptr++;
//	//}
//
//	char str[] = "abcdefg";
//	char kele[] = "kele";
//	kele::memcpy(str, kele, 4);
//	cout << str << endl;
//
//	kele::memmove(str+3, str, 4);
//	cout << str << endl;
//
//	cout << kele::strstr(str, kele) << endl;
//
//	cout << (char*)kele::memset(kele, '0', 4) << endl;
//
//	cout << kele::strcmp(str, str) << endl;
//
//	cout << OFFSETOF(hh, i) << endl;
//
//	return 0;
//}


#include <stdio.h>

#define PRINT1(FORMAT, VALUE) \
	printf("the value is "FORMAT"\n", VALUE)

#define PRINT2(FORMAT, VALUE) \
	printf("the value of "#VALUE" is "FORMAT"\n", VALUE) // yes
	//printf("the value of ""VALUE"" is "FORMAT"\n", VALUE) // no

#define ADD_TO_SUM(num, value) \
	sum##num += value;


int main()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("a=%d,b=%d,c=%d\n", a, b, c); // 对齐 -1 -1 255
	printf("file:%s\n line:%d\n time:%s\n", __FILE__, __LINE__, __TIME__);
	const char* p = "hello ""bit\n"; // 字符串合并
	printf("%s\n", p);
	PRINT1("%d", 10);
	PRINT2("%d", 10);
	//ADD_TO_SUM(5, 10);//作用是：给sum5增加10.

	return 0;
}