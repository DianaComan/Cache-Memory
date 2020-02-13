#include "Set.h"

template <typename Tvalue>
void Set<Tvalue>::AddBlock(int address, Tvalue value) {
	MemoryBlock<Tvalue> newBlock(address, value);
	
	if (IsFull()) {
		if (!blocks.first.IsLastAdded()) {
			blocks.first = newBlock;
			blocks.first.SetLastAdded();
			blocks.second.ClearLastAdded();
		}
		else {
			blocks.second = newBlock;
			blocks.second.SetLastAdded();
			blocks.first.ClearLastAdded();
		}
		return;
	}
	int index = GetEmptySlot();
	if (index == FIRST) {
		blocks.first = newBlock;
		blocks.first.SetLastAdded();
		blocks.second.ClearLastAdded();
	}
	else {
		blocks.second = newBlock;
		blocks.second.SetLastAdded();
		blocks.first.ClearLastAdded();
	}
}

template <typename Tvalue>
bool Set<Tvalue>::HasBlock(int address) {
	if (blocks.first.GetAddress() == address ||
		blocks.second.GetAddress() == address) {
		return true;
	}

	return false;
}

template <typename Tvalue>
int Set<Tvalue>::GetBlockIndex(int address) {
	if (blocks.first.GetAddress() == address) {
		return FIRST;
	}
	if (blocks.second.GetAddress() == address) {
		return SECOND;
	}

	return NO_INDEX;
}

template <typename Tvalue>
bool Set<Tvalue>::IsFull() {
	if (blocks.first.GetAddress() != NULL_ADDRESS
		&& blocks.second.GetAddress() != NULL_ADDRESS) {
		return true;
	}

	return false;
}

template <typename Tvalue>
int Set<Tvalue>::GetEmptySlot() {
	if (blocks.first.GetAddress() == NULL_ADDRESS) {
		return FIRST;
	}
	if (blocks.second.GetAddress() == NULL_ADDRESS) {
		return SECOND;
	}

	return NO_INDEX;
}

template <typename Tvalue>
MemoryBlock<Tvalue>& Set<Tvalue>::GetBlock(int address) {
	if (blocks.first.GetAddress() == address) {
		return blocks.first;
	}

	return blocks.second;
}

template <typename Tvalue>
Tvalue Set<Tvalue>::ReadBlock(int address) {
	MemoryBlock<Tvalue>& block = GetBlock(address);
	return block.GetValue();
}

template <typename Tvalue>
void Set<Tvalue>::WriteBlock(int address, Tvalue value) {
	MemoryBlock<Tvalue>& block = GetBlock(address);
	block.SetValue(value);
	block.ClearDityBit();
}

template <typename Tvalue>
void Set<Tvalue>::SetDirtyBit(int address) {
	MemoryBlock<Tvalue>& block = GetBlock(address);
	block.SetDirtyBit();
}

template <typename Tvalue>
void Set<Tvalue>::ClearDirtyBit(int address) {
	MemoryBlock<Tvalue>& block = GetBlock(address);
	block.ClearDityBit();
}

template <typename Tvalue>
bool Set<Tvalue>::IsDirty(int address) {
	if (HasBlock(address)) {
		MemoryBlock<Tvalue>& block = GetBlock(address);
		return block.IsDirty();
	}
	return false;
}

template <typename Tvalue>
MemoryBlock<Tvalue> Set<Tvalue>::GetOldBlock() {
	if (!blocks.first.IsLastAdded()) {
		return blocks.first;
	}

	return blocks.second;
}

template <typename Tvalue>
void Set<Tvalue>::PrintSet(FILE *fout, int index) {
	if (blocks.first.GetAddress() != NULL_ADDRESS) {
		fprintf(fout, "%d %d ", index, FIRST);
		blocks.first.PrintBlock(fout);
	}
	if (blocks.second.GetAddress() != NULL_ADDRESS) {
		fprintf(fout, "%d %d ", index, SECOND);
		blocks.second.PrintBlock(fout);
	}
}

template class Set<int>;