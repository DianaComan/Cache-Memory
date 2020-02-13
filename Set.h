#pragma once

#include "Utils.h"
#include "MemoryBlock.h"

#define FIRST 0
#define SECOND 1
#define NO_INDEX -1

template <typename Tvalue>
class Set {
private:
	Pair<MemoryBlock<Tvalue>, MemoryBlock<Tvalue> > blocks;
	int GetEmptySlot();
	MemoryBlock<Tvalue>& GetBlock(int address);

public:
	void AddBlock(int address, Tvalue value);
	bool HasBlock(int address);
	bool IsFull();

	int GetBlockIndex(int address);
	Tvalue ReadBlock(int address);
	void WriteBlock(int address, Tvalue value);
	
	void SetDirtyBit(int address);
	void ClearDirtyBit(int address);
	bool IsDirty(int address);

	MemoryBlock<Tvalue> GetOldBlock();

	void PrintSet(FILE* fout, int index);
};