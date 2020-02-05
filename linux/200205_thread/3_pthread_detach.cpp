#include<iostream>
#include<unistd.h>
#include<pthread.h>

using namespace std;

void * thread_run(void * arg)
{
	pthread_detach(pthread_self());
	cout<<"running..."<<endl;
	return nullptr;
}

int main()
{
	pthread_t tid;
	if(pthread_create(&tid, nullptr, thread_run, nullptr) != 0)
	{
		cout<<"pthread_create FAILURE"<<endl;
		exit(EXIT_FAILURE);
	}
	cout<<"main thread : "<<pthread_self()<<endl;
	cout<<"func thread : "<<tid<<endl;
	sleep(1);
	if(pthread_join(tid, nullptr) == 0)
	{
		cout<<"pthread wait successful..."<<endl;
	}
	else
	{
		cout<<"pthread wait failed..."<<endl;
	}
	return 0;
}
