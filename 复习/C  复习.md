# C++语法复习

## 1. C++入门基础

### 缺省参数

1. 半缺省参数必须从右往左依次来给出，不能间隔着给
2.  缺省参数不能在函数声明和定义中同时出现
3. 缺省值必须是常量或者全局变量 
4.  C语言不支持（编译器不支持）

### 函数重载

函数重载是函数的一种特殊情况，C++允许在**同一作用域中声明几个功能类似的同名函数**，这 些同名函数的形参列表**(参数个数 或 类型 或 类型顺序)不同**，常用来处理实现功能类似数据类型不同的问题。

**原理：函数名的修饰规则 链接时需要通过函数名找到函数实现**

gcc的函数修饰后名字不变。而g++的函数修饰后变成【_Z+函数长度 +函数名+类型首字母】

 通过这里就理解了C语言没办法支持重载，因为同名函数没办法区分。而C++是通过函数修 饰规则来区分，只要参数不同，修饰出来的名字就不一样，就支持了重载

### 引用和指针

引用概念：引用不是新定义一个变量，而是给**已存在变量取了一个别名**，编译器不会为引用变量开辟内存空 间，它和它引用的变量共用同一块内存空间。

**引用和指针的区别**：

**从语法的角度来说**：**引用是给已有的变量取别名，不开空间；指针是开空间存储对象的地址，指向对象**

从使用角度来说：

1. **引用定义的时候需要初始化，指针可以不初始化**
2. 上面推论：没有NULL引用，但有NULL指针， 引用比指针使用起来相对更安全
3. **指针可以改变指向，引用不可以改变**
4. 有多级指针，但是没有多级引用
5. sizeof指针和引用含义不一样
6. 引用++和指针++表达的含义不一样
7. 访问实体的方式不一样，指针需要显示解引用，引用由编译器处理

**从底层实现的角度来说（最后）**：**引用在底层实现上实际是有空间的，因为引用是按照指针方式来实现的**

**引用的使用场景**：

1.做参数

2.做返回值（注意使用安全，不要返回栈上的临时对象）

### 内联inline

C++建议使用 const enum inline 代替 宏， 内联/宏 和 函数对应

再来说说宏的缺点：

1. 容易出错，符号优先级问题
2. 不能调试，预处理阶段已经替换，看不到宏的具体处理逻辑
3. 不够严谨，与类型无关，缺少类型检查

宏的优点：对于各种类型都适配，可以增加代码的复用性，当处理小型计算的任务时宏比函数调用的消耗更小

内联：**以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数调用建立栈帧的开销，内联函数提升程序运行的效率**。

inline是一种以空间换时间的做法，如果编译器将函数当成内联函数处理，在编译阶段，会 用函数体替换函数调用，缺陷：**可能会使目标文件变大（这一点和宏一样）**，优势：少了调用开销，提高程序运 行效率

inline对于编译器而言只是一个建议，不同编译器关于inline实现机制可能不同

inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址 了，链接就会找不到

### nullptr

因为NULL在C++中可能是0也可能是（（void*）0）

```cc
#ifndef NULL
#ifdef __cplusplus
#define NULL   0
#else
#define NULL   ((void *)0)
#endif
#endif
```

1.  在使用nullptr表示指针空值时，不需要包含头文件，因为nullptr是C++11作为新关键字引入 的。
2.  在C++11中，sizeof(nullptr) 与 sizeof((void*)0)所占的字节数相同。 
3.  为了提高代码的健壮性，在后续表示指针空值时建议最好使用nullptr。

## 2. 类和对象

### **面向对象和面向过程的区别？**

面向对象更加注重：类和类之间的关系（如：栈的实现，容器适配器、迭代器统一（反向迭代器），算法通过迭代器获取容器的数据）

面向对象更加注重实现过程

**面向对象（Object-Oriented Programming, OOP）**是一种编程范式，它基于“对象”的概念，将数据和操作数据的方法组织在一起。在面向对象编程中，对象是类的实例，类定义了对象的属性（数据成员）和行为（方法）。对象可以互相通信，通过调用彼此的方法来完成任务。面向对象的四个核心原则是封装、继承、多态和抽象。
**面向对象的主要特点**：

1. 封装：隐藏对象的内部细节，只对外提供接口进行交互，保护数据的安全性。
2. 继承：允许创建一个新类（子类）作为现有类（父类）的扩展，继承其属性和方法。
3. 多态：同一方法可以根据调用它的对象类型表现出不同的行为。
4. 抽象：通过抽象类或接口来定义通用行为，实现代码的重用和模块化。

**面向过程（Procedural Programming）**： 面向过程编程更侧重于步骤和函数的组合来解决问题。程序被设计为一系列有序的步骤，每个步骤对应一个函数或子程序，这些函数直接操作数据。面向过程编程不强调对象的概念，而是以数据为中心，通过函数来处理数据。
**面向对象与面向过程的区别**：

1. **编程思路：面向对象是基于类和对象，通过对象之间的交互实现功能；面向过程是通过函数调用来完成任务序列。**
2. **封装性：面向对象封装的是数据和操作数据的方法，而面向过程主要封装的是功能逻辑。**
3. **结构与复用：面向对象支持继承和多态，使得代码更容易复用和扩展；面向过程的复用主要依赖函数和模块。**
4. **复杂性管理：面向对象更适合处理复杂的系统，因为它能更好地模拟现实世界中的实体和关系；面向过程则适用于简单的、线性的任务。**

### **类大小的计算**

内存对齐

和结构体的内存对齐规则一样

1. 首元素位于0偏移量地址
2. 对齐数 = 编译器的默认对齐数 和 对象大小 （取小）
3. 整体大小等于最大对齐数的整数倍

空类大小（占位）

**注意空类的大小，空类比较特殊，编译器给了空类一个字节来唯一标识这个类的对象。**

成员函数代码位于代码区，成员变量在实例化位置定义

### **struct 和 class 的区别**

访问限定符、继承关系、兼容C语言

struct访问限定符默认public，class访问限定符默认private

struct默认public继承，class默认private继承

struct兼容C语言，在C语言中是结构体，在C++中可以定义成员函数方法，class不兼容C语言

### **this指针**

C++编译器给每个“非静态的成员函数“增加了一个隐藏 的指针参数，让该指针指向当前对象(函数运行时调用该函数的对象)，在函数体中所有“成员变量” 的操作，都是通过该指针去访问。只不过所有的操作对用户是透明的，即用户不需要来传递，编 译器自动完成

**特性**：

1. this指针的类型：**类类型* const**，即成员函数中，不能给this指针赋值 
2.  只能在“成员函数”的内部使用 
3.  this指针本质上是“成员函数”的形参，当对象调用成员函数时，将对象地址作为实参传递给 this形参。所以对象中不存储this指针
4.  this指针是“成员函数”**第一个**隐含的指针形参，一般情况由编译器通过ecx寄存器自动传递，不需要用户传递

**this指针储存位置**（寄存器ecx或调用位置的栈空间）

从概念上讲，当你调用一个非静态成员函数时，**编译器会自动将调用该函数的对象的地址作为第一个隐式参数传递给该函数，这个地址就是this指针的值**。在函数内部，你可以通过this指针来访问或修改对象的成员。

然而，**this指针并不是存储在对象的内存布局中的一部分。它更像是函数调用的一个“附加”参数**，由编译器在函数调用时自动处理。

在大多数实现中，当你调用一个成员函数时，编译器会生成一些额外的代码来设置this指针。**这个指针通常会被存放在一个特殊的寄存器中，或者如果寄存器不可用，它可能会被压入调用栈中**。但是，这些都是实现细节，并且在不同的编译器和平台上可能会有所不同

this指针可以为空吗，当你调用的成员函数内部不访问成员变量（就不会解引用报错）- 使用方式类似于静态成员函数

### **八个默认成员函数**

1. 构造和析构
2. 拷贝构造和赋值
3. 移动构造和移动赋值
4. 取地址重载和const取地址重载（基本不用）

一般情况下，构造都是要自己实现的

深拷贝的类，需要提供拷贝构造、赋值重载和析构

移动构造和移动赋值，当上面三个是编译器默认生成的，编译器才会自己在生成

也就是说一般深拷贝的类需要自己提供移动构造和移动赋值

默认生成的，会对内置类型浅拷贝，对自定义类型调用其拷贝构造或赋值

**对于默认移动构造和移动赋值，会对内置类型拷贝，自定义类型调用其对应的（自己实现的yes）移动构造，如果没有调用拷贝构造**

### **初始化列表**

特性：所有的构造初始化都会经过初始化列表

哪些成员必须要在初始化列表初始化？

- **引用成员变量**
- **const成员变量**
- **没有默认构造的自定义成员变量**

**无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为是默认构造函数**

初始化列表的初始化顺序是成员对象的声明顺序

### **运算符重载**

目的是让自定义类型用运算符，增强可读性

哪些运算符不能重载 (.*  .)

```cc
class Person
{
public:
	Person(double name = 1.1, int age = 0)
		:_name(name)
		, _age(age)
	{}

	void* operator new(size_t size) // new重载
	{}

	void operator delete(void* p) // delete重载
	{}
private:
	Test2 _name;
	int _age;
};
```

### **友元**（了解）

友元提供了一种突破封装的方式，有时提供了便利。但是友元会增加耦合度，破坏了封装，所以 友元不宜多用

友元函数

友元函数可以直接访问类的私有成员，它是定义在类外部的普通函数，不属于任何类，但需要在 类的内部声明，声明时需要加friend关键字

- 友元函数可访问类的私有和保护成员，但不是类的成员函数 
- 友元函数不能用const修饰 
- 友元函数可以在类定义的任何地方声明，不受类访问限定符限制 
- 一个函数可以是多个类的友元函数 
- 友元函数的调用与普通函数的调用原理相同

友元类

友元类的所有成员函数都可以是另一个类的友元函数，都可以访问另一个类中的非公有成员

- 友元关系是单向的，不具有交换性
- 友元关系不能传递
- 友元关系不能继承

### **explicit关键字**

构造函数**对于单个参数或者除第一个参数无默认值其余均有默认值 的构造函数，还具有类型转换的作用**。

使用用explicit修饰构造函数，将会**禁止构造函数的隐式转换**

### **static成员**

**不属于类的成员大小**

**可以当作静态全局变量，只是受类域的限制**

**需要在类外定义**

所有类实例化的对象共用一个静态成员变量

1. 静态成员函数可以调用非静态成员函数吗？（参数传了this就可以）
2. 非静态成员函数可以调用类的静态成员函数吗？可以

