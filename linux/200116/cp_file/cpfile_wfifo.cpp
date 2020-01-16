#include<iostream>
#include<stdio.h>
#include<errno.h>
#include<cstring>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define SIZE 1024
#define ERR_EXIT(m) do{perror(m);exit(EXIT_FAILURE);}while(0)

using namespace std;

void mk_fifo()
{
	mkfifo("tp", 0644);
}

void rdfile_wrTofifo()
{
	int infd = open("file", O_RDONLY);
	if(infd == -1)
	{
		ERR_EXIT("open_file");
	}
	int outfd = open("tp", O_WRONLY);
	if(outfd == -1)
	{
		ERR_EXIT("open_tp");
	}
	char buf[SIZE] = {};
	int len;
	while((len = read(infd, buf, SIZE)) > 0)
	{
		write(outfd, buf, len);
	}
	close(infd);
	close(outfd);
}

int main()
{
	mk_fifo();
	rdfile_wrTofifo();
	return 0;
}
