#ifndef INPUT_H
#define INPUT_H

#include "error.h"
#include "config.h"

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>

int getline(FILE *file, char str[],const int lim);
int read_str(FILE *file);
int count_lines(char *str, const size_t len);
int getFileSize(FILE *file);
int read_in_str(char **str, int nlines);

extern char *buff;
#endif // INPUT_H
