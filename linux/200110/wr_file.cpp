#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

char buf[1024] = {};
const char * msg = "myfile2\n";

void write_file()
{
	FILE * fp = fopen("myfile2", "w");
	if(fp)
	{
		fputs(msg, fp);
		fclose(fp);
	}
}

void read_file()
{
	FILE * fp = fopen("myfile2", "r");
	if(fp)
	{
		fgets(buf, 5, fp);
		fclose(fp);
	}
	cout<<buf<<endl;
}

int main()
{
	write_file();
	read_file();
	return 0;
}
