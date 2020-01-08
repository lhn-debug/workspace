#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

using namespace std;

int main()
{
	cout<<"pid:"<<getpid()<<endl;
	cout<<"ppid:"<<getppid()<<endl;
	return 0;
}
