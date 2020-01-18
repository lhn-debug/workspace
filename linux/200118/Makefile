.PHONY:all
all:sig catch_sig

sig:sig.cpp
	g++ -o $@ $^

catch_sig:catch_sig.cpp
	g++ -o $@ $^

.PHONY:clean
clean:
	rm -rf sig catch_sig
