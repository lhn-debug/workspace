#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<iostream>

using namespace std;

const char * msg = "This is a system file I/O\n";

void sys_write_file()
{
	umask(0);
	int fd = open("sys_wr_file", O_WRONLY|O_CREAT, 0644);
	if(fd < 0)
	{
		cout<<"Error"<<endl;
		return;
	}
	int count = 5;
	while(count > 0)
	{
		write(fd, msg, strlen(msg));
		count--;
	}
	close(fd);
}

void sys_read_file()
{
	int fd = open("sys_wr_file", O_RDONLY);
	if(fd < 0)
	{
		cout<<"Error"<<endl;
		return;
	}
	char buf[1024] = {};
	while((read(fd, buf, strlen(msg))) > 0)
	{
		cout<<buf;
	}
	close(fd);
}

int main()
{
	sys_write_file();
	sys_read_file();
	return 0;
}
