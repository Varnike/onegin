#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "output.h"
#include "input.h"
#include "error.h"
#include "sort.h"

const char *fin_name = "textin.txt";
const char *fout_name = "sorted.txt";

int main() 
{
	int fd       = 0;
	int fd_out   = 0;
	int linecnt  = 0;
	int buffsize = 0;
	char *buff   = NULL;
	strsize *str = NULL;

	if ((buffsize = getFileSize(fin_name)) == EOF) {
		fprintf(stderr, "%s\n", errmsg(ERRNUM));
                return -1;
	}

	if((fd = open(fin_name, O_RDONLY, 0)) == -1 || (fd_out = open(fout_name, O_WRONLY, 0)) == -1) {
         	ERRNUM = FOPEN_ERR;
                fprintf(stderr, "%s\n", errmsg(ERRNUM));
	 	return -1;
	}

	if ((buff = (char  *) calloc(sizeof(char),  buffsize + 1)) == NULL) {
		ERRNUM = CALLOC_ERR;
		fprintf(stderr, "%s\n", errmsg(ERRNUM));
		return -1;
	}

	if ((linecnt =  readNcnt(fd, buff, buffsize)) == EOF) {
		fprintf(stderr, "%s\n", errmsg(ERRNUM));
		free(buff);
		return -1;
	}

	if ((str = (strsize *) calloc(sizeof(strsize), linecnt)) == NULL) {
		ERRNUM = CALLOC_ERR;
                fprintf(stderr, "%s\n", errmsg(ERRNUM));
		free(buff);
                return -1;
	}

	if (read_in_str(str, buff, linecnt, buffsize) != linecnt) {
                fprintf(stderr, "%s\n", errmsg(ERRNUM));
		free(buff);
        	free(str);
                return -1;	
	}	
	
	myqsort(str, 0, linecnt - 1, (int (*)(const void *, const void *))(cmp_from_start));
	//qsort(str, linecnt, sizeof(strsize), (int (*)(const void *, const void *))(cmp_from_start));
	if (print_str(fd_out, str, linecnt) != NO_ERR)
		fprintf(stderr, "%s\n", errmsg(ERRNUM));

	
	qsort(str, linecnt, sizeof(strsize), (int (*)(const void *, const void *))(cmp_from_back));
       	if (print_str(fd_out, str, linecnt) != NO_ERR)
		fprintf(stderr, "%s\n", errmsg(ERRNUM));


	if (write(fd_out, buff, buffsize) != buffsize) {
		ERRNUM = WRITE_ERR;
		fprintf(stderr, "%s\n", errmsg(ERRNUM));
	}
	

	if (close(fd) == EOF) {
		ERRNUM = FCLOSE_ERR;
                fprintf(stderr, "%s\n", errmsg(ERRNUM));
	}

	free(buff);
	free(str);

	return 0;
}
