#include "cachelab.h"
#include "utils.h"
#include "cache.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h> //used for getopt

#if 0
gcc -Wall -O2 -g -pg csim.c cachelab.c utils.c cache.c -o csim 
用于编译，-Wall 选项用于显示所有警告，-O2 选项用于优化代码，
-g 选项用于生成调试信息，-pg 选项会让编译器生成用于性能分析的信息，-o 选项用于指定输出文件名

./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace 

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./csim -s 2 -E 1 -b 3 -t traces/trans.trace
#endif

int main(int argc, char** argv) {
    int opt;
    int s = -1, E = -1, b = -1;
    char *t = NULL;
    int verbose = 0;
    while ((opt = getopt(argc, argv, "hvs:E:b:t:")) != -1) {
        switch (opt) {
            case 'h':
                print_usage();
                exit(EXIT_SUCCESS);
            case 'v':
                verbose = 1;
                break;
            case 's':
                s = atoi(optarg);
                break;
            case 'E':
                E = atoi(optarg);
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 't':
                t = optarg;
                break;
            default: /* '?' */
                print_usage();
                exit(EXIT_FAILURE);
        }
    }
    if (s == -1 || E == -1 || b == -1 || trace_file_exist(t)) {
        fprintf(stderr, "./csim: Missing required command line argument\n");
        print_usage();
        exit(EXIT_FAILURE);
    }
    printf("s = %d, E = %d, b = %d, t = %s, verbose = %d\n", s, E, b, t, verbose);  
    cache_t* cache = initCache(s, E, b);
    FILE *file = fopen(t, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", t);
        exit(EXIT_FAILURE);
    }
    char operation;
    uint64_t address;
    int size;

    while (fscanf(file, " %c %lx,%d", &operation, &address, &size) == 3) {
        switch (operation) {
            case 'I':
                break;
            case 'L':
                access_cache(cache, address, size, verbose, operation);
                break;
            case 'S':
                access_cache(cache, address, size, verbose, operation);
                break;
            case 'M':
                if (access_cache(cache, address, size, verbose, operation)) {
                    if (verbose) printf("M %lx,%d miss ", address, size);
                }
                access_cache(cache, address, size, verbose, operation);
                break;
        }
    }
    fclose(file);
    printf("\n");
    freeCache(cache);
    
    printSummary(hits, misses, evictions);
    return 0;
}