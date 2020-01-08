#include<iostream>

using namespace std;

class A
{
public:
	A(int _b = 0):b(_b){}
	class B
	{
	public:
		void display(const A& obj)
		{
			cout<<a<<endl;
			cout<<obj.b<<endl;
		}
	};
private:
	static int a;
	int b;
};

int A::a = 0;

int main()
{
	A a;
	A::B ab;
	ab.display(a);
	return 0;
}
