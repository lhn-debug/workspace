.phony:all
all:1_shared_ptr_thread 2_shared_ptr_circleRef 3_shared_ptr_delete 4_lockGuard

1_shared_ptr_thread:1_shared_ptr_thread.cpp
	g++-4.8 -std=c++11 -o $@ $^ -pthread

2_shared_ptr_circleRef:2_shared_ptr_circleRef.cpp
	g++-4.8 -std=c++11 -o $@ $^

3_shared_ptr_delete:3_shared_ptr_delete.cpp
	g++-4.8 -std=c++11 -o $@ $^

4_lockGuard:4_lockGuard.cpp
	g++-4.8 -std=c++11 -o $@ $^ -pthread

.phony:clean
clean:
	rm -rf 1_shared_ptr_thread 2_shared_ptr_circleRef 3_shared_ptr_delete 4_lockGuard
