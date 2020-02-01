#include<iostream>

using namespace std;

class Person
{
public:
	Person()
	{
		++_count;
	}
protected:
	string _name;
public:
	static int _count;
};

int Person::_count = 0;

class Student:public Person
{
protected:
	string _sno;
};

class Graduate:public Student
{
protected:
	string _course;
};

int main()
{
	Person p;
	Student s1;
	Student s2;
	Graduate g1;
	Graduate g2;
	cout<<"Person Number:"<<Person::_count<<endl;//5
	Student::_count = 0;
	cout<<"Person Number:"<<Person::_count<<endl;//0
	return 0;
}
