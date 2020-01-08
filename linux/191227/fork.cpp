#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;

int main()
{
	int ret = fork();
	if(ret < 0)
	{
		perror("error");
		return 0;
	}
	else if(ret == 0)
	{
		cout<<"[child ]";
		cout<<"ppid:"<<getppid()<<" pid:"<<getpid()<<" fork:"<<ret<<endl;
	}
	else
	{
		cout<<"[father]";
		cout<<"ppid:"<<getppid()<<" pid:"<<getpid()<<" fork:"<<ret<<endl;
	}
	return 0;
}
