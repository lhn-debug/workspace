#include<iostream>
#include<typeinfo>

using namespace std;

void test_1()
{
	int a = 1;
	int b = 2;
	decltype(a+b) c;
	cout<<typeid(c).name()<<endl;
}

void * get_memory(size_t size)
{
	return malloc(size);
}

void test_2()
{
	cout<<typeid(decltype(get_memory)).name()<<endl;
	cout<<typeid(decltype(get_memory(1))).name()<<endl;
}

int main()
{
	test_1();
	test_2();
	return 0;
}
