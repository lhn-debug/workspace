#include<iostream>
#include<queue>
#include<cstdlib>
#include<pthread.h>
#include<time.h>
#include<unistd.h>

#define MAX 10

using namespace std;

class BlockQueue
{
private:
	queue<int> q;
	size_t cap;
	pthread_mutex_t lock;
	pthread_cond_t full;
	pthread_cond_t empty;
private:
	void lockQueue()
	{
		pthread_mutex_lock(&lock);
	}

	void unlockQueue()
	{
		pthread_mutex_unlock(&lock);
	}

	void productWait()
	{
		pthread_cond_wait(&full, &lock);
	}

	void consumeWait()
	{
		pthread_cond_wait(&empty, &lock);
	}

	void productNotify()
	{
		pthread_cond_signal(&full);
	}

	void consumeNotify()
	{
		pthread_cond_signal(&empty);
	}

	bool isEmpty()
	{
		return ((q.size() == 0) ? true : false);
	}

	bool isFull()
	{
		return ((q.size() == cap) ? true : false);
	}
public:
	BlockQueue(int _cap = MAX):cap(_cap)
	{
		pthread_mutex_init(&lock, nullptr);
		pthread_cond_init(&full, nullptr);
		pthread_cond_init(&empty, nullptr);
	}

	~BlockQueue()
	{
		pthread_mutex_destroy(&lock);
		pthread_cond_destroy(&full);
		pthread_cond_destroy(&empty);
	}

	void pushData(const int& data)
	{
		lockQueue();
		while(isFull())
		{
			consumeNotify();
			cout<<"queue full, notify consume data, product stop..."<<endl;
			productWait();
		}
		q.push(data);
		consumeNotify();
		unlockQueue();
	}

	void popData(int &data)
	{
		lockQueue();
		while(isEmpty())
		{
			productNotify();
			cout<<"queue empty, notify product data, consume stop..."<<endl;
			consumeWait();
		}
		data = q.front();
		q.pop();
		productNotify();
		unlockQueue();
	}
};

void * Consumer(void * arg)
{
	BlockQueue * pbq = static_cast<BlockQueue *>(arg);
	int data;
	while(true)
	{
		pbq->popData(data);
		cout<<"consume data done: "<<data<<endl;
	}
	return nullptr;
}

void * Producter(void * arg)
{
	BlockQueue * pbq = static_cast<BlockQueue *>(arg);
	srand((unsigned int)time(nullptr));
	while(true)
	{
		int data = rand() % 1024;
		pbq->pushData(data);
		cout<<"product data done: "<<data<<endl;
		sleep(1);
	}
	return nullptr;
}

int main()
{
	BlockQueue bq;
	pthread_t c, p;

	pthread_create(&c, nullptr, Consumer, static_cast<void *>(&bq));
	pthread_create(&p, nullptr, Producter, static_cast<void *>(&bq));

	pthread_join(c, nullptr);
	pthread_join(p, nullptr);
	return 0;
}
