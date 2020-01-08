#include<iostream>

using namespace std;

class A
{
public:
	A()
	{
		++_count;
	}
	A(const A& a)
	{
		++_count;
	}
	static int getCount()
	{
		return _count;
	}
	void display()
	{
		cout<<getCount()<<endl;
	}
private:
	static int _count;
};

int A::_count = 0;

int main()
{
	cout<<A::getCount()<<endl;
	A a1,a2;
	A a3(a1);
	cout<<A::getCount()<<endl;
	a3.display();
	return 0;
}
