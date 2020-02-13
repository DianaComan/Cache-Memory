#include "Utils.h"

template <typename Tfirst, typename Tsecond>
Pair<Tfirst, Tsecond>::Pair() {
}

template <typename Tfirst, typename Tsecond>
Pair<Tfirst, Tsecond>::Pair(Tfirst first, Tsecond second) {
	this->first = first;
	this->second = second;
}

template <typename Tfirst, typename Tsecond>
Pair<Tfirst, Tsecond>::Pair(const Pair& other) {
	this->first = other.first;
	this->second = other.second;
}

template <typename Tfirst, typename Tsecond>
Pair<Tfirst, Tsecond>& Pair<Tfirst, Tsecond>::operator=(const Pair& other) {
	this->first = other.first;
	this->second = other.second;

	return *this;
}

template class Pair<MemoryBlock<int>, MemoryBlock<int> >;

int countDigits(int number) {
	int count = 0;
	while (number > 0) {
		count++;
		number = number / 10;
	}

	return count;
}
 
void IntToString(int number, char* dest) {
	char buff[NR_DIGITS + 1];

	int count = countDigits(number);
	int i;
	for (i = 0; i < NR_DIGITS - count; i++) {
		dest[i] = '0';
	}
	dest[i] = '\0';

	sprintf(buff, "%d", number);

	strcat(dest, buff);
	dest[NR_DIGITS] = '\0';
}