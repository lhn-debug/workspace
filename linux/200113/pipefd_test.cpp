#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<cstring>
#include<cstdlib>

using namespace std;

int main()
{
	char buffer[128];
	int pipefds[2];
	int flag = pipe(pipefds);
	if(flag == -1)
	{
		perror("make pipe");
		_exit(1);
	}
	//读取键盘输入写入buffer
	while(fgets(buffer, sizeof(buffer), stdin))
	{
		int len = strlen(buffer);
		//将buffer内容写入管道
		if(write(pipefds[1], buffer, len) != len)
		{
			perror("write to pipe");
			break;
		}
		//把buffer内容置空
		memset(buffer, 0x00, sizeof(buffer));
		//从管道读的内容写入buffer
		if((len = read(pipefds[0], buffer, sizeof(buffer))) == -1)
		{
			perror("read from pipe");
			break;
		}
		//将buffer内容写入显示器
		if(write(1, buffer, len) != len)
		{
			perror("write to stdout");
			break;
		}
	}
	return 0;
}
