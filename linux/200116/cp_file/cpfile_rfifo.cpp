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

void rdfifo_wrTofile()
{
	int infd = open("tp", O_RDONLY);
	if(infd == -1)
	{
		ERR_EXIT("open_tp");
	}
	int outfd = open("file.bak", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if(outfd == -1)
	{
		ERR_EXIT("open_file_bak");
	}
	char buf[SIZE] = {};
	int len;
	while((len = read(infd, buf, SIZE)) > 0)
	{
		write(outfd, buf, len);
	}
	close(infd);
	close(outfd);
	unlink("tp");
}

int main()
{
	rdfifo_wrTofile();
	return 0;
}
