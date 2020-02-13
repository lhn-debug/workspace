.phony:all
all:dict_server dict_multiprocess_server dict_multithread_server

dict_server:dict_server.cpp
	g++-4.8 -std=c++11 -o $@ $^

dict_multiprocess_server:dict_multiprocess_server.cpp
	g++-4.8 -std=c++11 -o $@ $^

dict_multithread_server:dict_multithread_server.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread

.phony:clean
clean:
	rm -rf dict_server dict_multiprocess_server dict_multithread_server
