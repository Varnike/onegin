#include "output.h"

int print_str(int fd, strsize *arr, size_t strcnt)
{
	if (arr == NULL)
		return ERRNUM = BUFF_PTR_ERR;

	for (size_t i = 0; i != strcnt; i++) {
		int linestr = (arr[i].strptr - arr[i].realptr) + arr[i].len + 1;
		if (write(fd, arr[i].realptr, linestr) != linestr)
			return ERRNUM = WRITE_ERR;	
	}

	if (write(fd, "\n\n\n", NEWLINE_CNT) != NEWLINE_CNT)
                        return ERRNUM = WRITE_ERR;

	return NO_ERR;
}
#if 0
int clearBuffer(char **arr, size_t strcnt)
{
	if (arr == NULL)
		return ERRNUM = BUFF_PTR_ERR;
	for (int i = 0; i != strcnt; i++)
		free(arr[i]);
	return NO_ERR;
}
#endif
