#include "output.h"

int print_str(int fd, strsize *arr, size_t strcnt)
{
	if (arr == NULL)
		return ERRNUM = BUFF_PTR_ERR;

	for (size_t i = 0; i != strcnt; i++) {
		if (write(fd, arr[i].strptr, arr[i].len + 1) != arr[i].len + 1)
			return ERRNUM = WRITE_ERR;	
	}

	if (write(fd, "\n\n\n", 3) != 3)
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
