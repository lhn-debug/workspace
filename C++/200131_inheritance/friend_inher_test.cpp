#include<iostream>

using namespace std;

class Student;

class Person
{
public:
	friend void display(const Person& p, const Student& s);
protected:
	string _name;
};

class Student:public Person
{
protected:
	string _sno;
};

void display(const Person& p, const Student& s)
{
	cout<<p._name<<endl;
	//cout<<s._sno<<endl;
}

int main()
{
	Person p;
	Student s;
	display(p, s);
	return 0;
}
