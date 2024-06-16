#define _CRT_SECURE_NO_WARNINGS 1
 
#include <iostream>
using namespace std;
#include "SmartPtr.h"



void Test_auto_ptr()
{
	kele::auto_ptr<int> p1(new int(1));
	kele::auto_ptr<int> p2 = p1;
	kele::auto_ptr<int> p3;
	p3 = p1;
	// 资源的管理权限转移了，p1现在是nullptr
	//*p1 = 1;
}

//template<class T>
//kele::unique_ptr<T>::unique_ptr(kele::unique_ptr<T>& ptr)
//{
//
//}
//
//template<class T>
//kele::unique_ptr<T>& kele::unique_ptr<T>::operator=(kele::unique_ptr<T>& ptr)
//{
//	return *this;
//}

void Test_unique_ptr()
{
	kele::unique_ptr<int> p1(new int(1));
	//kele::unique_ptr<int> p2 = p1;
	kele::unique_ptr<int> p3;
	//p3 = p1;

	// 不允许拷贝构造和赋值
}

void Test_shared_ptr()
{
	kele::shared_ptr<int> p1(new int(1));
	kele::shared_ptr<int> p2 = p1;
	kele::shared_ptr<int> p3 = new int(2); // 编译器优化构造+拷贝构造->直接构造，所以看不出来了
	p3 = p1;

	
}

struct Node
{
	//kele::shared_ptr<Node> next;
	kele::weak_ptr<Node> next;
	int val = 0;

	~Node()
	{
		cout << "~Node" << endl;
	}
};


// 循环引用的问题
void Test_shared_ptr2()
{
	kele::shared_ptr<Node> p1 = new Node;
	kele::shared_ptr<Node> p2 = new Node;

	p1->next = p2;
	p2->next = p1;

	// 循环引用问题：
	// p1的next在指向p2后，p2空间的引用计数为2
	// p2的next在指向p1后，p1空间的引用计数为2
	// 当p1，p2析构时都会计数-1，但是因为next还指向这些空间所以，就没有释放
	// 所以就需要，另一种指针，能够指向空间，但是就不要计数，没有RAII，单纯用来指向，这样混合使用


}

// delete[] 的问题
// 构造时传参，function包装器
void Test_shared_ptr3()
{
	kele::shared_ptr<string> p1(new string[10], [](string* ptr) {delete[] ptr; });
	kele::shared_ptr<string> p2 = p1;
	kele::shared_ptr<string> p3(new string[2], [](string* ptr) {delete[] ptr; });
	p3 = p1;

	kele::shared_ptr<FILE> fp(fopen("test.txt", "r"), [](FILE* fp) {fclose(fp); });
}

#include <thread>
#include <mutex>
#include <atomic>

void Test_shared_ptr4()
{
	atomic<int> i = 0;
	int size = 10000;
	kele::shared_ptr<double> p1(new double(1.1));
	thread thd1([&]() {
		while (i < size)
		{
			kele::shared_ptr<double> copy(p1);
			i++;
			(*copy)++;
		}
		});

	thread thd2([&]() {
		while (i < size)
		{
			kele::shared_ptr<double> copy(p1);
			i++;
			(*copy)++;
		}
		});
	// 出现问题的原因是，两个线程如果同时copy shared_ptr 就会导致引用计数不准确，就有可能多次析构同一块空间
	// 所以shared_ptr 的引用计数需要是线程安全的， 但是它所指向的内容不是线程安全的
	thd1.join();
	thd2.join();
	cout << p1.use_count() << endl;
}


int main()
{
	Test_shared_ptr4();
	return 0;
}