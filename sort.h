#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <cstring>
#include <cassert>
#include <ctype.h>

#include "input.h"

void myqsort(strsize *v, int left, int right, int (*comp)(const void *,const void *));
void swap(strsize *v, int i, int j);
int cmp_from_back(const void *str1, const void *str2);
int cmp_from_start(const void *str1, const void *str2);
#endif //SORT_H
