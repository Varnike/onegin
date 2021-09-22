#ifndef OUTPUT_H
#define OUTPUT_H

#include "error.h"
#include "input.h"

#if 0
int clearBuffer(char **mass, size_t strcnt);
#endif
const size_t NEWLINE_CNT = 3;

int print_str(int fd,strsize *str, size_t strcnt);

#endif //OUTPUT_H
