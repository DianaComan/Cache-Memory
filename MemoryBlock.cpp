#include "MemoryBlock.h"

template<typename Tvalue>
MemoryBlock<Tvalue>::MemoryBlock() {
	address = NULL_ADDRESS;
	dirtyBit = false;
}

template<typename Tvalue>
MemoryBlock<Tvalue>::MemoryBlock(int address, Tvalue value) {
	this->address = address;
	this->value = value;
	this->dirtyBit = false;
	this->lastAdded = false;
}

template<typename Tvalue>
MemoryBlock<Tvalue>::MemoryBlock(const MemoryBlock& other) {
	this->address = other.address;
	this->value = other.value;
	this->dirtyBit = other.dirtyBit;
	this->lastAdded = false;
}

template<typename Tvalue>
MemoryBlock<Tvalue>& MemoryBlock<Tvalue>::operator=(const MemoryBlock& other) {
	this->address = other.address;
	this->value = other.value;
	this->dirtyBit = other.dirtyBit;
	this->lastAdded = other.lastAdded;

	return *this;
}

template<typename Tvalue>
int MemoryBlock<Tvalue>::GetAddress() {
	return address;
}

template<typename Tvalue>
Tvalue MemoryBlock<Tvalue>::GetValue() {
	return value;
}

template<typename Tvalue>
void MemoryBlock<Tvalue>::SetValue(Tvalue value) {
	this->value = value;
}

template<typename Tvalue>
void MemoryBlock<Tvalue>::SetDirtyBit() {
	dirtyBit = true;
}

template<typename Tvalue>
void MemoryBlock<Tvalue>::ClearDityBit() {
	dirtyBit = false;
}

template<typename Tvalue>
bool MemoryBlock<Tvalue>::IsDirty() {
	return dirtyBit;
}

template<typename Tvalue>
void MemoryBlock<Tvalue>::SetLastAdded() {
	lastAdded = true;
}

template<typename Tvalue>
void MemoryBlock<Tvalue>::ClearLastAdded() {
	lastAdded = false;
}

template<typename Tvalue>
bool MemoryBlock<Tvalue>::IsLastAdded() {
	return lastAdded;
}

template<typename Tvalue>
void MemoryBlock<Tvalue>::SetAddress(int address) {
	this->address = address;
}

template<typename Tvalue>
void MemoryBlock<Tvalue>::PrintBlock(FILE* fout) {
	fprintf(fout, "%d %d", address, value);
	if (IsDirty()) {
		fprintf(fout, " *");
	}
	fprintf(fout, "\n");
}

template class MemoryBlock<int>;