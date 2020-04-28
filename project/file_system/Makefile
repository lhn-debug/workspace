filesystem:./src/main.cpp control.o buffer.o superblock.o sector.o inode.o
	g++ -std=c++11 -o ./bin/filesystem ./src/main.cpp ./obj/control.o ./obj/buffer.o ./obj/superblock.o ./obj/sector.o ./obj/inode.o

inode.o:./src/inode.cpp
	g++ -std=c++11 -c ./src/inode.cpp -o ./obj/inode.o

control.o:./src/control.cpp
	g++ -std=c++11 -c ./src/control.cpp -o ./obj/control.o

sector.o:./src/sector.cpp
	g++ -std=c++11 -c ./src/sector.cpp -o ./obj/sector.o

buffer.o:./src/buffer.cpp
	g++ -std=c++11 -c ./src/buffer.cpp -o ./obj/buffer.o

superblock.o:./src/superblock.cpp
	g++ -std=c++11 -c ./src/superblock.cpp -o ./obj/superblock.o

clean:
	rm -rf ./obj/* ./bin/*
