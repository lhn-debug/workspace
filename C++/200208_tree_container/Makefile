.phony:all
all:1_map 2_multimap 3_set 4_multiset

1_map:1_map.cpp
	g++-4.8 -std=c++11 -o $@ $^

2_multimap:2_multimap.cpp
	g++-4.8 -std=c++11 -o $@ $^

3_set:3_set.cpp
	g++-4.8 -std=c++11 -o $@ $^

4_multiset:4_multiset.cpp
	g++-4.8 -std=c++11 -o $@ $^

.phony:clean
clean:
	rm -rf 1_map 2_multimap 3_set 4_multiset
