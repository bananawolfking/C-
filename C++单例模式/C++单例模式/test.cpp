#include <iostream>
#include <mutex>

using namespace std;;

// 1.请设计一个类，不能被拷贝
class cantbecopy
{
public:
	cantbecopy()
	{}
	// 方案二：把拷贝构造和赋值重载删除
	cantbecopy(const cantbecopy&) = delete;
	cantbecopy& operator=(const cantbecopy&) = delete;


private:
	// 方案一：把拷贝构造和赋值重载私有化
	// 1. 声明，防止类自动生成的默认的拷贝构造和赋值重载
	// 2. 私有化，如果只声明不私有化，类外面定义了构造和赋值，就会实现拷贝，必须私有化
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


// 2. 请设计一个类，只能在堆上创建对象
class onlyheap
{
public:
	static onlyheap* CreatObject()
	{
		return new onlyheap;
	}

	static onlyheap* CopyObject(const onlyheap* t)
	{
		// 实现创建和拷贝
		onlyheap* copy = CreatObject();
		// 调用赋值重载
		*copy = *t;
		return copy;
	}
private:
	onlyheap()
	{}

	onlyheap(const onlyheap&);

};

// 为了不让在栈上创建，但是要可以在堆上创建，本质是需要创建构造的，所以构造函数要有，但是私有化
// 内部再提供一个共有的函数，返回new的对象，调用私有的构造创建
// 为了防止栈上拷贝构造new的对象，进而在栈上创建，所以把拷贝构造也私有化

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


// 3. 请设计一个类，只能在栈上创建对象

// 方案一：把构造函数和拷贝构造私有化，防止new（）new时拷贝
//		  把析构函数私有化，防止delete对象

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

// 方案二：
// 重载对应的new和delete
class onlystack
{
public:
	// 格式固定
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


// 4. 请设计一个类，不能被继承


// 方案一：基类构造函数私有化
// 派生类需要调用父类的构造函数

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

// 方案二：加final

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

// 单例模式
// 1. 饿汉模式 main函数之前就创建好
// 优点：实现简单，不用考虑线程安全，启动后效率高
// 缺点：启动慢，初始化顺序不能控制
// 如果这个单例对象在多线程高并发环境下频繁使用，性能要求较高，那么显然使用饿汉模式来避免资源竞争，提高响应速度更好。
// 2. 懒汉模式 用到的时候再创建
// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
// 缺点：复杂，需要考虑线程安全
// 如果单例对象构造十分耗时或者占用很多资源，比如加载插件啊， 初始化网络连接啊，读取文件啊等等，
// 而有可能该对象程序运行时不会用到，那么也要在程序一开始就进行初始化，就会导致程序启动时非常的缓慢。 
// 所以这种情况使用懒汉模式（延迟加载）更好。
//



// 1. 先满足单例条件，只会被创建一次
class Hungry_man
{
public:
	static Hungry_man* GetInstance()
	{
		// 静态成员函数，可以访问静态成员
		return &_Instance;
	}

private:
	//只会创建一次，说明只构造一次，没有拷贝，和赋值
	Hungry_man(){}

	Hungry_man(const Hungry_man&) = delete;
	Hungry_man& operator=(const Hungry_man&) = delete;


	map<string, string> _map;
	int flag = 0;

	// 可以静态自己的类，作为成员函数吗?
	// 可以，因为静态成员，属于静态区（已初始化全局变量），不论这个类实例化几份，静态成员只有一份
	// 为什么？
	// 在全局空间初始化一次，这个类就已经创建好了，而且静态成员也只能初始化一次，保证单例
	static Hungry_man _Instance;
};

// 在全局初始化一次，单例
// main（）函数称为程序的入口，全局变量的初始化在main函数之前，这就是饿汉的模式
Hungry_man Hungry_man::_Instance;


// 1. 先满足单例条件，只会被创建一次
class Lazy_man
{
public:
	//static Lazy_man* GetInstance()
	//{
	//	// 静态成员函数，可以访问静态成员
	//	if (_Instance == nullptr) // 如果没有，需要，再创建
	//	{
	//		_Instance = new Lazy_man;// 这里不是线程安全的
	//	}
	//	return _Instance;
	//}

	static Lazy_man* GetInstance()
	{
		// 静态成员函数，可以访问静态成员
		if (_Instance == nullptr)
		{
			if (_Instance == nullptr) // 如果没有，需要，再创建
			{
				lock_guard<mutex> lk(_mtx);
				_Instance = new Lazy_man;// 这里不是线程安全的
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
			cout << "销毁成功" << endl;
		}
	}

private:
	//只会创建一次，说明只构造一次，没有拷贝，和赋值
	Lazy_man() {}

	Lazy_man(const Lazy_man&) = delete;
	Lazy_man& operator=(const Lazy_man&) = delete;

	// 析构函数私有化，可以在不让用户析构，自定义实现析构的额外处理动作，比如把数据保存到文件
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

	// 如果设计成非静态的，用户主动销毁析构，就会出错，其实也不符合之前的目的main（）之后析构
	//gc _gc;
	static gc _gc;
};

// 静态成员的初始化，指针类型可不会实例化
Lazy_man* Lazy_man::_Instance = nullptr;
Lazy_man::gc Lazy_man::_gc;
mutex Lazy_man::_mtx;


class Lazy_man_c11
{
public:
	//static Lazy_man* GetInstance()
	//{
	//	// 静态成员函数，可以访问静态成员
	//	if (_Instance == nullptr) // 如果没有，需要，再创建
	//	{
	//		_Instance = new Lazy_man;// 这里不是线程安全的
	//	}
	//	return _Instance;
	//}

	static Lazy_man_c11* GetInstance()
	{
		static Lazy_man_c11 lazy;
		return &lazy;
	}

private:
	//只会创建一次，说明只构造一次，没有拷贝，和赋值
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
//	// 如果有人不明情况，就delete会导致报错；所以要把析构私有化，不能删除内部需要
//	//delete p1;
//
//	Lazy_man::Destroy();
//	cout << p1 << endl; // p1指针要注意了，没办法，属于时最好直接使用，不要保存到指针内部
//	Lazy_man* p4 = Lazy_man::GetInstance();
//
//	cout << "VVVVVVVVVVVVV" << endl;
//
//	// 解决回收问题
//	// 实现的目标：不用的时候可以显式的调用销毁，也可以在main函数结束的时候，自己析构
//
//	return 0;
//}