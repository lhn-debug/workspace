#include<iostream>
#include<signal.h>

using namespace std;

void handler(int sig)
{
	cout<<"catch a sig:"<<sig<<endl;
}

int main()
{
	signal(SIGSEGV, handler);
	int *p = NULL;
	*p = 100;
	//while(1);
	return 0;
}	
