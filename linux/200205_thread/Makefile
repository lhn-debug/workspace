.phony:all

all:1_pthread_create 2_pthread_join 3_pthread_detach

1_pthread_create:1_pthread_create.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread

2_pthread_join:2_pthread_join.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread

3_pthread_detach:3_pthread_detach.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread

.phony:clean

clean:
	rm -rf 1_pthread_create 2_pthread_join 3_pthread_detach
