#include"../head.hpp"

class A
{
public:
	virtual void fun() = 0;
};

class B:public A
{
public:
	virtual void fun() override{}
};

int main()
{
/*
	//A a;
	B b;
*/
/*
	char w;
	int x;
	float y, z;
	cout<<w*x+y-z<<endl;
	float a = 123.456;
	printf("%-5.2f\n", a);
*/
/*
	int a = 0, b = 0, c = 0;
	if(++a>0||++b>0)++c;
	cout<<a<<b<<c<<endl;
*/

	return 0;
}