## 3. 内存管理￥

### 内存分布



### malloc/calloc/realloc 区别

。。。

### new/delete 和 malloc/free 区别（重点）

1. 性质 操作符运算符 库函数
2. 使用 需不需要大小/返回值类型强转与否/出错返回空或抛异常
3. 功能 对于类型的初始化，和对自定义类型的析构

### new和new[]的底层实现原理

new和delete是用户进行动态内存申请和释放的操作符，**operator new 和operator delete是系统提供的全局函数**，new在底层调用operator new全局函数来申请空间，delete在底层通过 operator delete全局函数来释放空间。

operator new （全局）+ 构造函数 operator new封装malloc

为什么？解决抛异常的问题，operator new失败内部抛异常

operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间失败，尝试执行空        间不足应对措施，如果改应对措施用户设置了，则继续申请，否则抛异常

**定位new/显示调用构造函数 -  new(地址)类型** 

**显示调用析构  -  地址->~类型()**

### 内存泄漏

**堆内存泄漏**(Heap leak) 和 **系统资源泄漏**（套接字、文件描述符、管道）

**什么是内存泄漏**：内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。内 存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对 该段内存的控制，因而造成了内存的浪费。 内存**泄漏的危害**：长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现 内存泄漏会导致响应越来越慢，最终卡死。

**如何避免内存泄漏**

1. 工程前期良好的设计规范，养成良好的编码规范，申请的内存空间记着匹配的去释放。ps： 这个理想状态。但是如果碰上异常时，就算注意释放了，还是可能会出问题。需要下一条智 能指针来管理才有保证。 
2. 采用RAII思想或者智能指针来管理资源。
3. 有些公司内部规范使用内部实现的私有内存管理库。这套库自带内存泄漏检测的功能选项。 
4. 出问题了使用内存泄漏工具检测。ps：不过很多工具都不够靠谱，或者收费昂贵

## 4. 模板

 非类型模板参数，就是用一个常量作为类(函数)模板的一个参数，在类(函数)模板中可将该参数当成常量来使用（整形）

**使用模板可以实现一些与类型无关的代码**

### 语法格式

```cc
template<class T>
 bool Less(T left, T right)
 {
    return left < right;
 }
```

**在模板函数使用的时候一般是传参，然后编译器推导**

**对类模板使用使用时，一般是显示指定类型---类类型<模板参数类型> 对象名**

但对于一些特殊类型的可能会得到一些错误的结果

例如：对比指针类型，比较的是指针的地址，而不是指向的对象大小关系

此时，就需要对模板进行特化。即：在原模板类的基础上，**针对特殊类型所进行特殊化的实现方式**。模板特化中分为**函数模板特化与类模板特化**。

### **模板特化**

**函数模板特化**(函数模板特化必须要指定特定的类型，没有偏特化的说法)

1. **必须要先有一个基础的函数模板**  
2.  关键字template后面接一对空的尖括号<> 
3.  **函数名后跟一对尖括号，尖括号中指定需要特化的类型**  
4.  函数形参表: **必须要和模板函数的基础参数类型完全相同**，如果不同编译器可能会报一些奇怪的错误

```cc
namespace kele
{
	template<class T> // 基础的函数模板
	bool less(T a, T b)
	{
		return a < b;
	}

	template<> // 特化的函数模板
	bool less<int*>(int* a, int* b)
	{
		return *a < *b;
	}

	bool less(int* left, int* right) // 函数 优先级最高
	{
		return *left < *right;
	}
}
```

**注意：一般情况下如果函数模板遇到不能处理或者处理有误的类型，为了实现简单通常都是将该函数直接给出**

**类模板特化**

**全特化：全特化即是将模板参数列表中所有的参数都确定化。**

**偏特化：任何针对模版参数进一步进行条件限制设计的特化版本。**

- 部分特化
- **参数更进一步的限制（指针/引用）**

要注意：参数限制还有const限制要考虑

```cc
namespace kele // 反向迭代器利用萃取类（模板偏特化）
{	
	template <class Iterator>
    struct iterator_traits {
        typedef typename Iterator::value_type        value_type;
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
    };

	template <class T>
    struct iterator_traits<T*> {
        typedef T                          value_type;
        typedef T*						   pointer;
        typedef T&						   reference;
    };

	template <class T>
    struct iterator_traits<const T*> {
        typedef T                          value_type;
        typedef const T*				   pointer;
        typedef const T&				   reference;
    };

	template<class Iteartor>
    struct Reverse_Iterator
    {
        typedef typename iterator_traits<Iteartor>::value_type value_type;
        typedef typename iterator_traits<Iteartor>::reference reference;
        typedef typename iterator_traits<Iteartor>::pointer pointer;

        typedef Reverse_Iterator<Iteartor> self;

        Iteartor rit;
        Reverse_Iterator(Iteartor x)
            :rit(x)
            {}

        template<class iter>
            Reverse_Iterator(const Reverse_Iterator<iter>& x)
            :rit(x.rit)
            {}

        reference operator*()
        {
            Iteartor tmp = rit;
            return *(--tmp);
        }

        pointer operator->()
        {
            return &(operator*());
        }

        self operator++()
        {
            --rit;
            return *this;
        }

        self operator++(int)
        {
            self tmp = *this;
            --rit;
            return tmp;
        }

        self operator--()
        {
            ++rit;
            return *this;
        }

        self operator--(int)
        {
            self tmp = *this;
            ++rit;
            return tmp;
        }

        bool operator!=(const self& x) const
        {
            return rit != x.rit;
        }

        bool operator==(const self& x) const
        {
            return rit == x.rit;
        }
    };
}
```

### 模板分离编译

模板不能分离编译：模板在没有实例化的时候是不会被编译的，在两个文件中，一个有实例化的声明，一个没有函数，就会链接报错，解决方法：

1. 将声明和定义放到一个文件 "xxx.hpp" 里面或者xxx.h其实也是可以的。推荐使用这种。 
2. 模板定义的位置显式实例化。这种方法不实用，不推荐使用。

### **模板优点和缺点**

优点：

1. 模板**复用**了代码，节省资源，更快的迭代开发，C++的标准模板库(STL)因此而产生 
2.  增强了代码的灵活性

缺点：

1. 模板会导致**代码膨胀问题**，也会导致**编译时间变长** 
2.  出现模板编译错误时，**错误信息非常凌乱，不易定位错误**

## 5. 继承（重点）

### 什么是继承？继承的意义

继承(inheritance)机制是**面向对象程序设计使代码可以复用的最重要的手段**，它允许程序员在保持原有类特性的基础上进行扩展，增加功能，这样产生新的类，称**派生类**。**继承呈现了面向对象程序设计的层次结构**，体现了由简单到复杂的认知过程。以前我们接触的复用都是函数复用，继承是**类设计层次的复用**

|   类成员/继承方式    |      public继承       |     protected继承      |     private继承      |
| :------------------: | :-------------------: | :--------------------: | :------------------: |
|   基类的public成员   |  派生类的public成员   | 派生类的protected 成员 | 派生类的private 成员 |
| 基类的protected 成员 | 派生类的protected成员 | 派生类的protected 成员 | 派生类的private 成员 |
|  基类的private成员   |   在派生类中不可见    |    在派生类中不可见    |   在派生类中不可见   |

不可见是指**基类的私有成员还是被继承到了派生类对象中**，但是语法上限制派生类对象不管在类里面还是类外面都**不能去访问它**。

使用关键字**class时默认的继承方式是private**，使用**struct时默认的继承方式是public**

在实际运用中一般使用都是public继承，几乎很少使用protetced/private继承

### 赋值兼容 - 切片

**派生类对象** 可以赋值给 **基类的对象 / 基类的指针 / 基类的引用**。这里有个形象的说法叫**切片**或者**切割**。寓意把派生类中父类那部分切来赋值过去。

**基类对象不能赋值给派生类对象**

基类的指针或者引用可以通过强制类型转换赋值给派生类的指针或者引用。但是必须是基类的指针是指向派生类对象时才是安全的

### 隐藏（重定义）

1. 在继承体系中**基类**和**派生类**都有**独立的作用域**
2. **子类和父类中有同名成员**，子类成员将**屏蔽父类对同名成员的直接访问**，这种情况叫**隐藏**， 也叫**重定义**。（在子类成员函数中，可以使用 **基类::基类成员 显示访问**）
3. 需要注意的是如果是**成员函数的隐藏**，只需要**函数名相同就构成隐藏**
4. 注意在实际中在继承体系里面最好不要定义同名的成员

```cc
//// 类继承
class Person
{
public:
	void print()
	{
		cout << _name << _age << endl;
	}
protected:
	string _name = "kele";
	int _age = 21;
};

class Student :public Person
{
public:
	void print()
	{
		cout << _name << _age << _stdid << endl;
	}
protected:
	string _name = "lihua";
	int _stdid = 1111;
};

int main()
{
	Student s;
	s.print();
	s.Person::print();//显示访问基类print函数
	return 0;
}
```

结果：

> lihua211111
> kele21

说明理解：成员也可以隐藏，这种隐藏更加像是在不同类域的显示优先级，例如同名的局部变量和全局变量

### 派生类的默认成员函数行为

1. 构造函数：**派生类的构造函数必须调用基类的构造函数 初始化基类的那一部分成员**。**如果基类没有默认的构造函数，则必须在派生类构造函数的初始化列表阶段显示调用**
2. 拷贝构造：派生类的拷贝构造函数必须调用基类的拷贝构造 完成基类的拷贝初始化
3. 赋值重载：派生类的operator=必须要调用基类的operator=完成基类的复制
4. 析构函数：派生类的析构函数会**在被调用完成后自动调用基类的析构函数清理基类成员**。因为这样才能**保证派生类对象先清理派生类成员再清理基类成员**的顺序
5. **派生类对象初始化先调用基类构造再调派生类构造**。**派生类对象析构清理先调用派生类析构再调基类的析构**

