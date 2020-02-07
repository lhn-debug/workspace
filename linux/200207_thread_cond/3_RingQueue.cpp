#include<iostream>
#include<cstdlib>
#include<vector>
#include<time.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

#define MAX 10

using namespace std;

class RingQueue
{
private:
	vector<int> v;
	size_t cap;
	sem_t data_sem;
	sem_t space_sem;
	int consume_step;
	int product_step;
public:
	RingQueue(int _cap = MAX)
		:v(_cap), cap(_cap), consume_step(0), product_step(0)
	{
		sem_init(&data_sem, 0, 0);
		sem_init(&space_sem, 0, cap);
	}

	~RingQueue()
	{
		sem_destroy(&data_sem);
		sem_destroy(&space_sem);
	}

	void pushData(const int& data)
	{
		sem_wait(&space_sem);
		v[consume_step] = data;
		consume_step++;
		consume_step %= cap;
		sem_post(&data_sem);
	}

	void popData(int &data)
	{
		sem_wait(&data_sem);
		data = v[product_step];
		product_step++;
		product_step %= cap;
		sem_post(&space_sem);
	}
};

void * consumer(void * arg)
{
	RingQueue * prq = static_cast<RingQueue *>(arg);
	int data;
	while(true)
	{
		prq->popData(data);
		cout<<"consume data done: "<<data<<endl;
	}
	return nullptr;
}

void * producter(void * arg)
{
	RingQueue * prq = static_cast<RingQueue *>(arg);
	srand((unsigned int)time(nullptr));
	while(true)
	{
		int data = rand() % 1024;
		prq->pushData(data);
		cout<<"product data done: "<<data<<endl;
		sleep(1);
	}
	return nullptr;
}

int main()
{
	RingQueue rq;
	pthread_t c, p;

	pthread_create(&c, nullptr, consumer, static_cast<void *>(&rq));
	pthread_create(&p, nullptr, producter, static_cast<void *>(&rq));

	pthread_join(c, nullptr);
	pthread_join(p, nullptr);
	return 0;
}
