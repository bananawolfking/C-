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
//	thread thd1([]() {cout << "hellow word" << endl; });// ֱ�ӹ���
//	thd1.join();// һ���߳������join�ˣ��ǲ��Ǿͱ������ˣ����ǣ������߳��Ѿ������ˣ������󻹴���
//	thread thd2; // ��ʱ�̣߳���������
//	thd2.swap(thd1); 
//	//thd2.join(); // �߳��������Ѿ��������ˣ�����������������ֻ���̶߳���Ŀ�����ʵ������������Լ�û�����壬��������
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
//	thread thd1 = thread(Print, 100, "kele"); // �߳̿��Դ������̵߳��������������ƶ�����
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
//	// �̵߳�detach���ڴ�����ʱ�������
//	// ����������߳��Ѿ��˳������߳�Ҳ���˳�
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
//	// 1. �ٽ������⣬��Ҫ����
//	// 2. ���ô�ֵ�м��п������������� ref(����)
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
//	// lambda���ʽ�Ͳ��ã���Ϊ�в�׽
//	// ����
//	thread thd1([&](int n = 10000) {
//		try {
//			for (int i = 0; i < n; ++i)
//			{
//				LockGuard<mutex> lk(mtx); // RAII ��Դ��ü���ʼ��
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

// t1��ӡ����
// t2��ӡż��
// �����ӡ


int main()
{
	mutex mtx;
	condition_variable cond;
	int n = 0;
	thread thd1([&]() {
		while (n < 100)
		{
			unique_lock<mutex> lk(mtx); // ����
			if (n % 2) // ����
				cond.wait(lk); // �����ȴ�

			cout << this_thread::get_id() << ":" << n++ << endl;
			cond.notify_one();
		}
	});

	thread thd2([&]() {
		while (n < 100)
		{
			unique_lock<mutex> lk(mtx); // ����
			if (!(n % 2)) // ż��
				cond.wait(lk); // �����ȴ�

			cout << this_thread::get_id() << ":" << n++ << endl;
			cond.notify_one();
		}
	});

	thd1.join();
	thd2.join();

	return 0;
}