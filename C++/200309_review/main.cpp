#include<iostream>
#include<cstring>

using namespace std;

extern "C" void fun()
{
	char arrc[] = {'a', 'b'};
	cout<<strlen(arrc)<<" "<<sizeof(arrc)<<endl;

	int arri[] = {1, 2, 3, 4};
	cout<<sizeof(arri)<<endl;

	int *parr[4];
	cout<<parr<<endl;
	for(int i = 0; i < 4; i++)
	{
		parr[i] = &arri[i];
	}

	for(int i = 0; i < 4; i++)
	{
		cout<<parr[i]<<":"<<*parr[i]<<endl;;
	}
	
	cout<<parr[0]+1<<":"<<*(parr[0]+1)<<endl;
	cout<<parr<<endl;
	cout<<parr+1<<endl;
	cout<<parr+2<<endl;

	int *p = parr[0];
	cout<<p<<endl;
	cout<<++p<<endl;
}

int main()
{
	fun();
	return 0;
}
