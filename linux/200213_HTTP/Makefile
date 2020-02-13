.phony:all
all:http_server

http_server:http_server.cpp
	g++-4.8 -std=c++11 -o $@ $^

.phony:clean
clean:
	rm -rf http_server
