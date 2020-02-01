#include<iostream>

using namespace std;

class Person
{
public:
	virtual void display()
	{
		cout<<"Person()"<<endl;
	}
};

class Student:public Person
{	
public:
	virtual void display()
	{
		cout<<"Student()"<<endl;
	}
};

void func(Person& people)
{
	people.display();
}

int main()
{
	Person p;
	func(p);
	Student s;
	func(s);
	return 0;
}
