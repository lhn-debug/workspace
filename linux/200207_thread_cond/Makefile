.phony:all

all:1_pthread_cond 2_BlockQueue 3_RingQueue

1_pthread_cond:1_pthread_cond.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread

2_BlockQueue:2_BlockQueue.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread

3_RingQueue:3_RingQueue.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread

.phony:clean

clean:
	rm -rf 1_pthread_cond 2_BlockQueue 3_RingQueue
