#include<iostream>
#include<unistd.h>

using namespace std;

void * thread1(void * arg)
{
	cout<<"thread 1 running..."<<endl;
	int * p = new int(10);
	return static_cast<void *>(p);
}

void * thread2(void * arg)
{
	cout<<"thread 2 running..."<<endl;
	int * p = new int(20);
	pthread_exit(static_cast<void *>(p));
}

void * thread3(void * arg)
{
	while(true)
	{
		cout<<"thread 3 running..."<<endl;
		sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t tid;
	void * ret;

	pthread_create(&tid, NULL, thread1, NULL);
	pthread_join(tid, &ret);
	cout<<"thread 1 "<<tid<<" return "<<*(static_cast<int *>(ret))<<endl;
	free(ret);

	pthread_create(&tid, NULL, thread2, NULL);
	pthread_join(tid, &ret);
	cout<<"thread 2 "<<tid<<" return "<<*(static_cast<int *>(ret))<<endl;
	free(ret);

	pthread_create(&tid, NULL, thread3, NULL);
	sleep(3);
	pthread_cancel(tid);
	pthread_join(tid, &ret);
	if(ret == PTHREAD_CANCELED)
	{
		cout<<"thread 3 "<<tid<<" return "<<"PTHREAD_CANCELED"<<endl;
	}
	else
	{
		cout<<"thread 3 "<<tid<<" return "<<"NULL"<<endl;
	}

	return 0;
}
