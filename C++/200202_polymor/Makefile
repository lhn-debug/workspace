.phony:all
all:1abstract_class 2virtual_fun_table 3virtual_fun_table

1abstract_class:1abstract_class.cpp
	g++-4.8 -std=c++11 -o $@ $^

2virtual_fun_table:2virtual_fun_table.cpp
	g++-4.8 -std=c++11 -o $@ $^

3virtual_fun_table:3virtual_fun_table.cpp
	g++-4.8 -std=c++11 -rdynamic -lpthread -o $@ $^

.phony:clean
clean:
	rm -rf 1abstract_class 2virtual_fun_table 3virtual_fun_table
