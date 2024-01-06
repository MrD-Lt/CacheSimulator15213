#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void print_usage() {
    printf("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\n");
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n\n");
    printf("Examples:\n");
    printf("  linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace\n");
    printf("  linux>  ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
}

int trace_file_exist(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fclose(file);
        return 0;
    }
    printf("Please check the file name.\n");
    return 1;
}

queue_node_t* create_queue_node(int line_index) {
    queue_node_t *new_node = malloc(sizeof(queue_node_t));
    if (new_node==NULL) return NULL;
    new_node->line_index = line_index;
    new_node->next = NULL;
    return new_node;
}

void initQueue(queue_t *q, int q_size) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    q->max_size = q_size;
}

void enqueue(cache_set_t *cache_set, queue_node_t *node) {
    queue_t *q = cache_set->LRU_q;
    if (q->size == q->max_size) {dequeue(cache_set);}
    if (q->rear != NULL) {q->rear->next = node;}
    q->rear = node;
    if (q->size == 0) {q->front = node;}
    q->size++;
}


int dequeue(cache_set_t *cache_set) {
    queue_t *q = cache_set->LRU_q;
    if (q->front == NULL) return 0;
    queue_node_t *temp = q->front;
    set_invalid(cache_set, temp);
    q->front = q->front->next;
    q->size--;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return 1;
}

int isEmpty(queue_t *q) {
    if (q->front == NULL) return 1;
    return 0;
}

void set_invalid(cache_set_t *cache_set, queue_node_t *q) {
    int line_index = q->line_index;
    cache_set->lines[line_index].valid = 0;
}

void freeQueue(queue_t *q) {
    while (q->front != NULL && q->rear != NULL) {
        queue_node_t *temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

void move_to_end(cache_set_t *cache_set, int line_index) {
    queue_t *q = cache_set->LRU_q;
    if (q->front == NULL || q->front == q->rear) {return;}
    queue_node_t *curr = q->front;
    queue_node_t *prev = NULL;
    while (curr != NULL) {
        if (curr->line_index == line_index) {
            if (prev != NULL) prev->next = curr->next;
            else q->front = curr->next;
            if (curr == q->rear) q->rear = prev;
            curr->next = NULL;
            if (q->rear != NULL) q->rear->next = curr;
            q->rear = curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
