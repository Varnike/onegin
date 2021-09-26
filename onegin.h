#ifndef ONEGIN_H
#define ONEGIN_H

#include "input.h"
#include "error.h"
#include "sort.h"
#include "file.h"

int sort_onegin(const char *fname_in, const char *fname_out);
int read_from_file(textBuff *btext, const char *name_in);
#endif
