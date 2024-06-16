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
	// ��Դ�Ĺ���Ȩ��ת���ˣ�p1������nullptr
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

	// ������������͸�ֵ
}

void Test_shared_ptr()
{
	kele::shared_ptr<int> p1(new int(1));
	kele::shared_ptr<int> p2 = p1;
	kele::shared_ptr<int> p3 = new int(2); // �������Ż�����+��������->ֱ�ӹ��죬���Կ���������
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


// ѭ�����õ�����
void Test_shared_ptr2()
{
	kele::shared_ptr<Node> p1 = new Node;
	kele::shared_ptr<Node> p2 = new Node;

	p1->next = p2;
	p2->next = p1;

	// ѭ���������⣺
	// p1��next��ָ��p2��p2�ռ�����ü���Ϊ2
	// p2��next��ָ��p1��p1�ռ�����ü���Ϊ2
	// ��p1��p2����ʱ�������-1��������Ϊnext��ָ����Щ�ռ����ԣ���û���ͷ�
	// ���Ծ���Ҫ����һ��ָ�룬�ܹ�ָ��ռ䣬���ǾͲ�Ҫ������û��RAII����������ָ���������ʹ��


}

// delete[] ������
// ����ʱ���Σ�function��װ��
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
	// ���������ԭ���ǣ������߳����ͬʱcopy shared_ptr �ͻᵼ�����ü�����׼ȷ�����п��ܶ������ͬһ��ռ�
	// ����shared_ptr �����ü�����Ҫ���̰߳�ȫ�ģ� ��������ָ������ݲ����̰߳�ȫ��
	thd1.join();
	thd2.join();
	cout << p1.use_count() << endl;
}


int main()
{
	Test_shared_ptr4();
	return 0;
}