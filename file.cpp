#include "file.h"

void open_files(int *fd, int *fd_out)
{
	*fd = open(FIN_NAME, O_RDONLY, 0);
	*fd_out = open(FOUT_NAME, O_WRONLY, 0);

        if (*fd == -1 || *fd_out == -1) {
		ERRNUM = FOPEN_ERR;
		fprintf(stderr, "%s\n", errmsg(ERRNUM));
		exit(1);
        }
}

void close_files(int fd, int fd_out)
{
	if (close(fd) == EOF || close(fd_out) == EOF) {
                ERRNUM = FCLOSE_ERR;
                fprintf(stderr, "%s\n", errmsg(ERRNUM));
        }
}

int getFileSize(const char *filename)
{
        struct stat statbuf = {};

        if (stat(filename, &statbuf) == -1)
        {
                ERRNUM = FILE_SIZE_ERR;
                return EOF;
        }

        return statbuf.st_size;
}

int filein_size() 
{
	int buffsize = getFileSize(FIN_NAME);
	if (buffsize == EOF) {
                fprintf(stderr, "%s\n", errmsg(ERRNUM));
                exit(1);
        }
	return buffsize;
}

void exit_err(int fd, int fd_out)
{
	fprintf(stderr, "%s\n", errmsg(ERRNUM)); 
	close_files(fd, fd_out);

        exit(1);
}
