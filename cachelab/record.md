cachelab-handout git:(main) ✗ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./csim -s 1 -E 1 -b 1 -t traces/yi2.trace

==29517== Memcheck, a memory error detector
==29517== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29517== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==29517== Command: ./csim -s 1 -E 1 -b 1 -t traces/yi2.trace
==29517== 
s = 1, E = 1, b = 1, t = traces/yi2.trace, verbose = 0
==29517== Invalid write of size 8
==29517==    at 0x109C3B: enqueue (utils.c:53)
==29517==    by 0x109FA7: access_cache (cache.c:60)
==29517==    by 0x109467: main (csim.c:71)
==29517==  Address 0x8 is not stack'd, malloc'd or (recently) free'd
==29517== 
==29517== 
==29517== Process terminating with default action of signal 11 (SIGSEGV)
==29517==  Access not within mapped region at address 0x8
==29517==    at 0x109C3B: enqueue (utils.c:53)
==29517==    by 0x109FA7: access_cache (cache.c:60)
==29517==    by 0x109467: main (csim.c:71)
==29517==  If you believe this happened as a result of a stack
==29517==  overflow in your program's main thread (unlikely but
==29517==  possible), you can try to increase the size of the
==29517==  main thread stack using the --main-stacksize= flag.
==29517==  The main thread stack size used in this run was 8388608.
==29517== 
==29517== HEAP SUMMARY:
==29517==     in use at exit: 20,096 bytes in 11 blocks
==29517==   total heap usage: 13 allocs, 2 frees, 20,584 bytes allocated
==29517== 
==29517== 16 bytes in 1 blocks are still reachable in loss record 1 of 9
==29517==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29517==    by 0x109B4E: creat_queue_node (utils.c:30)
==29517==    by 0x109F9C: access_cache (cache.c:59)
==29517==    by 0x109467: main (csim.c:71)
==29517== 
==29517== 24 bytes in 1 blocks are still reachable in loss record 2 of 9
==29517==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29517==    by 0x109CEC: initCache (cache.c:9)
==29517==    by 0x1093E1: main (csim.c:53)
==29517== 
==29517== 32 bytes in 1 blocks are still reachable in loss record 3 of 9
==29517==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29517==    by 0x109D1E: initCache (cache.c:15)
==29517==    by 0x1093E1: main (csim.c:53)
==29517== 
==29517== 32 bytes in 2 blocks are still reachable in loss record 4 of 9
==29517==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29517==    by 0x109D61: initCache (cache.c:21)
==29517==    by 0x1093E1: main (csim.c:53)
==29517== 
==29517== 48 bytes in 2 blocks are still reachable in loss record 5 of 9
==29517==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29517==    by 0x109DA0: initCache (cache.c:30)
==29517==    by 0x1093E1: main (csim.c:53)
==29517== 
==29517== 472 bytes in 1 blocks are still reachable in loss record 6 of 9
==29517==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29517==    by 0x48E164D: __fopen_internal (iofopen.c:65)
==29517==    by 0x48E164D: fopen@@GLIBC_2.2.5 (iofopen.c:86)
==29517==    by 0x1093F4: main (csim.c:54)
==29517== 
==29517== 1,024 bytes in 1 blocks are still reachable in loss record 7 of 9
==29517==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29517==    by 0x48E0BA3: _IO_file_doallocate (filedoalloc.c:101)
==29517==    by 0x48EFCDF: _IO_doallocbuf (genops.c:347)
==29517==    by 0x48EEF5F: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:744)
==29517==    by 0x48ED6D4: _IO_new_file_xsputn (fileops.c:1243)
==29517==    by 0x48ED6D4: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
==29517==    by 0x48D714C: outstring_func (vfprintf-internal.c:239)
==29517==    by 0x48D714C: __vfprintf_internal (vfprintf-internal.c:1263)
==29517==    by 0x4996A5A: __printf_chk (printf_chk.c:33)
==29517==    by 0x1093D4: printf (stdio2.h:112)
==29517==    by 0x1093D4: main (csim.c:52)
==29517== 
==29517== 4,096 bytes in 1 blocks are still reachable in loss record 8 of 9
==29517==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29517==    by 0x48E0BA3: _IO_file_doallocate (filedoalloc.c:101)
==29517==    by 0x48EFCDF: _IO_doallocbuf (genops.c:347)
==29517==    by 0x48EECDB: _IO_file_underflow@@GLIBC_2.2.5 (fileops.c:485)
==29517==    by 0x48EFD95: _IO_default_uflow (genops.c:362)
==29517==    by 0x48C50CF: __vfscanf_internal (vfscanf-internal.c:628)
==29517==    by 0x48C421C: __isoc99_fscanf (isoc99_fscanf.c:30)
==29517==    by 0x109435: main (csim.c:63)
==29517== 
==29517== 14,352 bytes in 1 blocks are still reachable in loss record 9 of 9
==29517==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29517==    by 0x498AA22: monstartup (gmon.c:153)
==29517==    by 0x109610: __gmon_start__ (in /home/mrd/githubrepo/15213/lab04CacheLab/cachelab-handout/csim)
==29517==    by 0x109015: ??? (in /home/mrd/githubrepo/15213/lab04CacheLab/cachelab-handout/csim)
==29517==    by 0x1FFEFFF887: ???
==29517==    by 0x488BE67: call_init (libc-start.c:135)
==29517==    by 0x488BE67: __libc_start_main@@GLIBC_2.34 (libc-start.c:379)
==29517==    by 0x1095D4: (below main) (in /home/mrd/githubrepo/15213/lab04CacheLab/cachelab-handout/csim)
==29517== 
==29517== LEAK SUMMARY:
==29517==    definitely lost: 0 bytes in 0 blocks
==29517==    indirectly lost: 0 bytes in 0 blocks
==29517==      possibly lost: 0 bytes in 0 blocks
==29517==    still reachable: 20,096 bytes in 11 blocks
==29517==         suppressed: 0 bytes in 0 blocks
==29517== 
==29517== For lists of detected and suppressed errors, rerun with: -s
==29517== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)


这是因为：
void enqueue(cache_set_t *cache_set, queue_node_t *node) {
    queue_t *q = cache_set->LRU_q;
    if (q->rear==NULL) {
        q->rear = node;
        q->front = node;
        q->size = 1;
    }
    else {
        if (q->size==q->max_size) {dequeue(cache_set);}
        q->rear->next = node;
        q->rear = node;
        q->size++;
    }
}
在max_size==1的时候会出错