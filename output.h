#ifndef OUTPUT_H
#define OUTPUT_H

#include "error.h"
#include "input.h"

#include <cstdlib>
#include <stdio.h>

int clearBuffer(char **mass, size_t strcnt);
int print_str(strsize *mass, size_t strcnt);

#endif //OUTPUT_H
