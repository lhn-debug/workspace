.PHONY:all
all:main_server main_client

main_server:main_server.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread

main_client:main_client.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread

.PHONY:clean
clean:
	rm -rf main_server main_client