```cc
class Person
{
public:
	Person(string name, int age)
		:_name(name),
		_age(age)
	{
		cout << "Person(string name, int age) 基类构造" << endl;
	}

	Person(const Person& t): _name(t._name),_age(t._age)
	{
		cout << "Person(const Person & t) 基类拷贝构造" << endl;
	}

	Person& operator==(const Person& t)
	{
		if (this != &t)
		{
			_name = t._name;
			_age = t._age;
		}
		cout << "Person& operator==(const Person& t) 基类赋值" << endl;
		return *this;
	}

	Person(Person&& t)
		:_name(std::forward<std::string>(t._name)),_age(t._age)
	{
		cout << "Person(Person&& t) 基类移动构造" << endl;
	}

	Person& operator==(Person&& t)
	{
		if (this != &t)
		{
			_name = std::forward<std::string>(t._name);
			_age = t._age;
		}
		cout << "Person& operator==(const Person& t) 基类移动赋值" << endl;
		return *this;
	}

	~Person()
	{
		cout << "~Person() 基类析构" << endl;
	}

	void print()
	{
		cout << _name << endl << _age << endl;
	}
protected:
	string _name;
	int _age;
};

class Student :public Person
{
public:
	Student(string name, int age, int stdid)
		:Person(name, age),
		_stdid(stdid)
	{
		cout << "Student(string name, int age, int stdid) 派生类构造" << endl;
	}

	Student(const Student& s)
		:Person(s), // 利用&引用切片
		_stdid(s._stdid)
	{
		cout << "Student(const Student & s) 派生类拷贝构造" << endl;
	}

	Student& operator==(const Student& s)
	{
		if (this != &s)
		{
			Person::operator==(s); // 利用&引用切片
			_stdid = s._stdid;
		}
		cout << "Student& operator==(const Student& s) 派生类赋值" << endl;
		return *this;
	}

	Student(Student&& s):Person(std::forward<Person>(s)), _stdid(s._stdid)
	{
		cout << "Student(Student&& s) 派生类移动构造" << endl;
	}

	Student& operator==(Student&& s)
	{
		if (this != &s)
		{
			Person::operator==(std::forward<Person>(s)); // 利用&引用切片
			_stdid = s._stdid;
		}
		cout << "Student& operator==(Student&& s) 派生类移动赋值" << endl;
		return *this;
	}

	~Student()
	{
		cout << "~Student() 派生类析构" << endl;
	}

	void print()
	{
		cout << _name << _age << _stdid << endl;
	}
protected:
	int _stdid;
};

int main()
{
	Student s("coke", 22, 21);
	cout << "-------------------------------------" << endl;
	Student s1 = s; // 拷贝构造
	cout << "-------------------------------------" << endl;
	s == s1;		// 赋值
	cout << "-------------------------------------" << endl;
	Student s2(move(s));
	cout << "-------------------------------------" << endl;
	s1 == move(s2);
	cout << "-------------------------------------" << endl;

	return 0;
}
```

结果：

> Person(string name, int age) 基类构造
>
> Student(string name, int age, int stdid) 派生类构造
>
> ----------------------------------------------------------------------------------------------
>
> Person(const Person & t) 基类拷贝构造
>
> Student(const Student & s) 派生类拷贝构造
>
> ----------------------------------------------------------------------------------------------
>
> Person& operator==(const Person& t) 基类赋值
>
> Student& operator==(const Student& s) 派生类赋值
>
> ----------------
>
> Person(Person&& t) 基类移动构造
>
> Student(Student&& s) 派生类移动构造
>
> ----
>
> Person& operator==(const Person& t) 基类移动赋值
>
> Student& operator==(Student&& s) 派生类移动赋值
>
> ---
>
> ~Student() 派生类析构
> ~Person() 基类析构
> ~Student() 派生类析构
> ~Person() 基类析构
> ~Student() 派生类析构
> ~Person() 基类析构



**总结：只有析构是先析构派生类再析构基类，其他默认成员函数的调用顺序都一样相反**

**原因：对于构造类，规则是初始化顺序由声明的顺序决定，继承的声明在类最开始的时候；对于析构，由于派生类的成员变量使用了基类的成员（例如指针引用），可能造成析构错误，或者二次析构**

网上的解答：

在面向对象编程中，一个对象可能拥有需要手动释放的资源，如动态分配的内存、文件句柄、网络连接等。派生类可能在其构造函数中分配这些资源，并在其析构函数中释放它们。如果基类的析构函数在派生类的析构函数之前被调用，那么派生类释放资源的代码将无法访问这些资源，因为它们可能已经被基类析构函数中的代码释放或改变了。因此，先调用派生类的析构函数可以确保派生类在基类之前释放其拥有的资源。

### 继承与友元和静态成员

**友元关系不能继承**，也就是说**基类友元不能访问子类私有和保护成员**

**基类定义了static静态成员，则整个继承体系里面只有一个这样的成员**。无论派生出多少个子类，都只有一个static成员实例

### 菱形继承

单继承：一个子类只有一个直接父类时称这个继承关系为单继承

多继承：一个子类有两个或以上直接父类时称这个继承关系为多继承

菱形继承：

<img src="E:\markdown\img\菱形继承.png" alt="菱形继承" style="zoom:60%;" />

菱形继承的问题：从下面的对象成员模型构造，可以看出**菱形继承有数据冗余和二义性的问题**。

_name在Assistant的对象中Person成员会有两份

<img src="E:\markdown\img\菱形继承2.png" alt = "菱形继承" style="zoom:60%;" />

```cc
class Person
{
public:
	string _name; // 姓名
};
class Student : public Person
{
protected:
	int _num; //学号
};
class Teacher : public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};
void Test()
{
	// 这样会有二义性无法明确知道访问的是哪一个
	Assistant a;
	//a._name = "peter";
	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
}

int main()
{
	Test();
	return 0;
}
```

<img src="E:\markdown\img\菱形继承内存图.png"  />

**虚拟继承可以解决菱形继承的二义性和数据冗余的问题。**

如上面的继承关系，在Student和 Teacher的继承Person时使用虚拟继承，即可解决问题。需要注意的是，虚拟继承不要在其他地 方去使用。

在基础重复的基类时 virtual 继承

<img src="E:\markdown\img\虚继承.png" style="zoom: 80%;" />

<img src="E:\markdown\img\虚继承内存结构.png"  />



**虚基表包含：**

- **偏移量（Offset）**:虚基表中存放的是偏移量，这些偏移量用于确定从派生类对象的起始地址到虚基类成员的实际内存地址的偏移量。在菱形继承中
- **以NULL结尾（编译器不同情况下不一样，适用于VS）**：与虚函数表（virtual function table，简称虚表或V-Table）类似，虚基表也是以NULL结尾的。这标识了表的结束，方便程序在遍历或访问表时知道何时停止。

在g++编译器下，一般采用在虚函数表中放置虚基类的偏移量的方式

### 继承和组合

- **public继承是一种is-a的关系**。也就是说每个派生类对象都是一个基类对象。 
- **组合是一种has-a的关系**。假设B组合了A，每个B对象中都有一个A对象。
- **优先使用对象组合，而不是类继承** 。
- 继承允许你根据基类的实现来定义派生类的实现。这种通过生成派生类的复用通常被称 为白箱复用(white-box reuse)。术语“白箱”是相对可视性而言：在继承方式中，基类的内部细节对子类可见 。继承一定程度破坏了基类的封装，基类的改变，对派生类有很 大的影响。派生类和基类间的依赖关系很强，耦合度高。 
- 对象组合是类继承之外的另一种复用选择。新的更复杂的功能可以通过组装或组合对象 来获得。对象组合要求被组合的对象具有良好定义的接口。这种复用风格被称为黑箱复 用(black-box reuse)，因为对象的内部细节是不可见的。对象只以“黑箱”的形式出现。  组合类之间没有很强的依赖关系，耦合度低。优先使用对象组合有助于你保持每个类被 封装。 
- 实际尽量多去用组合。**组合的耦合度低，代码维护性好**。不过继承也有用武之地的，有些关系就适合继承那就用继承，另外**要实现多态，也必须要继承**。类之间的关系可以用继承，可以用组合，就用组合。

## 6. 多态（重点）

### 什么是多态？

概念：通俗来说，就是多种形态，具体点就是去完成某个行为，**当不同的对象去完成时会 产生出不同的状态**

**静态的多态（编译时）**：

- 函数重载，利用参数匹配和函数名修饰规则
- 模板，利用模板根据参数实例化

**动态的多态（运行时）**

和指向对象有关

### **构成条件**

1. **父子类，继承关系**

2. **虚函数重写**

   > 虚函数：父类虚函数，子类的虚函数可以不加virtual
   >
   > 重写：三同，特例协变和析构，具体看下面

3. **父类指针或者引用调用虚函数**

结果：指向父类调用父类虚函数，指向子类调用子类虚函数

### 重写（覆盖）

首先，必须要是虚函数，重写叫做**虚函数的重写**

派生类中有一个跟基类**完全相同**的虚函数(即派生类虚函数与基类虚函数的 **返回值类型、函数名字、参数列表完全相同**)，称子类的虚函数重写了基类的虚函数

```cc
class Person 
{
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person 
{
public:
	void BuyTicket() { cout << "买票-半价" << endl; } // 可以不加virtual但是不建议
};

void Func(Person& p) // 切片
{
	p.BuyTicket();
}

int main()
{
	Person ps;
	Student st;
	Func(ps);
	Func(st);
	return 0;
}
```

**重写的特例**：

1. **协变（基类与派生类虚函数返回值类型不同）**

派生类重写基类虚函数时，与基类虚函数**返回值类型不同**。即基类虚函数返回**基类对象的指针或者引用**，派生类虚函数**返回派生类对象的指针或者引用**时，称为**协变**

常见的使用场景：operator==重写，返回值必须是该对象的引用，所以存在使用场景，规则做出的妥协

2. **析构函数的重写（基类与派生类析构函数的名字不同）**

编译器对析构函数的名称做了特殊处理，**编译后析构函数的名称统一处理成destructor**，这样函数名就相同了

析构函数建议是虚函数

### 纯虚函数

**在虚函数的后面写上 =0 ，则这个函数为纯虚函数**

**包含纯虚函数的类叫做抽象类（也叫接口类），抽象类不能实例化出对象**，只有重写纯虚函数，派生类才能实例化出对象

纯虚函数规范了派生类必须重写，另外纯虚函数更体现出了接口继承

抽象类的作用：

1. 定义接口

   > 纯虚函数常用于定义接口类。接口类是一种只包含纯虚函数的类，它定义了一组操作，但具体的实现由派生类提供。这样，不同的派生类可以根据需要实现不同的行为，而接口类则提供了一个统一的访问方式

2. 实现多态（可以使用抽象类指针类型）

3. 间接强制派生类的重写实现（不重写就还是抽象类）

```cc
class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
	virtual void Drive() {
		cout << "Benz-舒适" << endl;
	}
};
class BMW :public Car
{
public:
	virtual void Drive() {
		cout << "BMW-操控" << endl;
	}
};

void func(Car* car)
{
	car->Drive();
}

void Test()
{
	Benz* pBenz = new Benz;
	BMW* pBMW = new BMW;
	func(pBenz);
	func(pBMW);
}

int main()
{
	Test();
	return 0;
}
```

