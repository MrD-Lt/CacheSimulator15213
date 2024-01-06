#ifndef CACHE_H_
#define CACHE_H_

#include <stdlib.h>
#include "utils.h"

extern int hits;
extern int misses;
extern int evictions;

cache_t* initCache(const int s, const int E, const int b);
void freeCache(cache_t *cache);
int access_cache(cache_t* cache, uint64_t address,int size, int verbose, char operation);

#endif