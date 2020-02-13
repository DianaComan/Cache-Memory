#include "Cache.h"

template <typename Tvalue>
Cache<Tvalue>::Cache() {
	container = new Set<int>[(1 << DEFAULT_SIZE)];
	size = DEFAULT_SIZE;
}

template <typename Tvalue>
Cache<Tvalue>::Cache(int size) {
	if (size < MAX_CACHE_SIZE) {
		container = new Set<int>[(1 << size)];
		this->size = size;
	}
}

template <typename Tvalue>
Cache<Tvalue>::~Cache() {
	delete[] container;
}

template <typename Tvalue>
int Cache<Tvalue>::HashFunction(int address) {
	return ((1 << size) - 1) & (address >> 2);
}

template <typename Tvalue>
bool Cache<Tvalue>::HasSpace(int address) {
	int set = HashFunction(address);
	return !container[set].IsFull();
}

template <typename Tvalue>
MemoryBlock<Tvalue> Cache<Tvalue>::GetPopBlock(int address) {
	int set = HashFunction(address);
	return container[set].GetOldBlock();
}


template <typename Tvalue>
void Cache<Tvalue>::WriteToAddress(int address, Tvalue value) {
	int set = HashFunction(address);
	container[set].WriteBlock(address, value);
}


template <typename Tvalue>
bool Cache<Tvalue>::HasAddress(int address) {
	int set = HashFunction(address);
	return container[set].HasBlock(address);
}

template <typename Tvalue>
void Cache<Tvalue>::SetDirty(int address) {
	int set = HashFunction(address);
	container[set].SetDirtyBit(address);
}

template <typename Tvalue>
bool Cache<Tvalue>::IsDirty(int address) {
	int set = HashFunction(address);
	return container[set].IsDirty(address);
}

template <typename Tvalue>
void Cache<Tvalue>::ClearDirty(int address) {
	int set = HashFunction(address);
	container[set].ClearDirtyBit(address);
}

template <typename Tvalue>
Tvalue Cache<Tvalue>::GetValue(int address) {
	int set = HashFunction(address);
	return container[set].ReadBlock(address);
}

template <typename Tvalue>
void Cache<Tvalue>::AddBlock(int address, int value) {
	int set = HashFunction(address);
	container[set].AddBlock(address, value);
}

template <typename Tvalue>
void Cache<Tvalue>::PrintCache(FILE* fout) {
	for (int i = 0; i < (1 << size); i++) {
		container[i].PrintSet(fout, i);
	}
}

template class Cache<int>;