普通函数的继承是一种**实现继承**，派生类继承了基类函数，可以使用函数，**继承的是函数的实现**。

虚函数的继承是一种**接口继承**，派生类**继承的是基类虚函数的接口**，目的是为了重写，达成多态，继承的是接口

### 重载、覆盖(重写)、隐藏(重定义)的对比

![](E:\markdown\img\重载、覆盖(重写)、隐藏(重定义)的对比.png)

### override/final

从上面可以看出，C++对函数重写的要求比较严格，但是有些情况下由于疏忽，可能会导致函数名字母次序写反而无法构成重载，而这种错误在编译期间是不会报出的，只有在程序运行时没有 得到预期结果才来debug会得不偿失，因此：**C++11提供了override和final两个关键字，可以帮助用户检测是否重写**
**1. final：修饰虚函数，表示该虚函数不能再被重写，若重写编译报错（在基类虚函数修饰）**

```cc
class Person {
public:
	virtual ~Person() final { cout << "~Person()" << endl; }
};
 
class Student : public Person {
public:
	virtual ~Student() { cout << "~Student()" << endl; }
};
```

> 报错："Person::~Person": 声明为 "final" 的函数不能由 "Student::~Student" 重写

**2. override(重写覆盖) 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错。（在派生类虚函数修饰）**

```cc
class Person {
public:
	~Person() { cout << "~Person()" << endl; }
};
 
class Student : public Person {
public:
	virtual ~Student() override { cout << "~Student()" << endl; }
};
```

> 报错：“Student::~Student”: 包含重写说明符“override”的方法没有重写任何基类方法

### 多态原理

**虚函数表**

```cc
// 在32位平台下，sizeof(Base)等于多少？
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;
};
 
int main()
{
	Base b;
	cout << sizeof(Base) << endl;
	return 0;
}
```

通过观察测试我们发现b对象是8bytes，**除了_b成员，还多一个__vfptr放在对象的前面**(注意有些平台可能会放到对象的最后面，这个跟平台有关)，**对象中的这个指针我们叫做虚函数表指针**(v代 表virtual，f代表function)。**一个含有虚函数的类中都至少都有一个虚函数表指针，因为虚函数的地址要被放到虚函数表中，虚函数表也简称虚表**

在多继承的情况下，如果多个基类都包含虚函数指针，那么这个派生类就需要多个虚函数指针

**虚函数表本质是一个存虚函数指针的指针数组**，在vs下这个数组最后面放了一个nullptr

总结一下派生类的虚表生成（编译阶段）：

1. 先将基类中的虚表内容**拷贝**一份到派生类虚表中
2. 如果派生类重写了基类中某个虚函数，用派生类自己的虚函数**覆盖**虚表中基类的虚函数
3. 派生类自己新增加的虚函数按其在派生类中的声明次序**增加**到派生类虚表的**最后**

**虚函数指针生成在构造函数的初始化列表**（编译器自动）

虚函数存在代码段，虚表存在代码段（常量区）

```cc
// 虚函数表打印
class Person
{
public:
	virtual void BuyTicket() {
		cout << "买票全价" << endl;
	}
 
	virtual void Func() {
		cout << _id << endl;
		BuyTicket();
	}
protected:
	int _id = 1;
};
 
class Student :public Person
{
public:
	void BuyTicket() {
		cout << "买票半价" << endl;
	}
 
protected:
	int _id = 2;
};
 
typedef void(*VFPtr) ();
 
void PrintVFTable(VFPtr* p)
{
	for (int i = 0; p[i] != nullptr; ++i)
	{
		printf("[%d] -> %p\n", i, p[i]);
	}
	cout << endl;
}
 
int main()
{
	Person p;
	Student s;
 
	PrintVFTable(*(VFPtr**)&p);
	PrintVFTable(*(VFPtr**)&s);
	return 0;
}
```

<img src="E:\markdown\img\虚函数表.png" style="zoom:67%;" />

**动态绑定与静态绑定**

1. **静态绑定又称为前期绑定(早绑定)**，在程序编译期间确定了程序的行为，也称为静态多态， 比如：函数重载

2. **动态绑定又称后期绑定(晚绑定)**，是在程序运行期间，根据具体拿到的类型确定程序的具体 行为，调用具体的函数，也称为动态多态

### 多继承关系的虚函数表（拓展）

**多继承派生类的虚表个数与继承基类个数相关**

**多继承派生类的虚表生成顺序与继承声明顺序有关**

**多继承派生类的未重写的虚函数 放在 第一个继承基类部分的虚函数表（第一个虚表） 的最后**

![](E:\markdown\img\多继承关系的虚函数表.png)

---

### 面试题

以下关于纯虚函数的说法,正确的是( ) 

- 声明纯虚函数的类不能实例化对象 		
- 子类必须实现基类的纯虚函数                
- 声明纯虚函数的类是虚基类 
- 纯虚函数必须是空函数

关于虚表说法正确的是（ ） 

- 一个类只能有一张虚表 
- 基类中有虚函数，如果子类中没有重写基类的虚函数，此时子类与基类共用同一张虚表 
- 虚表是在运行期间动态生成的 
- 一个类的不同对象共享该类的虚表

关于虚函数的描述正确的是( )          

- 派生类的虚函数与基类的虚函数具有不同的参数个数和类型      
- 内联函数不能是虚函数                    
- 派生类必须重新定义基类的虚函数       
- 虚函数可以是一个static型的函数 

> A D B

程序结果

菱形继承初始化顺序问题

```cc
class A {
public:
	A(char* s) { cout << s << endl; }
	~A() {}
};
class B :virtual public A
{
public:
	B(char* s1, char* s2) :A(s1) { cout << s2 << endl; }
};
class C :virtual public A
{
public:
	C(char* s1, char* s2) :A(s1) { cout << s2 << endl; }
};
class D :public B, public C
{
public:
	D(char* s1, char* s2, char* s3, char* s4) :B(s2, s2), C(s3, s3), A(s1)
	{
		cout << s4 << endl;
	}
};
int main() {
	char a[] = "class A";
	char b[] = "class B";
	char c[] = "class C";
	char d[] = "class D";
	D* p = new D(a, b, c, d);
	delete p;
	return 0;
}
```

> class A class B class C class D

多继承的指针偏移问题

```cc
class Base1 { public:  int _b1; };
class Base2 { public:  int _b2; };
class Derive : public Base1, public Base2 { public: int _d; };
int main() {
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	return 0;
}
```

> p1 == p3 < p2

接口继承参数问题

```cc
class A
{
public:
    virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
    virtual void test() { func(); }
};
 
class B : public A
{
public:
    void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};
 
int main()
{
    B* p = new B;
    p->test();
    return 0;
}
```

> B->1

![](E:\markdown\img\接口继承参数问题.png)

问答：

1. 什么是多态？

> 多种形态，为了完成某种行为，不同的对象调用会产生不同的结果
>

2. 什么是重载、重写(覆盖)、重定义(隐藏)？

> 重载是在同一类域中，函数名相同，参数不同，本质上是利用C++函数的修饰规则实现的调用
>
> 重定义体现在继承关系中，分别在基类和派生类的两个函数，且函数名相同就构成重定义，基类的函数被隐藏，可以显示调用
>
> 重写是在重定义的基础上，两个函数都是虚函数，且函数名，返回值类型和参数类型都相同就构成重写
>

3. 多态的实现原理？

> 在包含虚函数的类，在编译过程中，会在代码段（常量区）生成一张虚函数表，里面包含虚函数的指针。
>
> 通过这个类定义的对象，被实例化的过程中，编译器会通过初始化列表定义一个虚表指针指向这个虚表。
>
> 基类对象的指针或引用调用虚函数时，编译器就会通过对象的虚表指针进一步找到虚函数的地址
>

4. 虚函数可以加inlin吗？

> 可以，加inline可以，但加了也没用
>
> 要变成内联函数，由于内联函数是直接展开代码，并不存在函数调用，即没有函数地址，但如果要是虚函数就必须要有虚表，虚表就是存虚函数地址的
>
> 是内联函数就不是虚函数，是虚函数就不是内联函数
>

5. 静态成员函数可以是虚函数吗

> 不行，静态成员函数不可以是虚函数。静态函数是属于类的，不属于对象本身，静态成员函数没有this指针，就找不到虚函数表指针
>

6. 构造函数可以是虚函数吗？

> 不行，因为对象中的虚函数表指针是在构造函数初始化列表阶段才初始化的。实例化对象需要构造函数，调用构造函数需要虚表指针，虚表指针还没有被实例化出来
>

7. 析构函数可以是虚函数吗？

> 可以，并且最好把基类的析构函数定义成虚函数
>

8. 对象访问普通函数快还是虚函数更快？

> 首先如果是普通对象，是一样快的。如果是指针对象或者是引用对象，则调用的普通函数快，因为多态调用，运行时调用虚函数需要到虚函数表中去查找
>

9. 虚函数表是在什么阶段生成的，存在哪的？

> 虚函数表是在编译阶段就生成的，一般情况下存在代码段(常量区)的。
>

10.C++菱形继承的问题？虚继承的原理？

> 数据冗余和二义性
>
> 在虚继承的基类成员统一开辟一块区域存储，用虚基表记录偏移量，通过虚基表指针找到偏移量进而找到
>

11.什么是抽象类？抽象类的作用？

> 在虚函数的后面写上 =0 ，则这个函数为纯虚函数。包含纯虚函数的类叫做抽象类（也叫接口类）
>
> 抽象类不能实例化出对象。派生类继承后也不能实例化出对象，只有重写纯虚函数，派生类才能实例化出对象。
>
> 纯虚函数规范了派生类必须重写，另外纯虚函数更体现出了接口继承。
>
> 1. 定义接口
> 2. 实现多态
> 3. 间接强制子类实现虚函数重写

## 7. C++11

### 范围for

使用格式

```cc
vector<int> v = { 1,2,3,4,5 };
for (auto e : v)
{
	cout << e << " ";
}
cout << endl;
```

底层原理，使用迭代器

```cc
vector<int> v = { 1,2,3,4,5 };
auto it = v.begin();
while (it != v.end())
{
	cout << *it << " ";
	++it;
}
cout << endl;
```

### 右值引用的移动语义

#### **什么是左值，什么又是右值？**

左值，可以取地址，可以对内容进行修改

