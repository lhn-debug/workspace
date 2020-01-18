#include<iostream>
#include<unistd.h>

using namespace std;

int main()
{
	int count = 1;
	alarm(1);
	while(1)
	{
		cout<<"count = "<<count<<endl;
		count++;
	}
	return 0;
}
