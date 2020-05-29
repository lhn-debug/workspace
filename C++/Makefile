.PHONY:all
all:myclass.o main

myclass.o:myclass.cpp
	g++-4.8 -std=c++11 -w -c -o myclass.o myclass.cpp

main:myclass.o main.cpp
	g++-4.8 -std=c++11 -o $@ $^

.PHONY:clean
clean:
	rm -rf main
