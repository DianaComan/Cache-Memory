#include "CachePrinter.h"

template <typename Tvalue>
CachePrinter<Tvalue>::CachePrinter() {
	fout = fopen(CACHE_OUT, "w");
}

template <typename Tvalue>
CachePrinter<Tvalue>::~CachePrinter() {
	fclose(fout);
}

template <typename Tvalue>
void CachePrinter<Tvalue>::PrintCaches(Cache<Tvalue>& c1, Cache<Tvalue>& c2,
									   Cache<Tvalue>& c3) {
	c1.PrintCache(fout);
	fprintf(fout, "\n");
	c2.PrintCache(fout);
	fprintf(fout, "\n");
	c3.PrintCache(fout);
}

template class CachePrinter<int>;