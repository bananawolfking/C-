#include"test.h"



//int main()
//{
//	Stack st(5);
//
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//	cout << st.Pop() << endl;
//	st.Print();
//
//	return 0;
//}



//int main()
//{
//	Queue Q;
//
//	Q.Push(1);
//	Q.Push(2);
//	Q.Push(3);
//	Q.Push(4);
//	cout << Q.Pop() << endl;
//	Q.Push(1);
//	Q.Push(2);
//	Q.Print();
//	return 0;
//}




//int main()
//{
//	Date a;
//	a.Printf();
//	return 0;
//}

int main()
{
	Date a;
	Date b = a.DaysAfter1(100);
	b.Printf();
	a.Printf();

	return 0;
}