.phony:all
all:1_c_typechange 2_cpp_static_cast 3_cpp_reinterpret_cast 4_cpp_const_cast 5_cpp_dynamic_cast 6_explicit

1_c_typechange:1_c_typechange.c
	gcc -o $@ $^

2_cpp_static_cast:2_cpp_static_cast.cpp
	g++-4.8 -std=c++11 -o $@ $^

3_cpp_reinterpret_cast:3_cpp_reinterpret_cast.cpp
	g++-4.8 -std=c++11 -o $@ $^

4_cpp_const_cast:4_cpp_const_cast.cpp
	g++-4.8 -std=c++11 -o $@ $^

5_cpp_dynamic_cast:5_cpp_dynamic_cast.cpp
	g++-4.8 -std=c++11 -o $@ $^

6_explicit:6_explicit.cpp
	g++-4.8 -std=c++11 -o $@ $^

.phony:clean
clean:
	rm -rf 1_c_typechange 2_cpp_static_cast 3_cpp_reinterpret_cast 4_cpp_const_cast 5_cpp_dynamic_cast 6_explicit
