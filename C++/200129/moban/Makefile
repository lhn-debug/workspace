.phony:all
all:1test 2test 3test 4test main

1test:1test.cpp
	g++-4.8 -std=c++11 -o $@ $^

2test:2test.cpp
	g++-4.8 -std=c++11 -o $@ $^

3test:3test.cpp
	g++-4.8 -std=c++11 -o $@ $^

4test:4test.cpp
	g++-4.8 -std=c++11 -o $@ $^

main:main.cpp
	g++-4.8 -std=c++11 -o $@ $^

.phony:clean
clean:
	rm -rf 1test 2test 3test 4test main
