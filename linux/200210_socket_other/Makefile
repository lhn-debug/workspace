.phony:all
all:1_string_in_addr 2_inet_ntoa

1_string_in_addr:1_string_in_addr.cpp
	g++-4.8 -std=c++11 -o $@ $^

2_inet_ntoa:2_inet_ntoa.cpp
	g++-4.8 -std=c++11 -o $@ $^ -lpthread

.phony:clean
clean:
	rm -rf 1_string_in_addr 2_inet_ntoa
