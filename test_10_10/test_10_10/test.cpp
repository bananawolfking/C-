#include"F.h"

//int main()
//{
//	F(10);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	auto b = i;
//	auto* c = &i;
//	auto& d = i;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(typeid(b).name()).name() << endl;	//现在看起来像是字符串
//	int* a = nullptr;
//	cout << typeid(a).name() << endl;
//	return 0;
//}

//void func(int i)
//{
//	cout<< typeid(i).name() << endl;
//}
//
//void func(int* i)
//{
//	cout << typeid(i).name() << endl;
//}
//
//int main()
//{
//	func(NULL);
//	func(0);
//	func(nullptr);
//	return 0;
//}


//int main()
//{
//	int array[] = { 1,2,3,4,5,6,6 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	{
//		cout << array[i] << " ";
//	}
//	cout << endl;
//
//	for (int e : array)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto e : array)
//	{
//		e *= 2;
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto& e : array)
//	{
//		e *= 2;
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//for (auto* e : array)//错误
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	return 0;
//}

#include"Stack.h"


int main()
{
	Stack st;
	st.Init();
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	st.Push(5);
	st.Print();
	return 0;
}