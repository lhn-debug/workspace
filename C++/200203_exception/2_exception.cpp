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
	int * arr = new int[10];
	try
	{
		int a, b;
		cin>>a>>b;
		cout<<division(a, b)<<endl;
	}
	catch(...)
	{
		cout<<"delete[]1->"<<arr<<endl;
		delete[] arr;
		throw;
	}
	cout<<"delete[]2->"<<arr<<endl;
	delete[] arr;
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
	return 0;
}
