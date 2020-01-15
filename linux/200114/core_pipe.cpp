#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<cstdlib>
#include<error.h>
#include<cstring>

#define ERR_EXIT(m) do{perror(m);exit(EXIT_FAILURE);}while(0)

using namespace std;

int main()
{
	int pipefd[2];
	if(pipe(pipefd) == -1)
	{
		ERR_EXIT("pipe error");
	}
	pid_t pid = fork();
	if(pid == -1)
	{
		ERR_EXIT("fork error");
	}
	if(pid == 0)
	{
		close(pipefd[0]);
		write(pipefd[1], "hello", 5);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	close(pipefd[1]);
	char buf[10] = {};
	read(pipefd[0], buf, 10);
	cout<<buf<<endl;
	close(pipefd[0]);
	return 0;
}
