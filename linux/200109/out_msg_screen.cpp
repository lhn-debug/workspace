#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	const char * msg = "fwrite(msg, strlen(msg), 1, stdout)\n";
	fwrite(msg, strlen(msg), 1, stdout);
	return 0;
}
