.PHONY:all
all:stack_test queue_test priority_queue_test Stack Queue Priority_queue

stack_test:stack_test.cpp
	g++-4.8 -std=c++11 -o $@ $^

queue_test:queue_test.cpp
	g++-4.8 -std=c++11 -o $@ $^

priority_queue_test:priority_queue_test.cpp
	g++-4.8 -std=c++11 -o $@ $^

Stack:Stack.cpp
	g++-4.8 -std=c++11 -o $@ $^

Queue:Queue.cpp
	g++-4.8 -std=c++11 -o $@ $^

Priority_queue:Priority_queue.cpp
	g++-4.8 -std=c++11 -o $@ $^

.PHONY:clean
clean:
	rm -rf stack_test queue_test priority_queue_test Stack Queue Priority_queue
