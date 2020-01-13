#include<iostream>
#include<stdio.h>
#include<cstring>
#include<unistd.h>

using namespace std;

int main()
{
	const char * msg0 = "cout\n";
	const char * msg1 = "fwrite\n";
	const char * msg2 = "write\n";
	cout<<msg0;
	fwrite(msg1, strlen(msg1), 1, stdout);
	write(1, msg2, strlen(msg2));
	return 0;
}
