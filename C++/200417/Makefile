.PHONY:all
all:stack exploit1 call_shellcode

stack:stack.c
	g++-4.8 -std=c++11 -o $@ $^

exploit1:exploit1.c
	g++-4.8 -std=c++11 -o $@ $^

call_shellcode:call_shellcode.c
	g++-4.8 -std=c++11 -o $@ $^

.PHONY:clean
clean:
	rm -rf stack exploit1 call_shellcode
