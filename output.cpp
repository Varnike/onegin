#include "output.h"

int print_str(strsize *arr, size_t strcnt)
{
	if (arr == NULL)
		return errnum = POINTER_ERR;

	for (size_t i = 0; i != strcnt; i++) {
		if (arr == NULL)
		       return errnum = POINTER_ERR;
		if (printf("%s\n", arr[i].realptr) < 0)
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
