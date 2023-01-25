#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_recur(int *copyarr, int size, int *mainarr);
void merge(int *copyarr, int size, int middle, int *mainarr);
#endif
