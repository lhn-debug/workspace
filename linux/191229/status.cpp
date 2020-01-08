#include<sys/wait.h>
#include<unistd.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("error");
		exit(1);
	}
	if(pid == 0)
	{
		sleep(20);
		exit(8);
	}
	else
	{
		int status;
		int ret = wait(&status);
		if(ret > 0 && (status & 0x7F) == 0)
		{
			//正常退出
			cout<<"child exit code:"<<((status>>8) & (0xFF))<<endl;
		}
		else if(ret > 0)
		{
			//异常退出
			cout<<"sig code:"<<((status) & (0x7F))<<endl;
		}
	}
	return 0;
}
