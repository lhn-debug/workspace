.phony:all
all:1_thread_pool

1_thread_pool:1_thread_pool.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread -lrt

.phony:clean
clean:
	rm -rf 1_thread_pool
