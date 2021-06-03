all: mkdir_bin clean hello_c hello_cpp

CC=arm-linux-gnueabi-gcc
CXX=arm-linux-gnueabi-g++
LD=arm-linux-gnueabi-ld
C_FLAGS=

mkdir_bin:
	mkdir -p bin

hello_c: src/hello_c.c
	$(CC) -o bin/hello_c src/hello_c.c $(C_FLAGS)

hello_cpp: src/hello_cpp.cpp
	$(CXX) -o bin/hello_cpp src/hello_cpp.cpp $(C_FLAGS)

clean:
	rm -rf bin/*