```cc
int main()
{
	// 以下的p、b、c、*p都是左值
	int* p = new int(0);
	int b = 1;
	const int c = 2;
 
	// 以下几个是对上面左值的左值引用
	int*& rp = p;
	int& rb = b;
	const int& rc = c;
	int& pvalue = *p;
	return 0;
}
```

右值，不可以取地址，不可以对内容进行修改，例如：临时变量

- **函数返回值（不能是左值引用返回）**
- **表达式返回值**
- **匿名对象**
- **字面常量**

```cc
int main()
{
	double x = 1.1, y = 2.2;
	// 以下几个都是常见的右值
	10;
	x + y;
	fmin(x, y);
	// 以下几个都是对右值的右值引用
	int&& rr1 = 10;
	double&& rr2 = x + y;
	double&& rr3 = fmin(x, y);
	// 这里编译会报错：error C2106: “=”: 左操作数必须为左值
	// 10 = 1;
	// x + y = 1;
	// fmin(x, y) = 1;
	return 0;
}
```

#### **什么是左值引用，什么是右值引用？**

**无论左值引用还是右值引用，都是给对象取别名**

> 需要注意的是右值是不能取地址的，但是给右值取别名后，会导致右值被存储到特定位置，且可以取到该位置的地址
>
> 也就是说例如：不能取字面量10的地址，但是rr1引用后，可以对rr1取地址，也可以修改rr1。如果不想rr1被修改，可以用const int&& rr1 去引用
>
> 把字面量存储在了栈上，后面使用时取地址就是栈空间上的地址，修改也是
>
> 这是一种特性

- **左值引用只能引用左值，不能引用右值**
- **但是const左值引用既可引用左值，也可引用右值**
- **右值引用只能右值，不能引用左值**
- **但是右值引用可以move以后的左值**

当需要用右值引用引用一个左值时，可以通过move函数将左值转化为右值，move本质是一个函数，**唯一的功能就是将一个左值强制转化为右值引用，然后实现移动语义**

#### **右值引用的使用场景，如何提高效率**

左值引用的使用场景：做参数和做返回值都可以提高效率。（对于自定义类型）

左值引用的短板：**但是当函数返回对象是一个局部变量，出了函数作用域就不存在了，就不能使用左值引用返回， 只能传值返回**

例如： string operator+(const string& str)

<img src="E:\markdown\img\移动构造.png" style="zoom: 80%;" />

传值返回就会导致，两次拷贝构造，在编译器优化后可能会优化掉第一次的拷贝构造，但是返回值做为参数的拷贝构造是少不了的

**这个返回值是一个临时对象，也就是右值，将亡值，这个临时对象在拷贝之后也是要析构的，可不可以利用一下这个资源呢？**

**通过右值引用和移动语义解决上述问题**

#### **移动构造和移动赋值**

**在bit::string中增加移动构造，移动构造本质是将参数右值的资源窃取过来，占位已有，那么就不用做深拷贝了，所以它叫做移动构造，就是窃取别人的资源来构造自己。**

**不仅仅有移动构造，还有移动赋值**

```cc
namespace kele
{
    class string
    {
    public:
        string(const char* str = "")//构造
            :_size(strlen(str))
        {
            cout << "构造" << endl;
            _capacity = _size == 0 ? 3 : _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }
 
        string(const string& str)//拷贝构造
            :_str(nullptr)
        {
            cout << "string(const string & str)//拷贝构造" << endl;
            string tmp(str._str);
            swap(tmp);
        }
 
        string(string&& str)//移动构造
            :_str(nullptr),
            _size(0),
            _capacity(0)
        {
            cout << "string(string&& str)//移动构造" << endl;
            swap(str);
        }
 
        string& operator=(string& str)//赋值重载
        {
            if (this != &str)
            {
                cout << "string& operator=(string str)//赋值重载" << endl;
                string tmp(str._str);
                swap(tmp);
                return *this;
            }
        }
 
        string& operator=(string&& str)//移动赋值重载
        {
            if (this != &str)
            {
                cout << "string& operator=(string&& str)//移动赋值重载" << endl;
                swap(str);
                return *this;
            }
        }
 
        void reserve(size_t n = 0)
        {
            if (n > _capacity)
            {
                char* tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }
        string& operator+=(const string& s)
        {
            size_t n = s._size;
            if (_size + n > _capacity)
            {
                reserve(_capacity + n);
            }
            strcpy(_str + _size, s._str);
            _size += n;
            return *this;
        }
 
        string operator+(const string& str)
        {
            string tmp(_str);
            tmp += str;
            return tmp;
        }
 
        ~string()
        {
            delete[] _str;
            _size = _capacity = 0;
        }
 
        void swap(string& s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }
    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    };
}
```

#### **完美转发**

模板中的&& **万能引用**：

**模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值**

模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力

但是引用类型的**唯一作用就是限制了接收的类型，后续使用中都退化成了左值**

因为如果要进行移动构造需要对其内容做修改（必须是左值）

我们希望能够在**传递过程中保持它的左值或者右值的属性**, 就需要用我们下面学习的**完美转发（forward）**

forward可以看作是带模板的类

```cc
void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }
 
void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }
 
template<typename T>
void PerfectForward(T&& t)
{
    //Fun(t);
	Fun(forward<T>(t));完美转发
}
int main()
{
	PerfectForward(10);           	// 右值
	int a;
	PerfectForward(a);            	// 左值
	PerfectForward(std::move(a)); 	// 右值
	const int b = 8;
	PerfectForward(b);     	 		// const 左值
	PerfectForward(std::move(b)); 	// const 右值
	return 0;
}
```

#### **push和emplace系列的区别**

```cc
// vector
void push_back (const value_type& val); // 拷贝构造对象插入
void push_back (value_type&& val);		// 移动构造（构造 + 交换）对象插入
template <class... Args>
void emplace_back (Args&&... args);		// 构造对象插入
```

利用模板可变参数和万能引用拿到构造对象所需的参数，再调用对应的对象构造函数

**虽然相对于push_back而言，emplace_back有效率上的提升，但是移动拷贝的代价足够小，所有提升不大，但是对于一些包含大量内置类型的类还是有不错的提升的**

对于深拷贝的类，移动构造足够快，但是对于浅拷贝的类，emplace更有优势

### lambda

lambda表达式书写格式：

**[capture-list] (parameters) mutable ->return-type { statement }**

捕捉列表	参数列表	可变性	返回值类型	函数体

```cc
auto sub_lambda = [](int x, int y) {return x - y; };
```

- **[capture-list] :  捕捉列表**该列表总是出现在lambda函数的开始位置，编译器根据[]来判断接下来的代码是否为lambda函数，捕捉列表能够捕捉上下文中的变量供lambda 函数使用
- **(parameters)：参数列表**与普通函数的参数列表一致，如果不需要参数传递，则可以连同()一起省略
- **mutable：可变性**默认情况下，lambda函数总是一个const函数，mutable可以取消其常量性。使用该修饰符时，参数列表不可省略(即使参数为空)
- **->returntype：返回值类型**用追踪返回类型形式声明函数的返回值类型，没有返回值时此部分可省略。返回值类型明确情况下，也可省略，由编译器对返回类型进行推导
- **{statement}：函数体**在该函数体内，除了可以使用其参数外，还可以使用所有捕获到的变量

> 注意： 在lambda函数定义中，参数列表和返回值类型都是可选部分，而捕捉列表和函数体可以为空。
>
> 因此C++11中最简单的lambda函数为：[]{}; 该lambda函数不能做任何事情。



lambda表达式实际上可以理解为**无名函数（匿名）**，该函数无法直接调用，如果想要直接调用，可借助auto将其赋值给一个变量。

捕获列表说明：

捕捉列表描述了上下文中那些数据可以被lambda使用，以及使用的方式传值还是传引用

- [var]：表示值传递方式捕捉变量var
- [=]：表示值传递方式捕获所有父作用域中的变量(包括this)
- [&var]：表示引用传递捕捉变量var
- [&]：表示引用传递捕捉所有父作用域中的变量(包括this)
- [this]：表示值传递方式捕捉当前的this指针

**注意：**

1. 父作用域指包含lambda函数的语句块
2. 语法上捕捉列表可由多个捕捉项组成，并以逗号分割。
3. 捕捉列表不允许变量重复传递，否则就会导致编译错误。
4. 在块作用域以外的lambda函数捕捉列表必须为空。
5. 在块作用域中的lambda函数仅能捕捉父作用域中局部变量，捕捉任何非此作用域或者非局部变量都会导致编译报错
6. lambda表达式之间不能相互赋值，即使看起来类型相同

> class `int __cdecl main(void)'::`2'::<lambda_1> lambda表达式类型

**实际在底层编译器对于lambda表达式的处理方式，完全就是按照函数对象的方式处理的，即：如果定义了一个lambda表达式，编译器会自动生成一个类，在该类中重载了operator()**

### function/bind（了解）

function包装器也叫作适配器。C++中的function本质是一个类模板，也是一个包装器

**函数指针的类型非常的难用**

**仿函数又太复杂了，麻烦**

**lambda是匿名对象，没法显示类型**

这些都各有弊端，**而且因为是不同的类型，当类模板接收这些类型，还需要实例化不同的几份**，所有，能不能把他们都包装一下，形成统一的类型呢？

**std::function在头文件<functional>中**

```cc
template <class Ret, class... Args>
class function<Ret(Args...)>;
```

模板参数说明： **Ret: 被调用函数的返回类型 Args…：被调用函数的形参** 

```cc
typedef function<int(int,int)> func_t;
// 等价于
using func_t = function<int(int,int)>;
```

例子：

```cc
#include <functional>
#include <string>
#include <map>
 
typedef function<int(int, int)> func_t;
 
typedef int(*func_ptr)(int, int);
 
int sub_fun(int x, int y)
{
	return x - y;
}
 
class sub_class
{
public:
	int operator()(int x, int y)
	{
		return x - y;
	}
};
 
int main()
{
	auto sub_lambda = [](int x, int y) {return x - y; };
 
	func_t sub[] = { sub_fun, sub_class(), sub_lambda };
	cout << sub[0](1, 3) << endl;
	cout << sub[1](1, 3) << endl;
	cout << sub[2](1, 3) << endl;
 
	map<string, func_t> m = {
		{"函数指针", sub_fun },
		{"仿函数", sub_class() },
		{"lambda表达式", sub_lambda },
	};
	cout << m["函数指针"](1,3);
	cout << m["仿函数"](1,3);
	cout << m["lambda表达式"](1,3);
 
 
	return 0;
}
```

**function包装类内的成员函数**

对于静态成员函数

```cc
function<int(int, int)> f1 = sub_class::static_sub;
```

