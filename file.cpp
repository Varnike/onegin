#include "file.h"

FILE* open_file(const char *filename, const char *mode)
{
	FILE *file = fopen(filename, mode);	

        if (file == NULL) {
		ERRNUM = FOPEN_ERR;
		perror(errmsg(ERRNUM));
		return NULL;
        }

	return file;
}

int close_file(FILE *file)
{
	if (fclose(file) == EOF) {
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

