#include<iostream>
using std::cout;
using std::endl;

template <class T>
struct MyIter {
    typedef T value_type;
    T* ptr;

    MyIter(T* p) {
        ptr = p;
    }

    T& operator*() {
        return *ptr;
    }
};

template <class I>
typename I::value_type
func(I ite) {	// typename I::value_type 为返回值类型
    return *ite;
}

int main()
{
    MyIter<int> ite(new int(1231));
    cout << func(ite);
    return 0;
}


//#include"func.h"
//
//int main()
//{
//	int a = 1, b = 2;
//	int ret = Add(a, b);
//	return 0;
//}