对于普通成员函数

```cc
function<int(sub_class*, int, int)> f1 = &sub_class::sub;
// 等价于
function<int(sub_class, int, int)> f2 = &sub_class::sub;
```

因为普通成员函数参数的第一个是this指针，所以要有class*，也可以用class（为了方便bind）

拓展知识：

- 对于非静态成员函数，函数指针的赋值需要使用&
- 使用 **.\*** (实例对象)或者 **->\***（实例对象指针）调用类成员函数指针所指向的函数

非静态成员函数指针可以不传this的原因是，使用时必须实例化

对于虚函数，编译时函数指针的地址是未定义的（待实例化确定g++）

拓展中的拓展：
在类内的成员变量也可以当作函数，返回值是变量，参数是类，可以function和bind，实在是想不出使用场景[笑哭]

```cc
class sub_class
{
public:
	static int _sub(int x, int y){
		return x - y;
	}
	int sub(int x, int y){
		return x - y;
	}
};
 
int main()
{
	function<int(int, int)> f1 = &sub_class::_sub;// 对于类静态成员函数，需要指定类域，可以不加&
	cout << f1(1, 3) << endl;
 
	function<int(sub_class*, int, int)> f2 = &sub_class::sub;// 对于成员函数，隐藏了this指针，而且需要加&符号
	sub_class pc;
	cout << f2(&pc, 1, 3) << endl;// 匿名对象属于临时变量，右值不能取地址
 
	function<int(sub_class, int, int)> f3 = &sub_class::sub;// 对于成员函数，隐藏了this指针，而且需要加&符号
	cout << f3(sub_class(), 1, 3) << endl;// 编译器的特殊处理，传类型，其实如果成员函数使用了类内成员是临时变量的
 
	// 绑定bind
	// 可以改变参数的位置，也可以改变参数的数量，通过写死
	function<int(int, int)> f4 = bind(&sub_class::sub, sub_class(), placeholders::_1, placeholders::_2);
	cout << f4(1, 3) << endl;

	return 0;
}
```

**bind**

**std::bind函数定义在头文件<functional>中，是一个函数模板，它就像一个函数包装器(适配器)，接受一个可调用对象（callable object），生成一个新的可调用对象来“适应”原对象的参数列表**

一般而言，我们用它可以把一个原本接收N个参数的函数fn，通过绑定一些参数，返回一个接收M个（M 可以大于N，但这么做没什么意义）参数的新函数。同时，使用std::bind函数还可以实现参数顺序调整等操作

相当于对函数进行封装，来调整参数的位置顺序，也可以通过写死一些参数，减少参数个数

```cc
// 原型如下：
template <class Fn, class... Args>
bind (Fn&& fn, Args&&... args); /* unspecified */ 
// with return type (2) 
template <class Ret, class Fn, class... Args>
bind (Fn&& fn, Args&&... args); /* unspecified */ 
```

使用格式：

**auto newCallable = bind(callable,arg_list)**

newCallable本身是一个可调用对象，arg_list是一个逗号分隔的参数列表，对应给定的 callable的参数。当我们调用newCallable时，newCallable会调用callable,并传给它arg_list中的参数

arg_list中的参数可能包含形如n的名字，其中n是一个整数，这些参数是“占位符”，表示 newCallable的参数，它们占据了传递给newCallable的参数的“位置”。数值n表示生成的可调用对 象中参数的位置：_1为newCallable的第一个参数，_2为第二个参数，以此类推。

```cc
void func(int a, int b, int c)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
 
int main()
{
	function<void(int, int, int)> f1 = bind(func, placeholders::_1, placeholders::_2, placeholders::_3);
	f1(1, 2, 3);
 
	function<void(int, int)> f2 = bind(func, placeholders::_1, 2, placeholders::_2);
	// placeholders的参数数字对应的是函数调用时要填入参数的顺序和个数
	f2(1, 3);
    
	return 0;
}
```

### 线程库

#### **thread**

在C++11之前，涉及到多线程问题，都是和平台相关的，比如**windows和linux下各有自己的接 口，这使得代码的可移植性比较差**。**C++11中最重要的特性就是对线程进行支持了，使得C++在 并行编程时不需要依赖第三方库，而且在原子操作中还引入了原子类的概念**。要使用标准库中的 线程，必须包含< thread >头文件

|            函数名             |                             功能                             |
| :---------------------------: | :----------------------------------------------------------: |
|           thread()            |  构造一个线程对象，没有关联任何线程函数，即没有启动任何线程  |
| thread(fn, args1, args2, ...) | 构造一个线程对象，并关联线程函数fn，args1，args2，...为线程函数的参数 |
|            jion()             |   该函数调用后会阻塞住线程，当该线程结束后，主线程继续执行   |
|           detach()            | 在创建线程对象后马上调用，用于把被创建线程与线程对象分离开，分离的线程变为后台线程，创建的线程的"死活"就与主线程无关 |
|           get_id()            |                          获取线程id                          |
|          jionable()           |    线程是否还在执行，joinable代表的是一个正在执行中的线程    |

1. **当创建一个线程对象后，没有提供线程函数，该对象实际没有对应任何线程**

2. **线程对象可以关联一个线程，用来控制线程以及获取线程的状态**

3. **当创建一个线程对象后，并且给线程关联线程函数，该线程就被启动，与主线程一起运行**

4.  线程函数一般情况下可按照以下三种方式提供

   - 函数指针

   - lambda表达式
   - 函数对象

5. **thread类是防拷贝的，不允许拷贝构造以及赋值，但是可以移动构造和移动赋值，即将一个线程对象关联线程的状态转移给其他线程对象，转移期间不影响线程的执行**

6.  可以通过jionable()函数判断线程是否是有效的，如果是以下任意情况，则线程无效

   - 采用无参构造函数构造的线程对象 
   - 线程对象的状态已经转移给其他线程对象 
   - 线程已经调用jion或者detach结束

 **线程函数参数**

线程函数的**参数是以值拷贝的方式拷贝到线程栈空间中**的

因此：**即使线程参数为引用类型，在线程中修改后也不能修改外部实参**，因为其实际引用的是线程栈中的拷贝，而不是外部实参

两种解决方式：1. **std::ref(参数)** 2. 传地址

**注意：如果是类成员函数作为线程参数时，必须将this作为线程函数参数**

> 在线程内获取线程id，this_thread::get_id();
>

**多线程最主要的问题是共享数据带来的问题(即线程安全)**，下面是解决线程安全的工具

#### **atomic**

头文件<atomic>

C++11中引入了原子操作，**程序员不需要对原子类型变量进行加锁解锁操作，线程能够对原子类型变量互斥的访问**

以使用atomic类模板，定义出需要的任意原子类型，只适用于整形类型（bool类型除外），提供++ -- 操作

**不允许原子类型进行拷贝构造、移动构造以及 operator=**

#### **mutex**

头文件<mutex>

C++11提供的最基本的互斥量，该类的对象之间不能拷贝，也不能进行移动。mutex最常用的三个函数

|   函数名   |                           函数功能                           |
| :--------: | :----------------------------------------------------------: |
|   lock()   |                       上锁：锁住互斥量                       |
|  unlock()  |                  解锁：释放对互斥量的所有权                  |
| try_lock() | 尝试锁住互斥量，如果互斥量被其他线程占有，则当前线程也不会被阻塞 |

> 拓展：
>
> std::recursive_mutex ：其允许同一个线程对互斥量多次上锁（即递归上锁），来获得对互斥量对象的多层所有权， 释放互斥量时需要调用与该锁层次深度相同次数的 unlock()
>

手动释放锁，经常容易导致忘记解锁而死锁，或者因为抛异常可能会导致锁没有释放，又或者有多个出作用域的地方每个地方都要手动释放锁比较麻烦，所以就有了RAII(资源获得即初始化)思想封装的guard系列锁

**lock_guard**

lock_guard类模板主要是通过RAII的方式，对其管理的互斥量进行了封装，**在需要加锁的地方，只需要用上述介绍的任意互斥体实例化一个lock_guard，调用构造函数成功上锁，出作用域前，lock_guard对象要被销毁，调用析构函数自动解锁，可以有效避免死锁问题**

lock_guard的缺陷：太单一，用户没有办法对该锁进行控制

**unique_lock**

与lock_guard不同的是，unique_lock更加的灵活，提供了更多的成员函数

- **上锁/解锁操作**：lock、try_lock、try_lock_for、try_lock_until和unlock
- **修改操作**：移动赋值、交换(swap：与另一个unique_lock对象互换所管理的互斥量所有权)、释放(release：返回它所管理的互斥量对象的指针，并释放所有权)
- **获取属性**：owns_lock(返回当前对象是否上了锁)、operator bool()(与owns_lock()的功能相 同)、mutex(返回当前unique_lock所管理的互斥量的指针)

#### condition_variable

条件变量属于资源，只能构造

|                  函数                  |                 函数功能                 |
| :------------------------------------: | :--------------------------------------: |
| void wait(**unique_lock**<mutex>& lck) |  在条件变量的等待队列中睡眠，并且释放锁  |
|           void notify_one()            |    从条件变量的等待队列中唤醒一个线程    |
|           void notify_all()            | 广播，唤醒条件变量的等待队列中的所有线程 |

练习题：

支持两个线程交替打印，一个打印奇数，一个打印偶数

```cc
#include <thread>
#include <mutex>
#include <condition_variable>
void two_thread_print()
{
	std::mutex mtx;
	condition_variable c;
	int n = 100;
	bool flag = true;
	
	thread t1([&]() {
		int i = 0;
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			c.wait(lock, [&]()->bool {return flag; });
			cout << i << endl;
			flag = false;
			i += 2; // 偶数
			c.notify_one();
		}
	});
	
	thread t2([&]() {
		int j = 1;
		while (j < n)
		{
			unique_lock<mutex> lock(mtx);
			c.wait(lock, [&]()->bool {return !flag; });
			cout << j << endl;
			j += 2; // 奇数
			flag = true;
			c.notify_one();
		}
	});
	t1.join();
	t2.join();
}
int main()
{
	two_thread_print();
	return 0;
}
```

### STL中的一些变化

容器中新增了<array><forwardlist><unordered_map><unordered_set>

std::initializer_list,统一列表初始化

移动构造

emplace系列

线程库<thread><mutex><atomic><condition_variable>

包装器<functonal>

## 8. 异常（考察少）

### 用法

异常是一种处理错误的方式，当一个函数发现自己无法处理的错误时就可以抛出异常，让函数的直接或间接的调用者处理这个错误

throw抛异常 try catch对异常进行捕获

