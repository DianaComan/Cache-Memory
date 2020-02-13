#include "Processor.h"

Processor::Processor() : l2(Cache<int>(L2_SIZE)) {
	fin = fopen(OP_FILE, "r");
}

Processor::~Processor() {
	fclose(fin);
}

int Processor::ChangeCore(int core) {
	return 1 - core;
}

void Processor::ExecuteOperations() { 
	int core = 0;
	int address = 0;
	int newData = 0;
	char op;
	while (fscanf(fin, "%d %c %d", &core, &op, &address) != EOF) {
		if (op == READ_OP) {
			Read(core, address);
		}
		else if (op == WRITE_OP) {
			fscanf(fin, "%d", &newData);
			Write(core, address, newData);
		}
	}

	CachePrinter<int> printer;
	printer.PrintCaches(l1[0], l1[1], l2);
}

void Processor::AddInL2(int address, int value) {
	if (l2.HasSpace(address)) {
		l2.AddBlock(address, value);
	}
	else {
		MemoryBlock<int> block = l2.GetPopBlock(address);
		ram.WriteToMemory(block.GetAddress(), block.GetValue());
		l2.AddBlock(address, value);
	}
}

void Processor::Read(int core, int address) {
	if (l1[core].HasAddress(address) && !l1[core].IsDirty(address)) {
		return;
	}
	if (l2.HasAddress(address) && !l1[core].HasAddress(address)) {
		l1[core].AddBlock(address, l2.GetValue(address));
		return;
	} 
	if (l2.HasAddress(address) && l1[core].HasAddress(address)) {
		l1[core].WriteToAddress(address, l2.GetValue(address));
		return;
	}

	int value = ram.ReadMemory(address);
	AddInL2(address, value);
	if (l1[core].IsDirty(address)) {
		l1[core].WriteToAddress(address, value);
		return;
	}

	l1[core].AddBlock(address, value);
}

void Processor::Write(int core, int address, int value) {
	if (l1[ChangeCore(core)].HasAddress(address)) {
		l1[ChangeCore(core)].SetDirty(address);
	}

	if (l2.HasAddress(address)) {
		l2.WriteToAddress(address, value);
	}
	else {
		AddInL2(address, value);
	}

	if (l1[core].HasAddress(address)) { 
		l1[core].WriteToAddress(address, value);
	}
	else {
		l1[core].AddBlock(address, value);
	}
}