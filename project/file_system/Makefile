.PHONY:ALL
ALL:./bin/main

./bin/main:./src/main.cpp
	g++-4.8 -std=c++11 -o $@ $^

.PHONY:clean
clean:
	rm -rf ./bin/main
