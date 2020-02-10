.phony:all
all:1_mysql 2_fang_fun

1_mysql:1_mysql.cpp
	g++-4.8 -std=c++11 -o $@ $^ `mysql_config --cflags --libs`

2_fang_fun:2_fang_fun.cpp
	g++-4.8 -std=c++11 -o $@ $^

.phony:clean
clean:
	rm -rf 1_mysql 2_fang_fun
