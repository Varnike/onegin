#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <cstring>
#include <cassert>
#include <ctype.h>

#include "onegin.h"
#include "input.h"
#include "output.h"

void myqsort(void *arr, int linecnt, size_t size, int (*comp)(const void *, const void *)); 
void _myqsort(void *arr, size_t ssize, int left, int right, int (*comp)(const void *, const void *));
void swap(void *val1, void *val2, size_t vel);
int cmp_front_to_last(const void *str1, const void *str2);
int cmp_last_to_front(const void *str1, const void *str2);
void sortNwrite(struct textBuff *btext);
#endif //SORT_H

