#ifndef UTILS_H_
#define UTILS_H_

#include <stdint.h> //used for uint64_t

void print_usage();
int trace_file_exist(const char *filename);

// My queue for LRU
typedef struct queue_node {
    int line_index;
    struct queue_node *next;
} queue_node_t;

typedef struct {
    queue_node_t *front;
    queue_node_t *rear;
    int size;
    int max_size;
} queue_t;

// My Cache
typedef struct {
    int valid;
    uint64_t tag;
} cache_line_t;

typedef struct {
    cache_line_t *lines;
    queue_t *LRU_q;
} cache_set_t;

typedef struct {
    cache_set_t *sets;
    int num_sets;   
    int num_lines;  
    int b;
    int s;
} cache_t;

queue_node_t* create_queue_node(int line_index);
void initQueue(queue_t *q, int q_size);
void enqueue(cache_set_t *cache_set, queue_node_t *node);
int dequeue(cache_set_t *cache_set);
int isEmpty(queue_t *q);
void set_invalid(cache_set_t *cache_set, queue_node_t *q);
void freeQueue(queue_t *q);
void move_to_end(cache_set_t *cache_set, int line_index);


#endif