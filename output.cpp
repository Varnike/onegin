#include "output.h"

int print_str(strsize *arr, size_t strcnt)
{
	if (arr == NULL)
		return errnum = POINTER_ERR;

	for (size_t i = 0; i != strcnt; i++) {
		if (arr == NULL)
		       return errnum = POINTER_ERR;
		if (write(OUTPUT_MODE, arr[i].strptr, arr[i].len + 1) != arr[i].len + 1)
			return errnum = OUTPUT_ERR;	
	}

	return NO_ERR;
}

int clearBuffer(char **arr, size_t strcnt)
{
	if (arr == NULL)
		return errnum = POINTER_ERR;
	for (int i = 0; i != strcnt; i++)
		free(arr[i]);
	return NO_ERR;
}
#if 0
int printstr(strsize *str)
{
	int cnt = 0;
	if (write(STDIN_OUTPUT, str->strptr, str->len + 1) != str->len + 1)
		return EOF;
	return cnt;
}
#endif
