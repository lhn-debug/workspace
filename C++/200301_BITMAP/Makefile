.PHONY:all
all:main test

main:main.cpp
	g++-4.8 -std=c++11 -o $@ $^ -g

test:test.cpp
	g++-4.8 -std=c++11 -o $@ $^ -g

.PHONY:clean
clean:
	rm -rf main test
