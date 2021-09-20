#ifndef OUTPUT_H
#define OUTPUT_H

#include "error.h"
#include "input.h"

#include <unistd.h>
#include <cstdlib>
#include <stdio.h>

int clearBuffer(char **mass, size_t strcnt);
int print_str(strsize *str, size_t strcnt);
#if 0
int printstr(strsize *str);
#endif

#endif //OUTPUT_H
