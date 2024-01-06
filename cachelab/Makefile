#
# Student makefile for Cache Lab
# Note: requires a 64-bit x86-64 system 
#
CC = gcc
CFLAGS = -Wall -O2 -g -pg -Werror -std=c99 -m64

csim: csim.c cachelab.c cachelab.h utils.c cache.c
	$(CC) $(CFLAGS) -o csim csim.c cachelab.c utils.c cache.c -lm 
#
# Clean the src dirctory
#
clean:
	rm -rf *.o
	rm -f *.tar
	rm -f csim
	rm -f test-trans tracegen
	rm -f trace.all trace.f*
	rm -f .csim_results .marker
	rm -f gmon.out
	rm -f driver.py.bak


