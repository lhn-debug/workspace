#include<iostream>

using namespace std;

typedef void (* FUNC)();

int doSth(int i)
{
	cout<<"doSth"<<endl;
	return 0;
}

int main()
{
	FUNC f = reinterpret_cast<FUNC>(doSth);
	f();
	return 0;
}

