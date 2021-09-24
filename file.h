/**
 * @file
 *
 * @brief Set of functions for working with files.
 *
 * @author Varnike
 *
 * @date 21 Sep, 1:40 UTC+3.
 */


#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "output.h"
#include "error.h"
#include "input.h"

/**
 * @brief Opens file.
 *
 * If any error is occured, prints error in strerr.
 *
 * @param filename Name name of the file.
 * @param mode Open mode.
 *
 * @return FILE* structure on success, overwise returns NULL.
 */
FILE* open_file(const char *filename, const char *mode);

/**
 * @brief Close file with given descriptor.
 *
 * If any error is occured, prints error in strerr.
 *
 * @param fd FILE* structure.
 *
 * @return 0 on success, overwise returns -1.
 */
int close_file(FILE *file);

/**
 * @brief returns file size(number of characters in file).
 * 
 * @param Name name of the file.
 *
 * @return Number of characters in file. If any errors, returns EOF
 * and changes ERRNUM to FILE_SIZE_ERR.
 */

int getFileSize(const char *name);

#endif
