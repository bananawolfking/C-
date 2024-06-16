#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <Windows.h>
#include <mutex>
#include <time.h>
#include <condition_variable>
#include <atomic>

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


//int main()
//{
//	mutex mtx;
//	condition_variable cond;
//	int n = 0;
//	thread thd1([&]() {
//		while (n < 100)
//		{
//			unique_lock<mutex> lk(mtx); // ����
//			if (n % 2) // ����
//				cond.wait(lk); // �����ȴ�
//
//			cout << this_thread::get_id() << ":" << n++ << endl;
//			cond.notify_one();
//		}
//	});
//
//	thread thd2([&]() {
//		while (n < 100)
//		{
//			unique_lock<mutex> lk(mtx); // ����
//			if (!(n % 2)) // ż��
//				cond.wait(lk); // �����ȴ�
//
//			cout << this_thread::get_id() << ":" << n++ << endl;
//			cond.notify_one();
//		}
//	});
//
//	thd1.join();
//	thd2.join();
//
//	return 0;
//}

//int main()
//{
//	mutex mtx;
//	condition_variable cond;
//	bool flag = true;
//	int n = 0;
//	thread thd1([&]() {
//		while (n < 100)
//		{
//			unique_lock<mutex> lk(mtx); // ����
//			while (flag) // ����
//				cond.wait(lk);
//			// �����ȴ�
//			if (n >= 100)
//				break;
//			cout << this_thread::get_id() << "-1" << ":" << n++ << endl;
//			flag = true;
//			cond.notify_one();
//		}
//	});
//	// ���ӡ[0, 100]��
//	// ��n==98ʱ���߳�2�õ������߳�1���������������������������ĵȴ�������
//	// �߳�2��ӡ���n == 99���߳�һ�õ�������������������
//	// �߳�2�����������������õ������������������㣬�Զ��ͷ����������������������߳�2һ����while��
//	// ��������߳�2��while�ж�ǰ��ʱ��Ƭ���Ѿ����ˣ��ͻ����[0, 99]�����ʱ���߳�1����������ִ�еģ�n���100��
//	// �����ǰ������������߳�2�ͻ���whileѭ���У�[0, 100]
//	// 
//	thread thd2([&]() {
//		while (n < 100)
//		{
//			unique_lock<mutex> lk(mtx); // ����
//			while (!flag) // ż��
//				cond.wait(lk);
//			// �����ȴ�
//			if (n >= 100)
//				break;
//			cout << this_thread::get_id() << "-2" << ":" << n++ << endl;
//			flag = false;
//			cond.notify_one();
//		}
//	});
//
//	thd1.join();
//	thd2.join();
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	int size = 10000;
//	mutex mtx;
//	int a = 0;
//	int b = 0;
//	thread thd1([&]() {
//		for (int i = 0; i < size; i++)
//		{
//			lock_guard<mutex> lk(mtx);
//			n++;
//			a++;
//		}
//		});
//
//	thread thd2([&]() {
//		for (int i = 0; i < size; i++)
//		{
//			lock_guard<mutex> lk(mtx);
//			n++;
//			b++;
//		}
//		});
//	thd1.join();
//	thd2.join();
//
//	std::cout << n << endl;
//	cout << "a:" << a << endl;
//	cout << "b:" << b << endl;
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int size = 10000;
//	mutex mtx;
//	int a = 0;
//	int b = 0;
//	// ��Ϊ++��һ���򵥵Ĳ�������Ҫ��ʱ��̣ܶ���Ϊ�����л���Ҫ���������ģ���ҪһЩʱ�䣬
//	// ��ͻᵼ����ʱ��Ƭ��ͬ������£�һ���߳�Ƶ�����뵽����
//	// ����������£������������ʣ�������������ÿ��һ��ʱ�䣬��ѯ��
//	thread thd1([&]() {
//		while (n < size)
//		{
//			lock_guard<mutex> lk(mtx);
//			n++;
//			a++;
//		}
//		});
//
//	thread thd2([&]() {
//		while (n < size)
//		{
//			lock_guard<mutex> lk(mtx);
//			n++;
//			b++;
//		}
//		});
//	thd1.join();
//	thd2.join();
//
//	std::cout << n << endl;
//	cout << "a:" << a << endl;
//	cout << "b:" << b << endl;
//	return 0;
//}

using namespace std;

int main()
{
	atomic<int> n = 0;
	int size = 100000;
	int a = 0;
	int b = 0;
	// atomic ͨ��ԭ�Ӳ����������ٽ���Դ�����̰߳�ȫ
	// ���� ������� CAS compare and swap
	// CPU�ṩ��ָ�CAS�Ĺ�����ԭ�ӵģ����ᱻ��ϵ�
	// CAS(& , old, new)
	// if(* != old) return false;
	// else * = new; return true;
	// do{}while(CAS())
	thread thd1([&]() {
		while (n < size)
		{
			int newval, old;
			do 
			{
				old = n;
				newval = old + 1;
				
			} while (!atomic_compare_exchange_weak(&n, &old, newval));
			a++;
		}
		});

	thread thd2([&]() {
		while (n < size)
		{
			int newval, old;
			do
			{
				old = n;
				newval = old + 1;

			} while (!atomic_compare_exchange_weak(&n, &old, newval));
			b++;
		}
		});
	thd1.join();
	thd2.join();

	std::cout << n << endl;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	return 0;
}