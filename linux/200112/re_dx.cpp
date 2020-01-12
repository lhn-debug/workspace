#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

using namespace std;

int main()
{
	close(1);
	int fd = open("re_dx", O_WRONLY|O_CREAT, 0644);
	if(fd < 0)
	{
		cout<<"Error"<<endl;
		return 0;
	}
	cout<<fd<<endl;
	fflush(stdout);
	close(fd);
	return 0;
}
