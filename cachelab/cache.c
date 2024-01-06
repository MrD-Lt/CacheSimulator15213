#include <stdio.h>
#include "cache.h"

int hits = 0;
int misses = 0;
int evictions = 0;

cache_t* initCache(const int s, const int E, const int b) {
    cache_t* cache = (cache_t*)malloc(sizeof(cache_t));
    if (!cache) {return NULL;}
    cache->b = b;
    cache->s = s;
    cache->num_sets = 1 << s;
    cache->num_lines = E;
    cache->sets = (cache_set_t*)malloc(sizeof(cache_set_t) * cache->num_sets);
    if (!cache->sets) {
        freeCache(cache);
        return NULL;
    }
    for (int i = 0; i < cache->num_sets; i++) {
        cache->sets[i].lines = (cache_line_t*)malloc(sizeof(cache_line_t) * E);
        if (!cache->sets[i].lines) {
            freeCache(cache);
            return NULL;
        }
        for (int j = 0; j < E; j++) {
            cache->sets[i].lines[j].valid = 0;
            cache->sets[i].lines[j].tag = 0;
        }
        cache->sets[i].LRU_q = (queue_t*)malloc(sizeof(queue_t));
        if (!cache->sets[i].LRU_q) {
            freeCache(cache);
            return NULL;
        }
        initQueue(cache->sets[i].LRU_q, E);
    }
    return cache;
}

void freeCache(cache_t *cache) {
    for (int i = 0; i < cache->num_sets; i++) {
        free(cache->sets[i].lines);
        freeQueue(cache->sets[i].LRU_q);
    }
    free(cache->sets);
    free(cache);
}

int access_cache(cache_t* cache, uint64_t address, int size, int verbose, char operation) {
    uint64_t set_index = (address >> cache->b) & ((1ULL << cache->s) - 1);
    uint64_t tag = address >> (cache->b + cache->s);
    cache_set_t* cache_set = &(cache->sets[set_index]);
    queue_t* q = cache_set->LRU_q;
    for (int i = 0; i < cache->num_lines; i++) {
        cache_line_t* curr_line = &(cache_set->lines[i]);
        if (curr_line->valid && curr_line->tag == tag) {
            hits++;
            if (verbose) printf("%c %lx,%d hit\n", operation, address, size);
            move_to_end(cache_set, i);
            return 1;
        }
    }
    misses++;
    if (verbose && operation!='M') printf("%c %lx,%d miss\n", operation, address, size);
    for (int i = 0; i < cache->num_lines; i++) {
        cache_line_t* curr_line = &(cache_set->lines[i]);
        if (curr_line->valid == 0) {
            curr_line->valid = 1;
            curr_line->tag = tag;
            queue_node_t* new_node = create_queue_node(i);
            enqueue(cache_set, new_node); 
            return 0; 
        }
    }
    evictions++;
    if (verbose && operation != 'M') printf("eviction\n");
    int line_to_replace;
    if (q->front != NULL) {
        line_to_replace = q->front->line_index;
        dequeue(cache_set);
    } 
    else line_to_replace = 0;
    cache_line_t* curr_line = &(cache_set->lines[line_to_replace]);
    curr_line->valid = 1;
    curr_line->tag = tag;
    queue_node_t* new_node = create_queue_node(line_to_replace);
    enqueue(cache_set, new_node);
    return 0;
}