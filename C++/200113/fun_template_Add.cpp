#include<iostream>

using namespace std;

template<typename T>
void Add(const T& _t1, const T& _t2)
{
	cout<<(_t1 + _t2)<<endl;
}

int main()
{
	int a = 2;
	double b = 3.0;
	Add(a, a);//隐式实例化编译器自己推演
	//Add(a, b);编译错误，参数列表只有一个类型，此处a,b类型不同
	Add(a, (int)b);//用户强制转化
	Add<int>(a, b);//显式实例化在函数名后<>加类型
	return 0;
}
