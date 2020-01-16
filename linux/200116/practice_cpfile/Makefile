.PHONY:all
all:filecp_wrpipe filecp_rdpipe

filecp_wrpipe:filecp_wrpipe.cpp
	g++ -o $@ $^

filecp_rdpipe:filecp_rdpipe.cpp
	g++ -o $@ $^

.PHONY:clean
clean:
	rm -rf filecp_wrpipe filecp_rdpipe
