.phony:all
all:1_initializer_list 2_decltype 3_move 4_forward 5_lambda 6_thread 7_fang

1_initializer_list:1_initializer_list.cpp
	g++-4.8 -std=c++11 -o $@ $^

2_decltype:2_decltype.cpp
	g++-4.8 -std=c++11 -o $@ $^

3_move:3_move.cpp
	g++-4.8 -std=c++11 -o $@ $^

4_forward:4_forward.cpp
	g++-4.8 -std=c++11 -o $@ $^

5_lambda:5_lambda.cpp
	g++-4.8 -std=c++11 -o $@ $^

6_thread:6_thread.cpp
	g++-4.8 -std=c++11 -o $@ $^ -pthread

7_fang:7_fang.cpp
	g++-4.8 -std=c++11 -o $@ $^

.phony:clean
clean:
	rm -rf 1_initializer_list 2_decltype 3_move 4_forward 5_lambda 6_thread 7_fang
