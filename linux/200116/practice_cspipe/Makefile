.PHONY:all
all:serverpipe clientpipe

serverpipe:serverpipe.cpp
	g++ -o $@ $^

clientpipe:clientpipe.cpp
	g++ -o $@ $^

.PHONY:clean
clean:
	rm -rf serverpipe clientpipe
