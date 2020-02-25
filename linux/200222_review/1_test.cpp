#include<iostream>
#include<vector>

using namespace std;

class A
{
public:
	A()
	{
		cout<<"A()"<<endl;
	}
	static void fun(){}
};

class B:public A
{
public:
	B()
	{
		cout<<"B()"<<endl;
	}
};

int main()
{/*
	int *p = new int[2];
	p[0] = 10;
	p[1] = 20;
	cout<<*++p<<endl;
*/	
//	B b;

	vector<int> v;
	int input;
	while(true)
	{
		cin>>input;
		if(input == -1)
		{
			break;
		}
		v.push_back(input);
	}
	for(auto& e : v)
	{
		cout<<e<<endl;
	}
	return 0;
}
