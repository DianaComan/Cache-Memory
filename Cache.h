#pragma once

#include "Set.h"
#include "MemoryBlock.h"

#define MAX_CACHE_SIZE 20
#define DEFAULT_SIZE 11

template <typename Tvalue>
class Cache {
private:
	Set<Tvalue> *container;
	int size;
	int HashFunction(int address);

public:
	Cache();
	Cache(int size);
	~Cache();

	bool HasAddress(int address);
	bool HasSpace(int address);
	MemoryBlock<Tvalue> GetPopBlock(int address);
	void WriteToAddress(int address, Tvalue value);
	void SetDirty(int address);
	void ClearDirty(int address);
	bool IsDirty(int address);
	Tvalue GetValue(int address);

	void AddBlock(int address, int value);

	void PrintCache(FILE *fout);
};