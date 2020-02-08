#include<iostream>
#include<queue>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

#define MAX_THREAD 10

typedef bool (*handler_t)(int);

using namespace std;

class ThreadTask
{
private:
	int _data;
	handler_t _handler;
public:
	ThreadTask()
		:_data(-1),_handler(nullptr)
	{}

	ThreadTask(int data, handler_t handler)
		:_data(data),_handler(handler)
	{}

	void setTask(int data, handler_t handler)
	{
		_data = data;
		_handler = handler;
	}

	void run()
	{
		_handler(_data);
	}
};

class ThreadPool
{
private:
	int _thread_max;
	int _thread_cur;
	bool _tp_quit;
	queue<ThreadTask *> _task_queue;
	pthread_mutex_t _lock;
	pthread_cond_t _cond;
private:
	void lockQueue()
	{
		pthread_mutex_lock(&_lock);
	}

	void unlockQueue()
	{
		pthread_mutex_unlock(&_lock);
	}

	void wakeUpOne()
	{
		pthread_cond_signal(&_cond);
	}

	void wakeUpAll()
	{
		pthread_cond_broadcast(&_cond);
	}

	void threadQuit()
	{
		--_thread_cur;
		unlockQueue();
		pthread_exit(nullptr);
	}

	void threadWait()
	{
		if(_tp_quit)
		{
			threadQuit();
		}
		pthread_cond_wait(&_cond, &_lock);
	}

	bool isEmpty()
	{
		return _task_queue.empty();
	}

	static void * thr_start(void * arg)
	{
		ThreadPool * tp = static_cast<ThreadPool *>(arg);
		while(1)
		{
			tp->lockQueue();
			while(tp->isEmpty())
			{
				tp->threadWait();
			}
			ThreadTask * tt;
			tp->popTask(&tt);
			tp->unlockQueue();
			tt->run();
			delete tt;
		}
		return nullptr;
	}
public:
	ThreadPool(int max = MAX_THREAD)
		:_thread_max(max),
		_thread_cur(max),
		_tp_quit(false)
	{
		pthread_mutex_init(&_lock, nullptr);
		pthread_cond_init(&_cond, nullptr);
	}

	~ThreadPool()
	{
		pthread_mutex_destroy(&_lock);
		pthread_cond_destroy(&_cond);
	}

	bool poolInit()
	{
		pthread_t tid;
		for(int i = 0; i < _thread_max; ++i)
		{
			int ret = pthread_create(&tid, nullptr, thr_start, this);
			if(ret != 0)
			{
				cout<<"create thread pool error..."<<endl;
				return false;
			}
		}
		return true;
	}

	bool pushTask(ThreadTask * tt)
	{
		lockQueue();
		if(_tp_quit)
		{
			unlockQueue();
			return false;
		}
		_task_queue.push(tt);
		wakeUpOne();
		unlockQueue();
		return true;
	}

	bool popTask(ThreadTask ** tt)
	{
		*tt = _task_queue.front();
		_task_queue.pop();
		return true;
	}

	bool poolQuit()
	{
		lockQueue();
		_tp_quit = true;
		unlockQueue();
		while(_thread_cur > 0)
		{
			wakeUpAll();
			sleep(1);
		}
		return true;
	}
};
