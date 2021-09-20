#include <iostream>
#include <stdlib.h>


#include "output.h"
#include "input.h"
#include "error.h"
#include "config.h"
#include "sort.h"


int main() 
{
	FILE *input = fopen("lust.txt", "r");
	if(input == NULL) 
		return -1;

	char *buff = 0;

	int buffsize = getFileSize(input);
	buff   = (char  *) calloc(sizeof(char),  buffsize + 1);

	int linecnt =  readNcnt(input, buff, buffsize);

	strsize *str= (strsize *) calloc(sizeof(strsize), linecnt);

	read_in_str(str, buff, linecnt, buffsize);	
		
	qsort(str, linecnt, sizeof(strsize), (int (*)(const void *, const void *))(cmp_from_start)); 
		
	printf("\n\n\n======= errcode %d =======\n\n\n", print_str(str, linecnt));
	
	qsort(str, linecnt, sizeof(strsize), (int (*)(const void *, const void *))(cmp_from_back));
	printf("\n\n\n======= errcode %d =======\n\n\n", print_str(str, linecnt));
	
	printf("%s\n", buff);
	fclose(input);
	free(buff);
	free(str);

	return 0;
}
