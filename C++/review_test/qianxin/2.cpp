#include<iostream>
#include<stdio.h>

using namespace std;

long zuhe(int base, int shang)
{
	int m = base - shang;
	long tmp = 1;
	int tmp2 = base;
	for(int i = 0; i < m; i++)
	{
		tmp *= (tmp2--);
	}
	return tmp;
}

int main()
{
	int n;
	float f = 1;
	cin>>n;
	if(n == 0)
	{
		f = 0;
		printf("%.6f\n", f);
		return 0;
	}
	if(n > 990)
	{
		printf("%.6f\n", f);
		return 0;
	}
	printf("%.6f\n", f);
	return 0;
}
