#include<iostream>

using namespace std;

double division(int a, int b)
{
	if(b == 0)
	{
		throw "error div by 0!";
	}
	else
	{
		return ((double)a / (double)b);
	}
}

void func()
{
	int a, b;
	cin>>a>>b;
	cout<<division(a, b)<<endl;
}

int main()
{
	try
	{
		func();
	}
	catch(const char * errmsg)
	{
		cout<<errmsg<<endl;
	}
	catch(...)
	{
		cout<<"unknow error!"<<endl;
	}
	return 0;
}
