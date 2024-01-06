[English Version](README.md)
# CacheSimulator15213

## 概述

此项目是CMU 15-213课程Cache Lab的一部分。目标是实现一个缓存模拟器。

主要文件有：
1. `csim.c` 主程序
2. `cache.c` `cache.h` 缓存模拟器
3. `utils.c` `utils.h` 工具函数

修改了原来课程的`driver.py`到python3。

删除了和Part B相关的大部分内容。

## 技术细节

- **缓存模拟器**：模拟具有设置数量（S）、缓存行数量（E）和块大小（B）的可配置缓存。模拟器处理不同的缓存访问模式，并报告缓存命中、缺失和驱逐的次数。

- **数据结构**：使用结构体表示缓存、缓存集和缓存行。为了实现LRU（最近最少使用）替换策略，每个缓存集都有一个队列来追踪行的使用情况。

- **内存管理**：特别注意内存的正确分配和释放，避免内存泄漏。

- **调试和测试**：使用GDB进行调试，并通过Valgrind检查内存泄漏。程序在多种缓存配置和访问模式下进行了测试。

## 相关命令
编译使用makefile或者命令行手动编译：
```zsh
gcc -Wall -O2 -g -pg csim.c cachelab.c utils.c cache.c -o csim
```
```zsh
make
```
使用valgrind检查内存泄漏：
```zsh
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./csim -s 2 -E 1 -b 3 -t traces/trans.trace
```

## 测试结果

模拟器在一系列测试用例中与参考模拟器的表现一致，测试结果如下：

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
