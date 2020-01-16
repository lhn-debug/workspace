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

void rdfrompipeWrtofile()
{
	int infd = open("tmp", O_RDONLY);
	if(infd == -1)
	{
		ERR_EXIT("open_tmp");
	}

	int outfd = open("file.bak", O_WRONLY|O_CREAT, 0644);
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
	unlink("tmp");
}

int main()
{
	rdfrompipeWrtofile();
	return 0;
}
