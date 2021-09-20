#include "input.h"

int readNcnt(int fd, char *buff, size_t buffsize)
{
	if(read(fd, buff, buffsize) != buffsize) {
		ERRNUM = READ_ERR;
		return -1;
	}

	printf("BUFFSIZE = %zu\n", buffsize);	

	int nlines = count_lines(buff, buffsize); 

	printf("NLINES = %d\n", nlines);
	return nlines;
}

int read_in_str(strsize *str, const char *buff, int nlines, size_t buffsize) {
	if (str == NULL) {
		ERRNUM = STRUCT_PTR_ERR;
		return EOF;
	}

	if (buff == NULL) {
		ERRNUM = BUFF_PTR_ERR;
		return EOF;
	}

	int curr_ptr  = 0;
	int curr_line = 0;
	int prev_cnt  = 0;

	for (int i = 0; curr_line < nlines && i != buffsize; i++) {
		if (buff[i] == '\n') {
			if (buff[curr_ptr] == '\n') {
				curr_ptr = i + 1;
				continue;
			}

			str[curr_line].realptr = (char*)(buff + curr_ptr);

			while(!isalpha(buff[curr_ptr]) && !isdigit(buff[curr_ptr]) &&
				       	buff[curr_ptr] != '\0')
				curr_ptr++;

			str[curr_line].strptr = (char*)(buff + curr_ptr);
			str[curr_line++].len = i - curr_ptr; 
			
			curr_ptr = i + 1;
		}
	}	
	return nlines;
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

int count_lines(char *str, const size_t len)
{
	if (str == NULL)
		return EOF;
	int cnt = 0;
	int charcnt = 0;

	for (int i = 0; i != len; i++) {
		if (str[i] == '\n') {
			if (charcnt == 0) 
				continue;
			charcnt = 0;
			cnt++;
		}
		else 
			charcnt++;
	}

	return cnt;
}
