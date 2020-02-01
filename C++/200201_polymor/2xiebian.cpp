#include<iostream>

using namespace std;

class A{};
class B:public A{};

class Person
{
public:
	virtual A* fun()
	{
		return new A;
	}
};

class Student:public Person
{
public:
	virtual B* fun()
	{
		return new B;
	}
};

int main()
{
	return 0;
}
