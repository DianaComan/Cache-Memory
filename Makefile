all: build 

build: Main.o MemoryBlock.o Processor.o Ram.o Set.o Utils.o Cache.o CachePrinter.o
	g++ -std=c++11 Main.o MemoryBlock.o Processor.o Ram.o Set.o Utils.o Cache.o CachePrinter.o -o tema1

.o: 
	g++ -std=c++11 -Wall -g -c $?

clean:
	-rm -f *.o tema1