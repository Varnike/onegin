#include <iostream>
#include <stdlib.h>


#include "output.h"
#include "input.h"
#include "error.h"
#include "config.h"
#include "sort.h"


int main() 
{
	FILE *input = fopen("lessgo.txt", "r");
	if(input == NULL) 
		return -1;

	char *buff = 0;

	int buffsize = getFileSize(input);
	buff   = (char  *) calloc(sizeof(char),  buffsize);

	int linecnt =  readNcnt(input, buff, buffsize);

	strsize str[linecnt]= {0};

	read_in_str(str, buff, linecnt, buffsize);	
		
	qsort(str, linecnt, sizeof(strsize), (int (*)(const void *, const void *))(strcomp)); 
	
	printf("errcode = %d\n", print_str(str, linecnt));
	
	fclose(input);
	free(buff);

	return 0;
}
