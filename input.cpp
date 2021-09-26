#include "input.h"

int readNcnt(textBuff *btext)
{
	int fd = fileno(btext->file_in);
	if(read(fd, btext->buff, btext->buffsize) != btext->buffsize) {
		ERRNUM = READ_ERR;
		return -1;
	}

	printf("BUFFSIZE = %zu\n", btext->buffsize);	

	btext->linecnt = count_lines(btext->buff, btext->buffsize); 

	printf("NLINES = %d\n", btext->linecnt);
	return btext->linecnt;
}

int read_in_str(textBuff *btext) {
	if (btext->str == NULL) {
		ERRNUM = STRUCT_PTR_ERR;
		return EOF;
	}

	if (btext->buff == NULL) {
		ERRNUM = BUFF_PTR_ERR;
		return EOF;
	}

	int curr_ptr  = 0;
	int curr_line = 0;
	int prev_cnt  = 0;

	for (int i = 0; curr_line < btext->linecnt && i != btext->buffsize; i++) {
		if (btext->buff[i] == '\n') {
			if (btext->buff[curr_ptr] == '\n') {
				curr_ptr = i + 1;
				continue;
			}

			btext->str[curr_line].realptr = (char*)(btext->buff + curr_ptr);
			
			while(isTrash(btext->buff[curr_ptr]) && btext->buff[curr_ptr] != '\n')
				curr_ptr++;

			btext->str[curr_line].strptr = (char*)(btext->buff + curr_ptr);
			btext->str[curr_line++].len = i - curr_ptr; 
			
			curr_ptr = i + 1;
		}
	}

	return btext->linecnt;
}

int isTrash(char c)
{
	return !isalpha(c) && !isdigit(c);
}

int count_lines(char *str, const size_t len)
{
	if (str == NULL)
		return EOF;
	int cnt = 0;
	int i = 0;
	for (i = 0; i != len; i++)
		if (str[i] != '\n')
			break;

	for ( ; i != len; i++) {
		if (str[i] == '\n' && str[i-1] != '\n')
			cnt++;
	}
	return cnt;
}
