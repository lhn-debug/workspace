#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define SIZE 1024

#define ERR_EXIT(m) do{perror(m);exit(EXIT_FAILURE);}while(0)

using namespace std;

void rdfromfileWrtopipe()
{
	umask(0);
	if(mkfifo("tmp", 0644) < 0)
	{
		ERR_EXIT("mkfifo");
	}
	
	int infd = open("file", O_RDONLY);
	if(infd == -1)
	{
		ERR_EXIT("open_file");
	}

	int outfd = open("tmp", O_WRONLY);
	if(outfd == -1)
	{
		ERR_EXIT("open_tmp");
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
	rdfromfileWrtopipe();
	return 0;
}
