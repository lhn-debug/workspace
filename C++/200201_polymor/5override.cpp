#include<iostream>

using namespace std;

class A
{
public:
	virtual void fun(){}
};

class B:public A
{
public:
	//override检查派生类是否重写基类虚函数
	virtual void fun() override
	{
		cout<<endl;
	}
};

int main()
{
	return 0;
}