try 块中放置可能抛出异常的代码，try 块中的代码被称为保护代码

**异常的抛出和匹配原则**

1. 异常是通过**抛出对象**而引发的，该**对象的类型决定了应该激活哪个catch的处理代码**
2. 被选中的处理代码是调用链中**与该对象类型匹配且离抛出异常位置最近的那一个** 
3. 抛出异常对象后，会生成一个**异常对象的拷贝**，因为抛出的异常对象可能是一个临时对象， 所以会生成一个拷贝对象，这个拷贝的临时对象会在**被catch以后销毁**。（这里的处理**类似于函数的传值返回**） 
4. **catch(...)可以捕获任意类型的异常**，问题是不知道异常错误是什么
5. 实际中抛出和捕获的匹配原则有个例外，并不都是类型完全匹配，可以**抛出的派生类对象， 使用基类捕获**，这个在实际中非常实用

**在函数调用链中异常栈展开匹配原则**

1. **首先检查throw本身是否在try块内部**，如果是再查找匹配的catch语句。如果有匹配的，则调到catch的地方进行处理。 
2. **没有匹配的catch则退出当前函数栈**，继续在**调用函数的栈中进行查找**匹配的catch。 
3. **如果到达main函数的栈，依旧没有匹配的，则终止程序**。上述这个沿着调用链查找匹配的 catch子句的过程称为栈展开。所以实际中我们最后都要加一个catch(...)捕获任意类型的异常，否则当有异常没捕获，程序就会直接终止。
4. **找到匹配的catch子句并处理以后，会继续沿着catch子句后面继续执行**

**异常的重新抛出** 在catch块内部最后throw就可以继续向外抛出

```cc
double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
   	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
   	// 重新抛出去。
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}
	// ...
	cout << "delete []" << array << endl;
	delete[] array;
}
int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}
```

**异常规范**

1. **异常规格说明的目的是为了让函数使用者知道该函数可能抛出的异常有哪些。 可以在函数的后面接throw(类型)，列出这个函数可能抛掷的所有异常类型**
2.  函数的后面接throw()，表示函数不抛异常。 
3.  若无异常接口声明，则此函数可以抛掷任何类型的异常

```cc
// 这里表示这个函数会抛出A/B/C/D中的某种类型的异常
void fun() throw(A，B，C，D);
// 这里表示这个函数只会抛出bad_alloc的异常
void* operator new (std::size_t size) throw (std::bad_alloc);
// 这里表示这个函数不会抛出异常
void* operator delete (std::size_t size, void* ptr) throw();
// C++11 中新增的noexcept，表示不会抛异常
thread() noexcept;
thread (thread&& x) noexcept;
```

throw()规范是给程序员看的，给调用接口的人知道会抛什么类型的异常，不强制不影响程序运行

**但是如果是C++11的关键字noexcept，表示函数不会抛异常，如果函数内部运行时抛异常了，就会直接崩溃**

**自定义异常体系**

实际使用中很多公司都会自定义自己的异常体系进行规范的异常管理，因为一个项目中如果大家 随意抛异常，那么外层的调用者基本就没办法玩了，所以实际中都会定义一套继承的规范体系。 这样大家抛出的都是继承的派生类对象，捕获一个基类就可以了

**利用的是类的继承，派生类重写基类的成员函数，再利用基础对象引用接受，利用的还是多态**

```cc
// 传派生类，基类接受，利用多态
class Exception
{
public:
	Exception(size_t errid, const string& errmsg)
		:_errid(errid),
		_errmsg(errmsg)
	{}
 
	virtual string what() const
	{
		return _errmsg;
	}
protected:
	size_t _errid;
	string _errmsg;
};
 
class Sql_Exception : public Exception
{
public:
	Sql_Exception(size_t id, const string& errmsg, const string& sql)
		:Exception(id,errmsg),
		_sql(sql)
	{}
 
	virtual string what() const
	{
		string str;
		str += _errmsg;
		str += " : ";
		str += _sql;
		return str;
	}
 
private:
	string _sql;
};
 
int main()
{
	try {
		Sql_Exception p(1, "写错了", "qeqawr");
		throw p;
	}
	catch (Exception& str)
	{
		cout << str.what() << endl;
	}
	
 
	return 0;
}
```

C++ 提供了一系列标准的异常，定义在<exception>中，我们可以在程序中使用这些标准的异常。它们是以父 子类层次结构组织起来的

### 异常的优缺点

**异常安全问题**

- 构造函数完成对象的构造和初始化，**最好不要在构造函数中抛出异常**，否则可能导致**对象不完整或没有完全初始化**
- 析构函数主要完成资源的清理，**最好不要在析构函数内抛出异常**，否则可能导致**资源泄漏**(内 存泄漏、句柄未关闭等)
-  C++中异常经常会导致**资源泄漏**的问题，比如在new和delete中抛出了异常，导致**内存泄漏**，在lock和unlock之间抛出了异常导致**死锁**，C++经常使用RAII来解决以上问题，关于RAII我们智能指针这节进行讲解

**异常的优点**：

1. 异常对象定义好了，**相比错误码的方式可以清晰准确的展示出错误的各种信息**，甚至可以包含堆栈调用的信息，这样可以**帮助更好的定位程序的bug**

2. **返回错误码**的传统方式有个很大的问题就是，在函数调用链中，**深层的函数返回了错误，那么我们得层层返回错误**，最外层才能拿到错误，**而抛异常会直接跳到捕获他的位置**

3. 很多的第三方库都包含异常，比如boost、gtest、gmock等等常用的库，那么我们使用它们也需要使用异常

4. **部分函数使用异常更好处理**，比如构造函数没有返回值，**不方便使用错误码方式处理**。比如 T& operator[]这样的函数，如果pos越界了只能使用异常或者终止程序处理，**没办法通过返回值表示错误**

**异常的缺点**：

1. **异常会导致程序的执行流乱跳，并且非常的混乱，并且是运行时出错抛异常就会乱跳**。这会导致我们跟踪调试时以及分析程序时，比较困难

2. **异常会有一些性能的开销**。当然在现代硬件速度很快的情况下，这个影响基本忽略不计

3. C++没有垃圾回收机制，资源需要自己管理。**有了异常非常容易导致内存泄漏、死锁等异常安全问题**。这个需要使用RAII来处理资源的管理问题。学习成本较高

4. **C++标准库的异常体系定义得不好**，导致大家各自定义各自的异常体系，非常的混乱

5. **异常尽量规范使用，否则后果不堪设想，随意抛异常，外层捕获的用户苦不堪言**。所以异常规范有两点：一、抛出异常类型都继承自一个基类。二、函数是否抛异常、抛什么异常，都使用 func（） throw();的方式规范化

总结：异常总体而言，利大于弊，所以工程中我们还是鼓励使用异常的。另外OO的语言基本都是用异常处理错误，这也可以看出这是大势所趋。

## 9. 智能指针

### 发展历史

在C++98中，auto_ptr管理权转移的思想，被诟病auto_ptr导致原对象悬空

C++11带来了 

- unique_ptr（不让拷贝和赋值） 
- shared_ptr（通过引用计数的方式来实现多个shared_ptr对象之间共享资源）
- weak_ptr（解决shared_ptr造成的循环引用问题）

1. C++ 98 中产生了第一个智能指针auto_ptr. 
2. C++ boost给出了更实用的scoped_ptr和shared_ptr和weak_ptr. 
3. C++ TR1，引入了shared_ptr等。不过注意的是TR1并不是标准版。 
4. C++ 11，引入了unique_ptr和shared_ptr和weak_ptr。需要注意的是unique_ptr对应boost 的scoped_ptr。并且这些智能指针的实现原理是参考boost中的实现的

### RAII

RAII（Resource Acquisition Is Initialization）是一种利用对象生命周期来控制程序资源（如内存、文件句柄、网络连接、互斥量等等）的简单技术

**在对象构造时获取资源**，接着控制对资源的访问使之在对象的生命周期内始终保持有效，最后**在对象析构的时候释放资源**。借此，我们实际上把管理一份资源的责任托管给了一个对象。

这种做法有两大好处

- 不需要显式地释放资源
- 采用这种方式，对象所需的资源在其生命期内始终保持有效

### auto_ptr/unique_ptr/shared_ptr/weak_ptr特点是什么？解决了什么问题？

智能指针的原理

- RAII特性
- 重载operator*和opertaor->，具有像指针一样的行为

auto_ptr、unique_ptr、shared_ptr和weak_ptr是C++中用于管理动态分配内存的几种智能指针，它们各自具有不同的特点和用途，主要解决了动态内存管理中的内存泄漏、悬空指针、内存访问错误和异常安全性等问题。

#### 1. auto_ptr（C++98引入，C++11废弃）

**特点**：
- **独占所有权**：auto_ptr 实现了独占式所有权，即一个 auto_ptr 对象拥有对动态分配对象的唯一所有权。
- **所有权转移**：当 auto_ptr 被拷贝或被赋值时，会发生所有权的转移，原 auto_ptr 将失去对对象的所有权。
- **不支持数组**：auto_ptr 不支持管理动态分配的数组，因为其析构函数中调用的是 delete 而不是 delete[]。

**解决的问题**：
- 一定程度上解决了内存泄漏的问题，通过所有权转移和自动析构来释放内存。
- 但由于存在所有权转移的特性，使得它在容器和复杂数据结构中的使用变得复杂且不安全，因此最终被 C++11 废弃。

#### 2. unique_ptr（C++11引入）

**特点**：
- **独占所有权**：与 auto_ptr 类似，unique_ptr 也实现了独占式所有权。
- **禁止拷贝**：但 unique_ptr 禁止了拷贝构造和拷贝赋值操作，只能通过移动语义来转移所有权。
- **支持自定义删除器**：unique_ptr 允许指定一个自定义的删除器，以便在销毁对象时执行特定的清理操作。

**解决的问题**：
- 彻底解决了 auto_ptr 在所有权转移方面的问题，使得 unique_ptr 在容器和复杂数据结构中的使用更加安全和方便。
- 提供了更严格的内存管理机制，减少了内存泄漏和悬空指针的风险。

#### 3. shared_ptr（C++11引入）

**特点**：
- **共享所有权**：多个 shared_ptr 可以共享同一个动态分配的对象，通过引用计数来管理对象的生命周期。
- **自动资源释放**：当最后一个 shared_ptr 被销毁或重置时，对象会被自动释放。
- **可定制删除器**：与 unique_ptr 类似，shared_ptr 也允许指定自定义的删除器。

