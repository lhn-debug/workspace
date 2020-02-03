#include<iostream>

using namespace std;

class Base
{
public:
	explicit Base(int a):_a(a)
	{
		cout<<"Base(int a)"<<endl;
	}

	Base(const Base& base)
	{
		cout<<"Base(const Base& base)"<<endl;
	}
private:
	int _a;
};

int main()
{
	Base base1(1);
	Base base2(base1);
	//Base base3 = 1;explicit防止构造函数隐式转换
	return 0;
}
