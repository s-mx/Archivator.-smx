COMPILER=g++
FLAGS=--std=c++11 -c

all: main

main: reader.o writer.o compression.o main.o
	$(COMPILER) -O0 main.o compression.o reader.o writer.o huffman.o

reader.o:
	$(COMPILER) $(FLAGS) ./lib/reader.h ./lib/reader.cpp

writer.o:
	$(COMPILER) $(FLAGS) ./lib/writer.h ./lib/writer.cpp

main.o: compression.o reader.o writer.o
	$(COMPILER) $(FLAGS) ./main.cpp

compression.o: reader.o writer.o huffman.o
	$(COMPILER) $(FLAGS) ./lib/compression.h ./lib/compression.cpp

huffman.o: reader.o writer.o
	$(COMPILER) $(FLAGS) ./lib/huffman.h ./lib/huffman.cpp