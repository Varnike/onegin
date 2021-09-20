#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <cstring>
#include <cassert>
#include <ctype.h>

#include "input.h"

//TODO void myqsort(void *v, int left, int right, int (*comp)(void *,void *));
//void swap(char *v, int i, int j);
//int cmpstr(const void *str1, const void *str2);
int cmp_from_back(const void *str1, const void *str2);
int cmp_from_start(const void *str1, const void *str2);
#endif //SORT_H
