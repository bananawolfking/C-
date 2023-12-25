#include<iostream>
#include<string>
using namespace std;

//class Person
//{
//public:
//	void print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//	}
//protected:
//	string _name = "kele";
//	int _age = 20;
//};
//
//class Student : public Person
//{
//protected:
//	int stuid;
//};
//
//int main()
//{
//	Student s;
//	s.print();
//
//	return 0;
//}

class Person
{
public:
    Person(const string& name = "peter")
        : _name(name)
    {
        cout << "Person()" << endl;
    }

    Person(const Person& p)
        : _name(p._name)
    {
        cout << "Person(const Person& p)" << endl;
    }

    Person& operator=(const Person& p)
    {
        cout << "Person operator=(const Person& p)" << endl;
        if (this != &p)
            _name = p._name;

        return *this;
    }

    ~Person()
    {
        cout << "~Person()" << endl;
    }
protected:
    string _name; // ÐÕÃû
};

class Student : public Person
{
public:
    Student(const string& s = "kele", int num = 20)
        :Person(s),
        _num(num)
    {}

    Student(const Student& x)
        :Person(x),
        _num(x._num)
    {}

    Student& operator=(const Student& x)
    {
        if (this != &x)
        {
            Person::operator=(x);
            _num = x._num;
        }
        return *this;
    }


protected:
    int _num;
};


int main()
{
    Student s("lixinag", 21);
    Student x = s;
    Person v = x;
    s = x;

    return 0;
}