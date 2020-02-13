#pragma once

#include "Cache.h"

#define CACHE_OUT "cache.out"

template <typename Tvalue>
class CachePrinter {
private:
	FILE* fout;

public:
	CachePrinter();
	~CachePrinter();

	void PrintCaches(Cache<Tvalue>& c1, Cache<Tvalue>& c2, Cache<Tvalue>& c3);
};
