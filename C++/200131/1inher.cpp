#include<iostream>

using namespace std;

class Person
{
public:
	Person(const string& name = "", const int& age = 0)
		:_name(name), _age(age)
	{}

	void Print()
	{
		cout<<"name:"<<_name<<endl;
		cout<<"age:"<<_age<<endl;
	}
protected:
	string _name;
	int _age;
};

class Student:public Person
{	
public:
	Student(const string& name = "", const int& age = 0, const int& sid = 0)
		:Person(name, age), _sid(sid)
	{}

	void Print()
	{
		Person::Print();
		cout<<"sid:"<<_sid<<endl;
	}
protected:
	int _sid;
};

class Teacher:public Person
{
public:
	Teacher(const string& name = "", const int& age = 0, const int& tid = 0)
		:Person(name, age), _tid(tid)
	{}

	void Print()
	{
		Person::Print();
		cout<<"tid:"<<_tid<<endl;
	}
protected:
	int _tid;
};

int main()
{
	Student s("yx", 22, 1111);
	Teacher t("lhn", 22, 2222);
	s.Print();
	t.Print();
	return 0;
}
