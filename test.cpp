#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "output.h"
#include "input.h"
#include "error.h"
#include "sort.h"
#include "file.h"

int main() 
{
	int fd       = 0;
        int fd_out   = 0;
	open_files(&fd, &fd_out);

	int buffsize = filein_size();

	char *buff = (char  *) calloc(sizeof(char),  buffsize + 1);
	if (buff == NULL) {
		ERRNUM = CALLOC_ERR;
		exit_err(fd, fd_out);
	}

	int linecnt =  readNcnt(fd, buff, buffsize);
	if (linecnt == EOF) {
		free(buff);
		exit_err(fd, fd_out);
	}

	strsize *str = (strsize *) calloc(sizeof(strsize), linecnt);
	if (str == NULL) {
		ERRNUM = CALLOC_ERR;
      		free(buff);
		exit_err(fd, fd_out);
	}

	if (read_in_str(str, buff, linecnt, buffsize) != linecnt) {
		free(buff);
        	free(str);
		exit_err(fd, fd_out);
	}

	sortNwrite(buff, str, fd_out, buffsize, linecnt);

	close_files(fd, fd_out);

	free(buff);
	free(str);

	return 0;
}
