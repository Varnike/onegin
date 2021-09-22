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

const char FIN_NAME[]  = "textin.txt";
const char FOUT_NAME[] = "sorted.txt";

void open_files(int *fd_in, int *fd_out);
void close_files(int fd_in, int fd_out);
int filein_size();
/**
 * @brief returns file size(number of characters in file).
 * 
 * @param Name name of the file.
 *
 * @return Number of characters in file. If any errors, returns EOF
 * and changes ERRNUM to FILE_SIZE_ERR.
 */

int getFileSize(const char *name);
void exit_err(int fd, int fd_out);

#endif
