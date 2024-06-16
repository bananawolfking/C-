#include <iostream>
#include <mutex>

using namespace std;;

// 1.�����һ���࣬���ܱ�����
class cantbecopy
{
public:
	cantbecopy()
	{}
	// ���������ѿ�������͸�ֵ����ɾ��
	cantbecopy(const cantbecopy&) = delete;
	cantbecopy& operator=(const cantbecopy&) = delete;


private:
	// ����һ���ѿ�������͸�ֵ����˽�л�
	// 1. ��������ֹ���Զ����ɵ�Ĭ�ϵĿ�������͸�ֵ����
	// 2. ˽�л������ֻ������˽�л��������涨���˹���͸�ֵ���ͻ�ʵ�ֿ���������˽�л�
	//cantbecopy(const cantbecopy&);
	//cantbecopy& operator=(const cantbecopy&);
};


//int main()
//{
//	cantbecopy i;
//	//cantbecopy y = i;
//	cantbecopy j;
//	//j = i;
//
//	return 0;
//}


// 2. �����һ���ֻ࣬���ڶ��ϴ�������
class onlyheap
{
public:
	static onlyheap* CreatObject()
	{
		return new onlyheap;
	}

	static onlyheap* CopyObject(const onlyheap* t)
	{
		// ʵ�ִ����Ϳ���
		onlyheap* copy = CreatObject();
		// ���ø�ֵ����
		*copy = *t;
		return copy;
	}
private:
	onlyheap()
	{}

	onlyheap(const onlyheap&);

};

// Ϊ�˲�����ջ�ϴ���������Ҫ�����ڶ��ϴ�������������Ҫ��������ģ����Թ��캯��Ҫ�У�����˽�л�
// �ڲ����ṩһ�����еĺ���������new�Ķ��󣬵���˽�еĹ��촴��
// Ϊ�˷�ֹջ�Ͽ�������new�Ķ��󣬽�����ջ�ϴ��������԰ѿ�������Ҳ˽�л�

//int main()
//{
//	//onlyheap p1;
//	onlyheap* p2 = onlyheap::CreatObject();
//	//onlyheap p1(*p2);
//
//
//
//	return 0;
//}


// 3. �����һ���ֻ࣬����ջ�ϴ�������

// ����һ���ѹ��캯���Ϳ�������˽�л�����ֹnew����newʱ����
//		  ����������˽�л�����ֹdelete����

//class onlystack
//{
//public:
//	static onlystack CreatObject()
//	{
//		onlystack ret;
//		return ret;
//	}
//
//	static onlystack CopyObject(const onlystack& t)
//	{
//		onlystack ret(t);
//		return ret;
//	}
//
//private:
//	onlystack(){}
//	onlystack(const onlystack& t) {}
//};

// ��������
// ���ض�Ӧ��new��delete
class onlystack
{
public:
	// ��ʽ�̶�
	void* operator new(size_t size) = delete;

	void operator delete(void* p) = delete;

private:

};

//int main()
//{
//	onlystack p2;
//	//onlystack* p1 = new onlystack(p2);
//	//delete &p2;
//
//	return 0;
//}


// 4. �����һ���࣬���ܱ��̳�


// ����һ�����๹�캯��˽�л�
// ��������Ҫ���ø���Ĺ��캯��

//class NonInherit
//{
//public:
//	static NonInherit CreatObject()
//	{
//		NonInherit ret;
//		return ret;
//	}
//
//private:
//	NonInherit(){}
//
//};

// ����������final

class NonInherit final
{
public:
	static NonInherit CreatObject()
	{
		NonInherit ret;
		return ret;
	}

private:
	NonInherit() {}

};

//class B: public NonInherit
//{
//public:
//	B()
//	{
//
//	}
//};

//int main()
//{
//
//
//	return 0;
//}

#include <map>
#include <string>

// ����ģʽ
// 1. ����ģʽ main����֮ǰ�ʹ�����
// �ŵ㣺ʵ�ּ򵥣����ÿ����̰߳�ȫ��������Ч�ʸ�
// ȱ�㣺����������ʼ��˳���ܿ���
// ���������������ڶ��̸߲߳���������Ƶ��ʹ�ã�����Ҫ��ϸߣ���ô��Ȼʹ�ö���ģʽ��������Դ�����������Ӧ�ٶȸ��á�
// 2. ����ģʽ �õ���ʱ���ٴ���
// �ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��ء��������ʵ������˳�����ɿ��ơ�
// ȱ�㣺���ӣ���Ҫ�����̰߳�ȫ
// �������������ʮ�ֺ�ʱ����ռ�úܶ���Դ��������ز������ ��ʼ���������Ӱ�����ȡ�ļ����ȵȣ�
// ���п��ܸö����������ʱ�����õ�����ôҲҪ�ڳ���һ��ʼ�ͽ��г�ʼ�����ͻᵼ�³�������ʱ�ǳ��Ļ����� 
// �����������ʹ������ģʽ���ӳټ��أ����á�
//



