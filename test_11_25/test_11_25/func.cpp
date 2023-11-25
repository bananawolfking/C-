#include"func.h"

template<class T>
T Add(const T& a, const T& b)
{
	return a + b;
}

template
int Add<int>(const int& a, const int& b);