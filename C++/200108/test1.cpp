#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

//变量存在数据段
int globalVar = 1;
static int staticGlobalVar = 1;

int main()
{
	static int staticVar = 1;	//变量存在数据段

	//以下所有变量存在栈区
	int localVar = 1;
	int num1[10] = {1,2,3,4};
	char char2[] = "abcd";	//值存在代码段
	char *pchar3 = "abcd";	//值存在代码段
	int *ptr1 = (int*)malloc(sizeof(int)*4);	//值存在堆
	int *ptr2 = (int*)calloc(4,sizeof(int));	//值存在堆
	int *ptr3 = (int*)realloc(ptr2,sizeof(int)*4);	//值存在堆
	
	cout<<sizeof(num1)<<endl;	//40
	cout<<sizeof(char2)<<endl;	//5
	cout<<strlen(char2)<<endl;	//4
	cout<<sizeof(pchar3)<<endl;	//8
	cout<<strlen(pchar3)<<endl;	//4
	cout<<sizeof(ptr1)<<endl;	//8

	free(ptr1);
	free(ptr3);
	return 0;
}
