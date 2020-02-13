#pragma once

#include "MemoryBlock.h"
#include "Ram.h"
#include <cstring>

template <typename Tfirst, typename Tsecond>
class Pair {
public:
	Tfirst first;
	Tsecond second;

	Pair();
	Pair(Tfirst first, Tsecond second);
	Pair(const Pair& other);

	Pair& operator=(const Pair& other);
};

int countDigits(int number);
void IntToString(int number, char* dest);