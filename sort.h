#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <cstring>
#include <cassert>
#include <ctype.h>

#include "input.h"
#include "output.h"

void myqsort(strsize *arr, int left, int right, int (*comp)(const void *,const void *));
void swap(strsize *val1, strsize *val2);
int cmp_from_back(const void *str1, const void *str2);
int cmp_from_start(const void *str1, const void *str2);
void sortNwrite(char *buff, strsize *str, int fd_out, int buffsize, int linecnt);
#endif //SORT_H

