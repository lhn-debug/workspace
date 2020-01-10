#include<stdio.h>
#include<iostream>

#define SIZE 5

using namespace std;

const double arr[SIZE] = {0.1,0.2,0.3,0.4,0.5};
double res = 0.0;

void bin_write_file()
{
	FILE * fp = fopen("bin_file.bin", "wb");
	if(!fp)
	{
		cout<<"Error"<<endl;
		return ;
	}
	fwrite(arr, sizeof(double), SIZE, fp);
	fclose(fp);
}

void bin_read_file()
{
	FILE * fp = fopen("bin_file.bin", "rb");
	if(!fp)
	{
		cout<<"Error"<<endl;
		return ;
	}
	while(fread(&res, sizeof(double), 1, fp)>0)
	{
		cout<<res<<endl;
	}
	if(ferror(fp))
	{
		cout<<"I/O Error End!"<<endl;
	}
	fclose(fp);
}

int main()
{
	bin_write_file();
	bin_read_file();
	return 0;
}
