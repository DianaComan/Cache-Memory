#pragma once

#include <cstdio>
#include <cstdlib>
#include "Utils.h"

using namespace std;

#define IN_FILE "ram.in"
#define OUT_FILE "ram.out"
#define BUFF_SIZE 1000
#define NR_DIGITS 10
#define NEW_LINE 2

class Ram {
private:
	FILE *input;
	FILE *ramFile;
	int firstAddress;

	int GetPosition(int address);

public:
	Ram();
	~Ram();

	int ReadMemory(int address);
	void WriteToMemory(int address, int value);
};