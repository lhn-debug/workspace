#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	FILE * fp = fopen("myfile","r");
	if(!fp)
	{
		cout<<"Error!"<<endl;
	}
	char buf[1024];
	const char * msg = "Write to 'myfile' Successful!\n";
	while(feof(fp) == 0)
	{
		if(fread(buf, 1, strlen(msg), fp)>0)
			cout<<buf;
	}
	fclose(fp);
	return 0;
}
