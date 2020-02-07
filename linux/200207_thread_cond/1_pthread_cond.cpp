#include<iostream>
#include<unistd.h>
#include<pthread.h>

using namespace std;

pthread_mutex_t mutex;
pthread_cond_t cond;

int shared_val = 10;

void * thread_func1(void * arg)
{
	pthread_mutex_lock(&mutex);
	while(shared_val--)
	{
		pthread_cond_wait(&cond, &mutex);
		cout<<"activity..."<<shared_val<<endl;
	}
	pthread_mutex_unlock(&mutex);
	return nullptr;
}

void * thread_func2(void * arg)
{
	while(true)
	{
		pthread_cond_signal(&cond);
		sleep(1);
	}
	return nullptr;
}

int main()
{
	pthread_t t1, t2;

	pthread_mutex_init(&mutex, nullptr);
	pthread_cond_init(&cond, nullptr);
	
	pthread_create(&t1, nullptr, thread_func1, nullptr);
	pthread_create(&t2, nullptr, thread_func2, nullptr);

	pthread_join(t1, nullptr);
	pthread_join(t2, nullptr);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	return 0;
}
