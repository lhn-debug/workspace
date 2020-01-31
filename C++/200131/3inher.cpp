#include<iostream>

using namespace std;

class Person
{
public:
	Person(const char * name = "Tom")
		:_name(name)
	{
		cout<<"Person()"<<endl;
	}

	Person(const Person& p)
		:_name(p._name)
	{
		cout<<"Person(const Person& p)"<<endl;
	}

	Person& operator=(const Person& p)
	{
		cout<<"Person& operator=(const Person& p)"<<endl;
		if(this != &p)
		{
			_name = p._name;
		}
		return *this;
	}

	~Person()
	{
		cout<<"~Person()"<<endl;
	}
protected:
	string _name;
};

class Student:public Person
{
public:
	Student(const char * name, int num)
		:Person(name), _num(num)
	{
		cout<<"Student()"<<endl;
	}

	Student(const Student& s)
		:Person(s), _num(s._num)
	{
		cout<<"Student(const Student& s)"<<endl;
	}

	Student& operator=(const Student& s)
	{
		cout<<"Student& operator=(const Student& s)"<<endl;
		if(this != &s)
		{
			Person::operator=(s);
			_num = s._num;
		}
		return *this;
	}

	~Student()
	{
		cout<<"~Student()"<<endl;
	}
protected:
	int _num;
};

int main()
{
	Student s1("a", 20);
	Student s2(s1);
	Student s3 = s1;
	return 0;
}
