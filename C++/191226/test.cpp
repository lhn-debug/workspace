#include<iostream>

using namespace std;

namespace M
{
	int a = 0;
	int add(int a = 10,int b = 20)
	{
		return a + b;
	}
	namespace N
	{
		int a = 1;
		int add(int a = 20,int b = 30)
		{
			return a + b;
		}
	}
}

using namespace M;

int Add(int left, int right)
{
	return left+right;
}
double Add(double left, double right)
{
	return left+right;
}
long Add(long left, long right)
{
	return left+right;
}


void TestFunc(int a = 10)
{
	cout<<"void TestFunc(int)"<<endl;
}

void TestFunc(int a)
{
	cout<<"void TestFunc(int)"<<endl;
}


int main()
{
	cout<<M::a<<endl;
	cout<<M::add()<<endl;
	cout<<M::N::a<<endl;
	cout<<M::N::add()<<endl;
	
	cout<<a<<endl;
	cout<<add()<<endl;
	cout<<N::a<<endl;
	cout<<N::add()<<endl;

	cout<<Add(1,2)<<endl;
	cout<<Add(1.1,2.2)<<endl;
	cout<<Add(123456789,234567890)<<endl;

	TestFunc(10);
	TestFunc();

	return 0;
}
