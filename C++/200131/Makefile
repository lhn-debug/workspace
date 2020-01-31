.phony:all
all:1inher 2inher 3inher NonInher

1inher:1inher.cpp
	g++-4.8 -std=c++11 -o $@ $^

2inher:2inher.cpp
	g++-4.8 -std=c++11 -o $@ $^

3inher:3inher.cpp
	g++-4.8 -std=c++11 -o $@ $^

NonInher:NonInher.cpp
	g++-4.8 -std=c++11 -o $@ $^

.phony:clean
clean:
	rm -rf 1inher 2inher 3inher NonInher
