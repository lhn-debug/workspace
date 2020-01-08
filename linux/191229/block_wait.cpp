#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>

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
		cout<<"child pid:"<<getpid()<<endl;
		sleep(5);
		exit(257);
	}
	else
	{
		int status = 0;
		pid_t ret = waitpid(-1, &status, 0);
		if(WIFEXITED(status) && (ret == pid))
		{
			cout<<"child exit code:"<<WEXITSTATUS(status)<<endl;
		}
		else
		{
			cout<<"failed"<<endl;
			exit(1);
		}
	}
	return 0;
}
