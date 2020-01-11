#include<iostream>
#include<stdio.h>

#define SIZE 5

using namespace std;

void bin_wr_file()
{
	double res = 0.0;
	const double db[SIZE] = {0.1, 0.2, 0.3, 0.4, 0.5};
	FILE * fp;

	fp = fopen("bin_file.bin", "wb");
	if(!fp)
	{
		cout<<"Error"<<endl;
		return;
	}
	fwrite(db, sizeof(double), SIZE, fp);
	fclose(fp);

	fp = fopen("bin_file.bin", "rb");
	if(!fp)
	{
		cout<<"Error"<<endl;
		return;
	}
	while((fread(&res, sizeof(double), 1, fp)) > 0)
	{
		cout<<res<<endl;
	}
	if(feof(fp))
	{
		cout<<"feof"<<endl;
	}
	else if(ferror(fp))
	{
		cout<<"ferror"<<endl;
	}
	fclose(fp);
}

void wr_file()
{
	int c = 0;
	const char * ch = "This is a file\n";
	FILE * fp;
	
	fp = fopen("txt_file.txt", "w");
	if(!fp)
	{
		cout<<"Error"<<endl;
		return;
	}
	fputs(ch, fp);
	fclose(fp);

	fp = fopen("txt_file.txt", "r");
	if(!fp)
	{
		cout<<"Error"<<endl;
		return;
	}
	while((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	if(feof(fp))
	{
		cout<<"feof"<<endl;
	}
	else if(ferror(fp))
	{
		cout<<"ferror"<<endl;
	}
	fclose(fp);
}

int main()
{
	bin_wr_file();
	wr_file();
	return 0;
}
