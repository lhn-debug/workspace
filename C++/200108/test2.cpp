#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	//动态申请一个int类型空间
	int *ptr1 = new int;
	//动态申请一个int类型的空间并初始化为10
	int *ptr2 = new int(10);
	//动态申请3个int类型的空间
	int *ptr3 = new int[3];
	delete ptr1;
	delete ptr2;
	delete[] ptr3;
	return 0;
}
