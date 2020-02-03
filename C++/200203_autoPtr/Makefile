.phony:all
all:1_RAII 2_SmartPtr 3_auto_ptr_test 4_auto_ptr

1_RAII:1_RAII.cpp
	g++-4.8 -std=c++11 -o $@ $^

2_SmartPtr:2_SmartPtr.cpp
	g++-4.8 -std=c++11 -o $@ $^

3_auto_ptr_test:3_auto_ptr_test.cpp
	g++-4.8 -std=c++11 -o $@ $^

4_auto_ptr:4_auto_ptr.cpp
	g++-4.8 -std=c++11 -o $@ $^

.phony:clean
clean:
	rm -rf 1_RAII 2_SmartPtr 3_auto_ptr_test 4_auto_ptr
