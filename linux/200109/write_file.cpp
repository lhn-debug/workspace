#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	FILE * fp = fopen("myfile","w");
	if(!fp)
	{
		cout<<"Error!"<<endl;
	}
	const char * msg = "Write to 'myfile' Successful!\n";
	for(int i = 0; i < 5; i++)
	{
		fwrite(msg, strlen(msg), 1, fp);
	}
	fclose(fp);
	return 0;
}
