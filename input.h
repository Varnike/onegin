/**
 * @file
 *
 * @brief Set of functions which can be used to solve linear or quadratic equation.
 *
 * @author Varnike
 *
 * @date 21 Sep, 1:40 UTC+3.
 */

#ifndef INPUT_H
#define INPUT_H

#include "error.h"

#include <sys/stat.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctype.h>
#include <unistd.h> 
#include <stdio.h>

struct strsize {
        char *strptr;
        char *realptr;
        int len;
};

struct textBuff {
        int linecnt;
        size_t buffsize;
        strsize *str;
        char *buff;
        FILE *file_out;
        FILE *file_in;
};

int readNcnt(textBuff *btext);
int count_lines(char *str, const size_t len);
int read_in_str(textBuff *btext);
int isTrash(char c);

#endif // INPUT_H
