#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

using namespace std;

int main()
{
	int ret=fork();
	if(ret<0)
	{
		perror("error");
		return 0;
	}
	else if(ret==0)
	{
		cout<<"ppid:"<<getppid()<<" pid:"<<getpid()<<" ret:"<<ret<<endl;
		sleep(10);
	}
	else
	{
		cout<<"ppid:"<<getppid()<<" pid:"<<getpid()<<" ret:"<<ret<<endl;
		sleep(20);
	}
	return 0;
}
