#include<iostream>

using namespace std;

class A
{
public:
	A(int a)
		:_a(a){}
private:
	int _a;
};

class B
{
public:
	B(int a, int ref)
		:_a(a), _ref(ref), _n(10){}
private:
	A _a;
	int& _ref;
	const int _n;
};

int main()
{
	B b(10,10);
	return 0;
}
