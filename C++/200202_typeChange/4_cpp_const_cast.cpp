#include<iostream>

using namespace std;

int main()
{
	const int a = 2;
	int * p = const_cast<int *>(&a);
	*p = 3;
	cout<<*p<<endl;
	return 0;
}