**解决的问题**：
- 解决了多个对象需要共享同一块内存资源的问题，通过引用计数来确保资源在不再需要时得到释放。
- 提高了代码的可靠性和可维护性，减少了内存泄漏和悬空指针的风险。

#### 4. weak_ptr（C++11引入）

**特点**：

- **弱引用**：weak_ptr 是一种对 shared_ptr 所管理对象的弱引用，它不会增加对象的引用计数。
- **避免循环引用**：weak_ptr 主要用于解决 shared_ptr 之间的循环引用问题，通过弱引用来打破循环，确保对象在不再需要时能够被正确释放。
- **需要转换**：weak_ptr 不直接管理对象，它需要通过 lock 方法转换成 shared_ptr 才能访问对象。

**解决的问题**：

- 解决了 shared_ptr 之间的循环引用导致的内存泄漏问题。
- **提供了对共享资源的非拥有性观察接口，使得在某些情况下可以安全地访问资源而不影响资源的生命周期**。

### 模拟实现

```cc
#pragma once
#include <functional>
#include <atomic>

// auto_ptr
namespace kele
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr):_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& aptr):_ptr(aptr._ptr)
		{
			aptr._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& aptr)
		{
			if (this != &aptr)
			{
				_ptr = aptr._ptr;
				aptr._ptr = nullptr;
			}
			return *this;
		}

		~auto_ptr()
		{
			delete _ptr;
		}

		T& operator*() { return *_ptr; }

		T* operator->() { return _ptr; }

	private:
		T* _ptr;
	};


	template<class T>
	class unique_ptr
	{
		typedef unique_ptr<T> self_ptr;
	public:
		
		unique_ptr(T* ptr) :_ptr(ptr)
		{}

		template<class del>
		unique_ptr(T* ptr, del delfunc) :_ptr(ptr), _del(delfunc)
		{}

		unique_ptr(self_ptr& aptr) = delete;

		self_ptr& operator=(self_ptr& aptr) = delete;

		unique_ptr(self_ptr&& aptr)
			:_ptr(nullptr)
		{
			swap(_ptr, aptr._ptr);
			swap(_del, aptr._del);
		}

		self_ptr& operator=(self_ptr&& aptr)
		{
			if (this != &aptr)
			{
				swap(_ptr, aptr._ptr);
				swap(_del, aptr._del);
			}
			return *this;
		}

		~unique_ptr()
		{
			_del(_ptr);
		}

		T& operator*() { return *_ptr; }

		T* operator->() { return _ptr; }
	private:
		T* _ptr;
		std::function<void(T*)> _del = [](T* ptr) {
			//if(ptr != nullptr)
				delete ptr; 
		};
	};


	template<class T>
	class shared_ptr
	{
		typedef shared_ptr<T> self_ptr;
	public:

		shared_ptr(T* ptr) :_ptr(ptr), _ref_count(new std::atomic<size_t>(1))
		{}

		// 对于lambda表达式的接收就不能用引用
		template<class del>
		shared_ptr(T* ptr, del delfunc) 
            : _ptr(ptr), _del(delfunc),
        	_ref_count(new std::atomic<size_t>(1))
		{}

		shared_ptr(self_ptr& aptr)
			:_ptr(aptr._ptr), _del(aptr._del), _ref_count(aptr._ref_count)
		{
			(*_ref_count)++;
		}

		self_ptr& operator=(self_ptr& aptr)
		{
			if (this != &aptr)
			{
				_ptr = aptr._ptr;
				_del = aptr._del;
				_ref_count = aptr._ref_count;
				(*_ref_count)++;
			}
			return *this;
		}

		shared_ptr(self_ptr&& aptr)
			:_ptr(nullptr), _ref_count(new std::atomic<size_t>(1))
		{
			swap(_ptr, aptr._ptr);
			swap(_del, aptr._del);
			swap(_ref_count, _ref_count);
		}

		self_ptr& operator=(self_ptr&& aptr)
		{
			if (this != &aptr)
			{
				swap(_ptr, aptr._ptr);
				swap(_del, aptr._del);
				swap(_ref_count, _ref_count);
			}
			return *this;
		}

		~shared_ptr()
		{
			(*_ref_count)--;
			if(*_ref_count == 0)
				_del(_ptr);
		}

		T& operator*()
		{
			return *_ptr;
		}

		T& operator*() { return *_ptr; }

		T* operator->() { return _ptr; }
	private:
		T* _ptr;

		// 定制删除器
		std::function<void(T*)> _del = [](T* ptr) {
			//if(ptr != nullptr)
			cout << "delete" << endl;
			delete ptr;
		};

		std::atomic<size_t>* _ref_count; // 引用计数
	};


	template<class T>
	class weak_ptr
	{
		typedef weak_ptr<T> self_ptr;
	public:

		weak_ptr(T* ptr) :_ptr(ptr)
		{}

		weak_ptr(self_ptr& aptr)
			:_ptr(aptr._ptr)
		{}

		weak_ptr(shared_ptr<T>& aptr)
			:_ptr(aptr.get())
		{}

		self_ptr& operator=(self_ptr& aptr)
		{
			if (this != &aptr)
			{
				_ptr = aptr._ptr;
			}
			return *this;
		}

		self_ptr& operator=(shared_ptr<T>& aptr)
		{
			_ptr = aptr.get();
			return *this;
		}

		~weak_ptr()
		{
			cout << "weak delete" << endl;
		}

		T& operator*() { return *_ptr;}

		T* operator->(){ return _ptr;}
	private:
		T* _ptr;
	};
}
```

### 什么是循环引用？怎么解决？

<img src="E:\markdown\img\循环引用.png" style="zoom:80%;" />

因为节点内部的两个shared_ptr引用计数变成了2，在delete的时候，引用计数不会减到0，导致内存泄漏

### 定制删除器（了解）

auto_ptr 对于析构函数是用delete方式删除，但是对于需要delete[]的类型怎么办？对于不是在堆上开辟的空间，怎么办？

例如：文件描述符类型，资源

所以针对不同的使用场景就需要不同的删除器，由使用者提供，可以是lambda，函数指针，仿函数

对于不同的类型可以使用function包装器统一封装

注意lambda不能用&传参，lambda表达式是匿名函数，属于右值

拓展思考：

**shared_ptr的引用计数的增减都是原子的线程安全的，但是shared_ptr指向的资源并不是线程安全的，需要加锁**

对于循环引用，这样的场景下，如果有别的weak_ptr指向一个已经被delete的对象（由于shared_ptr管理的引用计数为0）,这会导致野指针问题，weak_ptr还不知道是不是野指针，无法判断，这么搞？

思考方案：shared_ptr开两个引用计数，一个属于shared_ptr的引用计数shared_ref，另一个属于weak_ptr的弱引用计数weak_ref，如果shared_ptr对象delete，shared_ref--,如果weak_ptr对象delete，weak_ref--。如果shared_ref为0，weak_ref不等于0，空间不释放，把对象交给weak_ptr管理,shared_ref和weak_ref都等于0释放空间

## 10. 类型转换（考察少）

C语言的强制类型转换，关闭或挂起了正常的类型检查，所以很不安全，建议避免使用强制类型转换，建议是用C++的

### 四种类型转换

- **static_cast（静态强制转化）**
- **reinterpret_cast（重译强制转化）**
- **const_cast（常量强制转化）**
- **dynamic_cast（动态强制转化）**

### 使用场景

**static_cast**（相关类型的转换）

**用于非多态类型的转换（静态转换），编译器隐式执行的任何类型转换都可用 static_cast**

**但它不能用于两个不相关的类型进行转换**

```cc
double d = 12.34;
int a = static_cast<int>(d);
cout<<a<<endl;
```

**reinterpret_cast**（不同类型的转换）

**操作符通常为操作数的位模式提供较低层次的重新解释，用于将一种类型转换为另一种不同的类型**

```cc
int a = 12;
// 这里使用static_cast会报错，应该使用reinterpret_cast
//int *p = static_cast<int*>(a);
int* p = reinterpret_cast<int*>(a);
cout << p << endl;
```

**const_cast**（const关系的改变）

**最常用的用途就是删除变量的const属性，方便赋值**

```cc
const int a = 2;
int* p = const_cast< int*>(&a );
*p = 3;
cout<<a <<endl;
```

**dynamic_cast**（多态类型基类到父类的转换）

**dynamic_cast用于将一个父类对象的指针/引用转换为子类对象的指针或引用(动态转换)** 

向上转型：子类对象指针/引用->父类指针/引用(不需要转换，赋值兼容规则) 

**向下转型：父类对象指针/引用->子类指针/引用(用dynamic_cast转型是安全的)** 

注意： 

1. **dynamic_cast只能用于父类含有虚函数的类**

   原因：dynamic_cast是**运行时类型检查**，需要运行时类型信息(RTTI)，而这个信息是存储与类的**虚函数表**关系紧密，只有一个类定义了虚函数，才会有虚函数表

2. **dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回0**

```cc
class A
{
public:
	virtual void f() {}
};
class B : public A
{};
void fun(A* pa)
{
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
int main()
{
	A a;
	B b;
	fun(&a);
	fun(&b);
	return 0;
}
```

> pb1:010FFBD8
> pb2:00000000
> pb1:010FFBCC
> pb2:010FFBCC

**RTTI（了解）**

RTTI：(Run-time Type identification)的简称，即：运行时类型识别。

C++通过以下方式来支持RTTI： 

1. typeid运算符 
2. dynamic_cast运算符 
3. decltype

## 11. IO流（考察少）

### 接口

![](E:\markdown\img\C++IO.png)

功能对应关系

|       C        |                   C++                    |
| :------------: | :--------------------------------------: |
|  scanf/printf  |         istream/ostream/iostream         |
| fscanf/fprintf |        ifstream/ofstream/fstream         |
| sscanf/sprintf | istringstream/ostringstream/stringstream |

**fstream**（文件操作）

| 函数名                | 作用                              |
| :-------------------- | :-------------------------------- |
| 构造                  | 创建空对象/打开文件               |
| 析构                  | 如果打开了文件关闭                |
| open/close            | 打开文件，指定文打开方式/关闭文件 |
| read/write            | 读/写                             |
| operator>>/operator<< | 如果类型重写了>>和<<，可以读/写   |
| seekg/seekp           | 设置读写指针的位置                |
| flush                 | 刷新缓冲区                        |

**stringstream**（字符串操作）

和上面的接口类似，就是没有open和close，多了一个str()返回c字符串，getline()

### 库的意义

1. **面向对象**
2. **支持自定义类型的流插入和流提取**

利用继承多态

**完**
