#include<iostream>
#include<string>
using namespace std;

//class Person
//{
//public:
//	void print()
//	{
//		cout << _name << endl << _age << endl;
//	}
//protected:
//	string _name = "kele";
//	int _age = 21;
//};
//
//class Student :public Person
//{
//protected:
//	int _stdid;
//};
//
//class Teacher :public Person
//{
//protected:
//	int _teacher;
//};

//int main()
//{
//	Person p;
//	Student s;
//	Teacher t;
//	p.print();
//	s.print();
//	t.print();
//	return 0;
//}


//int main()
//{
//	Student s;
//	Person p = s;
//	Person* pp = &s;
//	Person& rp = s;
//
//	Student* ps = (Student*)pp;
//	
//
//	return 0;
//}

//class Person
//{
//public:
//	void print()
//	{
//		cout << _name << endl << _age << endl;
//	}
//protected:
//	string _name = "kele";
//	int _age = 21;
//};
//
//class Student :public Person
//{
//public:
//	void print()
//	{
//		cout << _name << _age << _stdid << endl;
//	}
//protected:
//	int _stdid = 1111;
//};
//
//int main()
//{
//	Student s;
//	s.print();
//	s.Person::print();
//	return 0;
//}


//class Person
//{
//public:
//	Person(string name, int age)
//		:_name(name),
//		_age(age)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		:_name(p._name),
//		_age(p._age)
//	{
//		cout << "Person(Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		if (this != &p)
//		{
//			_name = p._name;
//			_age = p._age;
//		}
//		cout << "Person& operator=(const Person& p)" << endl;
//		return *this;
//	}
//
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//	void print()
//	{
//		cout << _name << endl << _age << endl;
//	}
//protected:
//	string _name;
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	Student(string name, int age, int stdid)
//		:Person(name, age),
//		_stdid(stdid)
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		:Person(s),
//		_stdid(s._stdid)
//	{
//		cout << "Student(Student& s)" << endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_stdid = s._stdid;
//		}
//		cout << "Student& operator=(const Student& s)" << endl;
//		return *this;
//	}
//
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//
//	void print()
//	{
//		cout << _name << _age << _stdid << endl;
//	}
//protected:
//	int _stdid;
//};

//int main()
//{
//	//Student s("coke" ,22 , 21);
//	//s.print();
//	//s.Person::print();
//
//	Person* p = new Student("coke", 22, 21);
//	delete p;
//	//destrutor(p);
//	//operator delete(p);
//	return 0;
//}

//int main()
//{
//	Person p("kele", 21);
//	Student s("coke", 22, 12345);
//	Person p1 = s;
//	Student s1 = s;
//	p = s1;
//	return 0;
//}



//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	//a._name = "peter";
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//	return 0;
//}

class Person
{
public:
	string _name; // 姓名
};
class Student : virtual public Person
{
protected:
	int _num; //学号
};
class Teacher : virtual public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};
int main()
{
	Assistant a;
	a._name = "peter";
	return 0;
}