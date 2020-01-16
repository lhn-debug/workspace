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

void mk_fifo()
{
	umask(0);
	if(mkfifo("mypipe", 0644) < 0)
	{
		ERR_EXIT("mypipe");
	}
}

void serverPipe()
{
	int rfd = open("mypipe", O_RDONLY);
	if(rfd < 0)
	{
		ERR_EXIT("open_rfd");
	}
	char buf[SIZE] = {};
	while(1)
	{
		cout<<"Waiting......"<<endl;
		size_t len = read(rfd, buf, SIZE);
		if(len == 0)
		{
			cout<<"client quit!......"<<endl;
			unlink("mypipe");
			exit(EXIT_SUCCESS);
		}
		else if(len > 0)
		{
			buf[len-1] = '\0';
			cout<<buf<<endl;
		}
		else
		{
			ERR_EXIT("read_rfd");
		}
	}
	close(rfd);
}

int main()
{
	mk_fifo();
	serverPipe();
	return 0;
}
