#include"thread_pool.h"

bool handler(int data)
{
	srand((unsigned int)time(nullptr));
	int n = 1 + rand() % 10;
	printf("thread:%p run task:%d, sleep %d sec\n", pthread_self(), data, n);
	sleep(n);
	return true;
}

int main()
{
	int i;
	ThreadPool pool;
	pool.poolInit();
	for(int i = 0; i < 100; ++i)
	{
		ThreadTask * tt = new ThreadTask(i, handler);
		pool.pushTask(tt);
	}
	pool.poolQuit();
	return 0;
}
