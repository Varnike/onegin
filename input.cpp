#include "input.h"

int readNcnt(FILE *file, char *buff, size_t buffsize)
{
	//TODO ferror = 0;
	int fd = fileno(file);
	//printf("%d\n", fd);
	read(fd, buff, buffsize);	
	printf("BUFFSIZE = %zu\n", buffsize);
	//TODO
	if (file == NULL) {
		errnum = FILE_PTR_ERR;
		return EOF;
	}
	
	int nlines = count_lines(buff, buffsize); 
	printf("NLINES = %d\n", nlines);
	return nlines;
}

int read_in_str(strsize *str, const char *buff, int nlines, size_t buffsize) {
	// TODO
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
			
			write(1, str[curr_line -1].strptr, str[curr_line -1].len + 1);
		}
	}	

	write(1, "\n\n",2);
	return nlines;
}


int getFileSize(FILE *file)
{
	if (file == NULL)
		return EOF;

	fseek(file, 0, SEEK_END);
	size_t fsize = ftell(file);
	fseek(file, 0, SEEK_SET);

	return fsize;	
}

int count_lines(char *str, const size_t len)
{
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
