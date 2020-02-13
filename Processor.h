#pragma once

#include "Cache.h"
#include "CachePrinter.h"
#include "MemoryBlock.h"

#define OP_FILE "operations.in"
#define L1_SIZE 11
#define L2_SIZE 13
#define READ_OP 'r'
#define WRITE_OP 'w'

class Processor {
private:
	Cache<int> l1[2];
	Cache<int> l2;
	FILE* fin;
	Ram ram;

	int ChangeCore(int core);
	void AddInL2(int address, int value);

public:
	Processor();
	~Processor();

	void ExecuteOperations();
	void Read(int core, int address);
	void Write(int core, int address, int value);
};