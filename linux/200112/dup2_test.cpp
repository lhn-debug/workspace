#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<cstring>

using namespace std;

const char * msg = "Testing dup2\n";

int main()
{
	int fd = open("./log", O_RDWR|O_CREAT, 0644);
	if(fd < 0)
	{
		cout<<"Error"<<endl;
		return 0;
	}
	cout<<fd<<endl;
	close(1);
	dup2(fd ,1);
	//read(0, msg, strlen(msg));
	close(fd);
	return 0;
}
