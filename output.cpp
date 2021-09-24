#include "output.h"

int print_str(FILE *file, strsize *arr, size_t strcnt)
{
	static int cnt = 0;
	static char BUFFOUT[BUFSIZ] = {};

	if (arr == NULL)
		return ERRNUM = BUFF_PTR_ERR;

	for (size_t i = 0; i != strcnt; i++) {
		int linestr = (arr[i].strptr - arr[i].realptr) + arr[i].len + 1;
		if(fwrite(arr[i].realptr, sizeof(char), linestr, file) != linestr)
			return ERRNUM = WRITE_ERR;	
	}

	fprintf(file,"\n\n\n");
         
	return NO_ERR;
}
