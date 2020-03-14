#include<iostream>

using namespace std;

int main()
{
	int i = 1;
	long l = 1;
	long long ll = 1;
	int tag1 = 1;
	while(tag1)
	{
		cout<<(tag1 & i);
		tag1 <<= 1;
	}
	cout<<endl;
	long tag2 = 1;
	while(tag2)
	{
		cout<<(tag2 & l);
		tag2 <<= 1;
	}
	cout<<endl;
	long long tag3 = 1;
	while(tag3)
	{
		cout<<(tag3 & ll);
		tag3 <<= 1;
	}
	cout<<endl;
	return 0;
}
