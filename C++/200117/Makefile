.PHONY:all
all:test testString String

test:test.cpp
	g++-4.8 -std=c++11 -o $@ $^

testString:testString.cpp
	g++-4.8 -std=c++11 -o $@ $^

String:String.cpp
	g++-4.8 -std=c++11 -o $@ $^

.PHONY:clean
clean:
	rm -rf test testString String
