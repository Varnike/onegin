#ifndef INPUT_H
#define INPUT_H

#include "error.h"
#include "config.h"

#include <sys/stat.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctype.h>
#include <unistd.h> 

struct strsize {
	char *strptr;
	char *realptr;
	int len;
};

int readNcnt(int fd, char *buff, size_t buffsize);
int count_lines(char *str, const size_t len);
int getFileSize(const char *name);
int read_in_str(strsize *str, const char *buff, int nlines, size_t buffsize);

#endif // INPUT_H
