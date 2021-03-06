#ifndef INPUT_H
#define INPUT_H

#include "error.h"
#include "config.h"

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctype.h>

struct strsize {
	char *strptr;
	char *realptr;
	int len;
};

//int getline(FILE *file, char str[],const int lim);
int readNcnt(FILE *file, char *buff, size_t buffsize);
int count_lines(char *str, const size_t len);
int getFileSize(FILE *file);
int read_in_str(strsize *str, const char *buff, int nlines, size_t buffsize);

#endif // INPUT_H
