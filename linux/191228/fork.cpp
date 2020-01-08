#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;

int main()
{
	pid_t pid;

	cout<<"fork前pid:"<<getpid()<<endl;

	pid = fork();

	if(pid == -1)
	{
		perror("error");
		return 0;
	}

	cout<<"fork后pid:"<<getpid()<<" fork返回:"<<pid<<endl;

	return 0;
}
