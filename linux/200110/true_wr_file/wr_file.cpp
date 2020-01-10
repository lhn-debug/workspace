#include<stdio.h>
#include<iostream>

using namespace std;

const char * msg = "This is file.txt!\n";

void write_file()
{
	FILE * fp = fopen("file.txt", "w");
	if(!fp)
	{
		cout<<"Error"<<endl;
		return ;
	}
	fputs(msg, fp);
	fclose(fp);
}

void read_file()
{
	FILE * fp = fopen("file.txt", "r");
	if(!fp)
	{
		cout<<"Error"<<endl;
		return ;
	}
	int c;//注意此处为int，作为putchar(int)的参数
	while((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	if(ferror(fp))
	{
		cout<<"I/O Error End!"<<endl;
	}
	fclose(fp);
}

int main()
{
	write_file();
	read_file();
	return 0;
}