// 1. �����㵥��������ֻ�ᱻ����һ��
class Hungry_man
{
public:
	static Hungry_man* GetInstance()
	{
		// ��̬��Ա���������Է��ʾ�̬��Ա
		return &_Instance;
	}

private:
	//ֻ�ᴴ��һ�Σ�˵��ֻ����һ�Σ�û�п������͸�ֵ
	Hungry_man(){}

	Hungry_man(const Hungry_man&) = delete;
	Hungry_man& operator=(const Hungry_man&) = delete;


	map<string, string> _map;
	int flag = 0;

	// ���Ծ�̬�Լ����࣬��Ϊ��Ա������?
	// ���ԣ���Ϊ��̬��Ա�����ھ�̬�����ѳ�ʼ��ȫ�ֱ����������������ʵ�������ݣ���̬��Աֻ��һ��
	// Ϊʲô��
	// ��ȫ�ֿռ��ʼ��һ�Σ��������Ѿ��������ˣ����Ҿ�̬��ԱҲֻ�ܳ�ʼ��һ�Σ���֤����
	static Hungry_man _Instance;
};

// ��ȫ�ֳ�ʼ��һ�Σ�����
// main����������Ϊ�������ڣ�ȫ�ֱ����ĳ�ʼ����main����֮ǰ������Ƕ�����ģʽ
Hungry_man Hungry_man::_Instance;


// 1. �����㵥��������ֻ�ᱻ����һ��
class Lazy_man
{
public:
	//static Lazy_man* GetInstance()
	//{
	//	// ��̬��Ա���������Է��ʾ�̬��Ա
	//	if (_Instance == nullptr) // ���û�У���Ҫ���ٴ���
	//	{
	//		_Instance = new Lazy_man;// ���ﲻ���̰߳�ȫ��
	//	}
	//	return _Instance;
	//}

	static Lazy_man* GetInstance()
	{
		// ��̬��Ա���������Է��ʾ�̬��Ա
		if (_Instance == nullptr)
		{
			if (_Instance == nullptr) // ���û�У���Ҫ���ٴ���
			{
				lock_guard<mutex> lk(_mtx);
				_Instance = new Lazy_man;// ���ﲻ���̰߳�ȫ��
			}
		}
		return _Instance;
	}

	static void Destroy()
	{
		if (_Instance)
		{
			delete _Instance;
			_Instance = nullptr;
			cout << "���ٳɹ�" << endl;
		}
	}

private:
	//ֻ�ᴴ��һ�Σ�˵��ֻ����һ�Σ�û�п������͸�ֵ
	Lazy_man() {}

	Lazy_man(const Lazy_man&) = delete;
	Lazy_man& operator=(const Lazy_man&) = delete;

	// ��������˽�л��������ڲ����û��������Զ���ʵ�������Ķ��⴦��������������ݱ��浽�ļ�
	~Lazy_man() {} 

	map<string, string> _map;
	int flag = 0;

	static Lazy_man* _Instance;

	static mutex _mtx;

	class gc
	{
	public:
		~gc()
		{
			Destroy();
		}
	};

	// �����ƳɷǾ�̬�ģ��û����������������ͻ������ʵҲ������֮ǰ��Ŀ��main����֮������
	//gc _gc;
	static gc _gc;
};

// ��̬��Ա�ĳ�ʼ����ָ�����Ϳɲ���ʵ����
Lazy_man* Lazy_man::_Instance = nullptr;
Lazy_man::gc Lazy_man::_gc;
mutex Lazy_man::_mtx;


class Lazy_man_c11
{
public:
	//static Lazy_man* GetInstance()
	//{
	//	// ��̬��Ա���������Է��ʾ�̬��Ա
	//	if (_Instance == nullptr) // ���û�У���Ҫ���ٴ���
	//	{
	//		_Instance = new Lazy_man;// ���ﲻ���̰߳�ȫ��
	//	}
	//	return _Instance;
	//}

	static Lazy_man_c11* GetInstance()
	{
		static Lazy_man_c11 lazy;
		return &lazy;
	}

private:
	//ֻ�ᴴ��һ�Σ�˵��ֻ����һ�Σ�û�п������͸�ֵ
	Lazy_man_c11() 
	{
		cout << "lazy" << endl;
	}
};

int main()
{
	Lazy_man_c11::GetInstance();
	return 0;
}

//int main()
//{
//	Hungry_man* qq = Hungry_man::GetInstance();
//
//
//	Lazy_man* p1 = Lazy_man::GetInstance();
//	Lazy_man* p2 = Lazy_man::GetInstance();
//	Lazy_man* p3 = Lazy_man::GetInstance();
//
//	// ������˲����������delete�ᵼ�±�������Ҫ������˽�л�������ɾ���ڲ���Ҫ
//	//delete p1;
//
//	Lazy_man::Destroy();
//	cout << p1 << endl; // p1ָ��Ҫע���ˣ�û�취������ʱ���ֱ��ʹ�ã���Ҫ���浽ָ���ڲ�
//	Lazy_man* p4 = Lazy_man::GetInstance();
//
//	cout << "VVVVVVVVVVVVV" << endl;
//
//	// �����������
//	// ʵ�ֵ�Ŀ�꣺���õ�ʱ�������ʽ�ĵ������٣�Ҳ������main����������ʱ���Լ�����
//
//	return 0;
//}