#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

char buf[1024] = {};
const char * msg = "write successful\n";

void write_file()
{
	FILE * fp = fopen("myfile", "w");
	if(!fp)
	{	
		cout<<"Error"<<endl;
	}
	fwrite(msg, strlen(msg), 1, fp);
	fclose(fp);
}

void read_file()
{
	FILE * fp = fopen("myfile", "r");
	if(!fp)
	{
		cout<<"Error"<<endl;
	}
	while(feof(fp) == 0)
	{
		if(fread(buf, 1, strlen(msg), fp) > 0)
		{
			cout<<buf;
		}
	}
	fclose(fp);
}

int main()
{
	write_file();//写文件
	read_file();//读文件
	fwrite(msg, strlen(msg), 1, stdout);//消息写到显示器
	return 0;
}
