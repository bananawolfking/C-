#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <Windows.h>
#include <mutex>
#include <time.h>
#include <condition_variable>

using namespace std;

//int main()
//{
//	thread thd1([]() {cout << "hellow word" << endl; });// 直接构造
//	thd1.join();// 一个线程如果被join了，是不是就被析构了，不是，这里线程已经销毁了，但对象还存在
//	thread thd2; // 临时线程，不会启动
//	thd2.swap(thd1); 
//	//thd2.join(); // 线程在上面已经启动过了，不会再启动，这里只是线程对象的拷贝，实际上这个对象以及没有意义，可以销毁
//
//
//	return 0;
//}

//void Print(int n, const string& name)
//{
//
//	for (int i = 0; i < n; ++i)
//	{
//		cout << name << ":" << i << endl;
//	}
//}

//int main()
//{
//	thread thd1 = thread(Print, 100, "kele"); // 线程可以创建空线程但不启动，允许移动构造
//	thread thd2 = thread(Print, 100, "C++");
//	thd1.join();
//	thd2.join();
//
//	return 0;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int i = 0;
//	vector<thread> vthd(n);
//	for (auto& th : vthd)
//	{
//		i++;
//		(th = thread(Print, 100, "name: " + to_string(i))).detach();
//	}
//	// 线程的detach是在创建的时候就做的
//	// 但是如果主线程已经退出，从线程也会退出
//	/*Sleep(5);*/
//
//	return 0;
//}
//

static void Print(int n, const string& name, int& x, mutex& mtx)
{

	for (int i = 0; i < n; ++i)
	{
		mtx.lock();
		(x)++;
		//cout << name << ":" << i << endl;
		mtx.unlock();
	}
}

//int main()
//{
//	int x = 0;
//	// 1. 临界区问题，需要加锁
//	// 2. 引用传值中间有拷贝，会有问题 ref(变量)
//	mutex mtx;
//
//	thread thd1 = thread(Print, 10000, "kele", ref(x), ref(mtx));
//	thread thd2 = thread(Print, 10000, "C++", ref(x), ref(mtx));
//
//	thd1.join();
//	thd2.join();
//
//	cout << x << endl;
//	return 0;
//}
//template<class Lock>
//class LockGuard
//{
//public:
//	LockGuard(Lock& mtx)
//		:_mtx(mtx)
//	{
//		_mtx.lock();
//	}
//
//	~LockGuard()
//	{
//		_mtx.unlock();
//	}
//
//
//private:
//	Lock& _mtx;
//};
//
//void Func()
//{
//	if (rand() % 3 == 0)
//		throw(exception("err"));
//
//}
//
//int main()
//{
//	srand((unsigned int)time(nullptr));
//	int x = 0;
//	mutex mtx;
//	// lambda表达式就不用，因为有捕捉
//	// 死锁
//	thread thd1([&](int n = 10000) {
//		try {
//			for (int i = 0; i < n; ++i)
//			{
//				LockGuard<mutex> lk(mtx); // RAII 资源获得即初始化
//				//mtx.lock();
//				(x)++;
//				Func();
//				//cout << name << ":" << i << endl;
//				//mtx.unlock();
//			}
//		}
//		catch (const exception& e)
//		{
//			cout << e.what() << endl;
//		}
//	});
//	
//	
//	thread thd2(Print, 10000, "C++", ref(x), ref(mtx));
//
//	thd1.join();
//	thd2.join();
//
//	cout << x << endl;
//	return 0;
//}

// t1打印奇数
// t2打印偶数
// 交替打印


int main()
{
	mutex mtx;
	condition_variable cond;
	int n = 0;
	thread thd1([&]() {
		while (n < 100)
		{
			unique_lock<mutex> lk(mtx); // 上锁
			if (n % 2) // 奇数
				cond.wait(lk); // 条件等待

			cout << this_thread::get_id() << ":" << n++ << endl;
			cond.notify_one();
		}
	});

	thread thd2([&]() {
		while (n < 100)
		{
			unique_lock<mutex> lk(mtx); // 上锁
			if (!(n % 2)) // 偶数
				cond.wait(lk); // 条件等待

			cout << this_thread::get_id() << ":" << n++ << endl;
			cond.notify_one();
		}
	});

	thd1.join();
	thd2.join();

	return 0;
}