#include "file.h"

int open_file(const char *filename, int mode)
{
	int fd = open(filename, mode, 0);

        if (fd == -1) {
		ERRNUM = FOPEN_ERR;
		perror(errmsg(ERRNUM));
		return -1;
        }

	return fd;
}

int close_file(const int fd)
{
	if (close(fd) == EOF) {
                ERRNUM = FCLOSE_ERR;
                perror(errmsg(ERRNUM));
		return -1;
        }
	return 0;
}

int getFileSize(const char *filename)
{
        struct stat statbuf = {};

        if (stat(filename, &statbuf) == -1)
        {
                ERRNUM = FILE_SIZE_ERR;
		perror(errmsg(ERRNUM));
                return EOF;
        }

        return statbuf.st_size;
}

