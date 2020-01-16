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

void serverpipe()
{
	umask(0);
	if(mkfifo("tmp", 0644) < 0)
	{
		ERR_EXIT("mkfifo");
	}

	int rfd = open("tmp", O_RDONLY);
	if(rfd < 0)
	{
		ERR_EXIT("open_tmp");
	}

	char buf[SIZE] = {};
	while(1)
	{
		cout<<"Please Waitting......"<<endl;
		size_t len = read(rfd, buf, SIZE);
		if(len == 0)
		{
			cout<<"client quit!......"<<endl;
			unlink("tmp");
			exit(EXIT_SUCCESS);
		}
		else if(len > 0)
		{
			buf[len-1] = '\0';
			cout<<buf<<endl;
		}
		else
		{
			ERR_EXIT("read_tmp");
		}
	}
	close(rfd);
}

int main()
{
	serverpipe();
	return 0;
}
