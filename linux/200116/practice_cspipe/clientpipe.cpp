#include<iostream>
#include<cstring>
#include<cstdlib>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define SIZE 1024

#define ERR_EXIT(m) do{perror(m);exit(EXIT_FAILURE);}while(0)

using namespace std;

void clientpipe()
{
	int wfd = open("tmp", O_WRONLY);
	if(wfd < 0)
	{
		ERR_EXIT("open_tmp");
	}
	
	char buf[SIZE] = {};
	while(1)
	{
		cout<<"Enter#";
		fflush(stdout);
		size_t len;
		if((len = read(0, buf, SIZE)) > 0)
		{
			buf[len] = '\0';
			write(wfd, buf, strlen(buf));
		}
		else
		{
			ERR_EXIT("write_tmp");
		}
	}
	close(wfd);
}

int main()
{
	clientpipe();
	return 0;
}
