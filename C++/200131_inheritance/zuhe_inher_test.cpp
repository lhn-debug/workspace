#include<iostream>

using namespace std;

//A、B构成is-a关系
class A
{
protected:
	string _a = "_a";
};

class B:public A
{
public:
	void display()
	{
		cout<<_a<<_b<<endl;
	}
protected:
	string _b = "_b";
};

//C、D构成has-a关系
class C
{
public:
	string get_c()
	{
		return _c;
	}
protected:
	string _c = "_c";
};

class D
{
public:
	void display()
	{
		cout<<c.get_c()<<_d<<endl;		
	}
protected:
	string _d = "_d";
	C c;
};

int main()
{
	B b;
	b.display();
	D d;
	d.display();
	return 0;
}
