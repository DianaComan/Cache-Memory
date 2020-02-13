#pragma once

#include <cstdio>

using namespace std;

#define NULL_ADDRESS -1

template <typename Tvalue>
class MemoryBlock {
private:
	int address;
	Tvalue value;
	bool dirtyBit;
	bool lastAdded;

public:
	MemoryBlock();
	MemoryBlock(int address, Tvalue value);
	MemoryBlock(const MemoryBlock& other);

	MemoryBlock& operator=(const MemoryBlock& other);

	int GetAddress();
	Tvalue GetValue();
	void SetValue(Tvalue value);
	void SetAddress(int address);

	void SetDirtyBit();
	void ClearDityBit();
	bool IsDirty();

	bool IsLastAdded();
	void SetLastAdded();
	void ClearLastAdded();

	void PrintBlock(FILE* fout);
};