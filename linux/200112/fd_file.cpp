#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

int main()
{
	int fd;
	fd = open("sys_wr_file", O_RDONLY);
	if(fd < 0)
	{
		cout<<"Error"<<endl;
		return 0;
	}
	cout<<fd<<endl;
	close(fd);

	close(0);
	fd = open("sys_wr_file", O_RDONLY);
	if(fd < 0)
	{
		cout<<"Error"<<endl;
		return 0;
	}
	cout<<fd<<endl;
	close(fd);

	close(2);
	fd = open("sys_wr_file", O_RDONLY);
	if(fd < 0)
	{
		cout<<"Error"<<endl;
		return 0;
	}
	cout<<fd<<endl;
	close(fd);

	return 0;
}
