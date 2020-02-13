#include "Ram.h"

Ram::Ram() {
	input = fopen(IN_FILE, "r");
	ramFile = fopen(OUT_FILE, "w+");

	char buff[BUFF_SIZE];
	int bytes;
	while ((bytes = fread(&buff, 1, BUFF_SIZE, input)) > 0) {
		fwrite(&buff, 1, bytes, ramFile);
	}
	fseek(ramFile, 0, SEEK_SET);
	fscanf(ramFile,"%d", &firstAddress);
}

Ram::~Ram() {
	fclose(input);
	fclose(ramFile);
}

int Ram::GetPosition(int address) {
	int line = (address - firstAddress) / sizeof(int);
	return (NEW_LINE + 2 * NR_DIGITS + 1) * line + NR_DIGITS + 1;
}

int Ram::ReadMemory(int address) {
	int pos = GetPosition(address);
	fseek(ramFile, pos, SEEK_SET);
	int value;
	fscanf(ramFile, "%d", &value);

	return value;
}

void Ram::WriteToMemory(int address, int value) {
	int pos = GetPosition(address);
	fseek(ramFile, pos, SEEK_SET);

	char buff[NR_DIGITS + 1];
	IntToString(value, buff);
	fprintf(ramFile, "%s", buff);
}