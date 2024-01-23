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
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//int main()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	//a._name = "peter";
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//	return 0;
//}

class Person
{
public:
	string _name; // ����
};
class Student : virtual public Person
{
protected:
	int _num; //ѧ��
};
class Teacher : virtual public Person
{
protected:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};
int main()
{
	Assistant a;
	a._name = "peter";
	return 0;
}