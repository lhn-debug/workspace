#include<iostream>
#include<cstring>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

using namespace std;

void *func(void *arg)
{
	while(true)
	{
		//printf("[%X]:", pthread_self());
		cout<<"func thread running..."<<endl;
		sleep(1);
	}
}

int main()
{
	pthread_t tid;
	int ret;
	if(ret = pthread_create(&tid, NULL, func, NULL) != 0)
	{
		fprintf(stderr, "pthread_create:%s\n", strerror(ret));
		exit(EXIT_FAILURE);
	}
	while(true)
	{
		//printf("[%X]:", pthread_self());
		cout<<"main thread running..."<<endl;
		sleep(1);
	}
	return 0;
}
