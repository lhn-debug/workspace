CC = g++
CXX_FLAGS = -std=c++11 -w 
# gdbµ÷ÊÔÑ¡Ïî -g -rdynamic

BIN = unix-fs

$(BIN): ./obj/main.o ./obj/Buffer.o ./obj/BufferManager.o ./obj/DeviceDriver.o ./obj/File.o ./obj/FileManager.o ./obj/FileSystem.o ./obj/INode.o ./obj/OpenFileManager.o ./obj/User.o ./obj/Utility.o
	$(CC) -o $@ $^
./obj/main.o: main.cpp
	$(CC) $(CXX_FLAGS) -c -o $@ $<
./obj/Buffer.o: Buffer.cpp
	$(CC) $(CXX_FLAGS) -c -o $@ $<
./obj/BufferManager.o: BufferManager.cpp
	$(CC) $(CXX_FLAGS) -c -o $@ $<
./obj/DeviceDriver.o: DeviceDriver.cpp
	$(CC) $(CXX_FLAGS) -c -o $@ $<
./obj/File.o: File.cpp
	$(CC) $(CXX_FLAGS) -c -o $@ $<
./obj/FileManager.o: FileManager.cpp
	$(CC) $(CXX_FLAGS) -c -o $@ $<
./obj/FileSystem.o: FileSystem.cpp
	$(CC) $(CXX_FLAGS) -c -o $@ $<
./obj/INode.o: INode.cpp
	$(CC) $(CXX_FLAGS) -c -o $@ $<
./obj/OpenFileManager.o: OpenFileManager.cpp
	$(CC) $(CXX_FLAGS) -c -o $@ $<
./obj/User.o: User.cpp
	$(CC) $(CXX_FLAGS) -c -o $@ $<
./obj/Utility.o: Utility.cpp
	$(CC) $(CXX_FLAGS) -c -o $@ $<
	
.phony:
clean:
	rm -f ./obj/*.o $(BIN)
	rm -f *.img
