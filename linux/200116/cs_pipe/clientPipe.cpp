#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define SIZE 1024
#define ERR_EXIT(m) do{perror(m);exit(EXIT_FAILURE);}while(0)

using namespace std;

void clientPipe()
{
	int wfd = open("mypipe", O_WRONLY);
	if(wfd < 0)
	{
		ERR_EXIT("open_wfd");
	}
	char buf[SIZE] = {};
	while(1)
	{
		cout<<"Enter#";
		fflush(stdout);
		size_t len = read(0, buf, SIZE);
		if(len <= 0)
		{
			ERR_EXIT("read_wfd");
		}
		else if(len > 0)
		{
			buf[len] = '\0';
			write(wfd, buf, strlen(buf));
		}
	}
	close(wfd);
}

int main()
{
	clientPipe();
	return 0;
}
