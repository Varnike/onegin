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

struct strsize {
	char *strptr;
	char *realptr;
	int len;
};
/**
 * @brief Reads file and counts lines in file.
 *
 * Reads buffsize characters of file to buffer buff and counts lines written.
 * 
 * @param fd File descriptor.
 * @param buff Pointer to buffer.
 * @param buffsize number of characters.
 * @return Number of lines written. If any errors, returns EOF.
 */

int readNcnt(int fd, char *buff, size_t buffsize);
int count_lines(char *str, const size_t len);
/**
 * @brief returns file size(number of characters in file).
 * 
 * @param Name name of the file.
 *
 * @return Number of characters in file. If any errors, returns EOF
 * and changes ERRNUM to FILE_SIZE_ERR.
 *

int getFileSize(const char *name);*/
int read_in_str(strsize *str, const char *buff, int nlines, size_t buffsize);
int isTrash(char c);
#endif // INPUT_H
