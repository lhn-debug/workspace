#include "fs.h"

int main()
{
	int *p, num = 100;
	p = &num;
	cout<<p<<endl;
	p += 1024;
	cout<<num<<endl;
	cout<<*p<<endl;
	cout<<p<<endl;
	return 0;
}
