#include<iostream>
#include<stdlib.h>

using namespace std;

/*
int main(int argc,char *agrv[],char *env[])
{
	int i=0;
	for(;env[i];i++)
	{
		cout<<env[i]<<endl;
	}
	return 0;
}
*/
/*
int main(int argc,char *argv[])
{
	extern char **environ;
	int i=0;
	for(;environ[i];i++)
	{
		cout<<environ[i]<<endl;
	}
	return 0;
}
*/

int main()
{
	cout<<getenv("PATH")<<endl;
	return 0;
}
