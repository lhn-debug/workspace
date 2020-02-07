#include<iostream>
#include<unistd.h>
#include<pthread.h>

using namespace std;

int shared_val = 10;
pthread_mutex_t mutex;

void * thread_func(void * arg)
{
	while(true)
	{
		pthread_mutex_lock(&mutex);
		if(shared_val)
		{
			sleep(1);
			cout<<static_cast<char *>(arg)<<shared_val<<endl;
			--shared_val;
			pthread_mutex_unlock(&mutex);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
			break;
		}
	}
	return nullptr;
}

int main()
{
	char * msg;
	pthread_t t1, t2, t3, t4;
	
	pthread_mutex_init(&mutex, nullptr);

	msg = "thread 1 shared_val = ";
	pthread_create(&t1, nullptr, thread_func, static_cast<void *>(msg));
	msg = "thread 2 shared_val = ";
	pthread_create(&t2, nullptr, thread_func, static_cast<void *>(msg));
	msg = "thread 3 shared_val = ";
	pthread_create(&t3, nullptr, thread_func, static_cast<void *>(msg));
	msg = "thread 4 shared_val = ";
	pthread_create(&t4, nullptr, thread_func, static_cast<void *>(msg));

	pthread_join(t1, nullptr);
	pthread_join(t2, nullptr);
	pthread_join(t3, nullptr);
	pthread_join(t4, nullptr);

	pthread_mutex_destroy(&mutex);
	return 0;
}
