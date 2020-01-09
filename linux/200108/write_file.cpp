#include<iostream>
#include<stdio.h>
#include<cstring>
#include<unistd.h>

using namespace std;

int main()
{
	FILE *fp = fopen("myfile","w");
	/*进程替换程序touch一个文件*/
	if(!fp)
	{
		char *const argv[] = {"touch","myfile",NULL};
		char *const envp[] = {"PATH=/bin:/usr/bin","TREM=console",NULL};
		execve("/bin/touch",argv,envp);
	}
	const char *msg = "Test Write File Successful!";
	fwrite(msg, strlen(msg), 1, fp);
	fclose(fp);
	return 0;
}
