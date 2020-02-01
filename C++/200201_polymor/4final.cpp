#include<iostream>

using namespace std;

class A
{
public:
	virtual void fun() final{}
};

class B:public A
{
public:
/*final修饰基类虚函数不能被继承
	virtual void fun()
	{
		cout<<endl;
	}
*/
};

int main()
{
	return 0;
}
