#include<iostream>

using namespace std;

class Base
{
public:
	virtual void fun() = 0;
};

class A:public Base
{
public:
	virtual void fun()
	{
		cout<<"A"<<endl;
	}
};

class B:public Base
{
public:
	virtual void fun()
	{
		cout<<"B"<<endl;
	}
};

int main()
{
	Base * pA = new A();
	Base * pB = new B();
	pA->fun();
	pB->fun();
	return 0;
}
