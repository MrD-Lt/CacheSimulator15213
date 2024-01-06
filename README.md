[中文版](README_SCH.md)
# CacheSimulator15213

## Overview
This project is part of the CMU 15-213 course Cache Lab. The goal is to implement a cache simulator.

Key files include:

1. `csim.c` - Main program
2. `cache.c` / `cache.h` - Cache simulator implementation
3. `utils.c` / `utils.h` - Utility functions

Modified the python version of the original course's `driver.py` to python3.

Most of the content related to Part B has been deleted.

## Technical Details
**Cache Simulator**: Simulates a configurable cache with set count (S), number of cache lines (E), and block size (B). The simulator handles different cache access patterns and reports cache hits, misses, and evictions.

**Data Structures**: Structures are used to represent the cache, cache sets, and cache lines. To implement the LRU (Least Recently Used) replacement policy, each cache set has a queue to track the usage of lines.

**Memory Management**: Special attention was given to the correct allocation and freeing of memory to avoid memory leaks.

**Debugging and Testing**: Debugged using GDB and checked for memory leaks with Valgrind. The program was tested under various cache configurations and access patterns.

Commands
Compile using makefile or the following command line for manual compilation:
```zsh
gcc -Wall -O2 -g -pg csim.c cachelab.c utils.c cache.c -o csim
```
```zsh
make
```
Check for memory leaks using valgrind:
```zsh
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./csim -s 2 -E 1 -b 3 -t traces/trans.trace
```

## Test Results
The simulator performed consistently with the reference simulator across a series of test cases. The test results are as follows:

    Part A: Testing cache simulator
    Running ./test-csim
                            Your simulator     Reference simulator
    Points (s,E,b)    Hits  Misses  Evicts    Hits  Misses  Evicts
        3 (1,1,1)       9       8       6       9       8       6  traces/yi2.trace
        3 (4,2,4)       4       5       2       4       5       2  traces/yi.trace
        3 (2,1,4)       2       3       1       2       3       1  traces/dave.trace
        3 (2,1,3)     167      71      67     167      71      67  traces/trans.trace
        3 (2,2,3)     201      37      29     201      37      29  traces/trans.trace
        3 (2,4,3)     212      26      10     212      26      10  traces/trans.trace
        3 (5,1,5)     231       7       0     231       7       0  traces/trans.trace
        6 (5,1,5)  265189   21775   21743  265189   21775   21743  traces/long.trace

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## Acknowledgements
This project is part of the CMU 15-213 course Cache Lab. The original files are provided by the course page.