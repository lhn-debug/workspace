.phony:all
all:./bin/atm_client ./bin/atm_server

./bin/atm_client:./client_ATM/atm_client.cpp
	g++-4.8 -std=c++11 -o $@ $^

./bin/atm_server:./server_ATM/atm_server.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread `mysql_config --cflags --libs`

.phony:clean
clean:
	rm -rf ./bin/atm_client ./bin/atm_server
