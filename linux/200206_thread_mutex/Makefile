.phony:all

all:1_pthread_mutex

1_pthread_mutex:1_pthread_mutex.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread

.phony:clean
	
clean:
	rm -rf 1_pthread_mutex
