#include "output.h"

int print_str(int fd, strsize *arr, size_t strcnt)
{
	static int cnt = 0;
	static char BUFFOUT[BUFSIZ] = {};

	if (arr == NULL)
		return ERRNUM = BUFF_PTR_ERR;

	for (size_t i = 0; i != strcnt; i++) {
		int linestr = (arr[i].strptr - arr[i].realptr) + arr[i].len + 1;
		
		if (cnt + linestr > BUFSIZ) {
			int in_buff = BUFSIZ - cnt;
			strncpy(BUFFOUT + cnt, arr[i].realptr, in_buff);

			if (write(fd, BUFFOUT, BUFSIZ) != BUFSIZ)
				return ERRNUM = WRITE_ERR;

			strncpy(BUFFOUT, arr[i].realptr + in_buff, linestr - in_buff);

			cnt = linestr - in_buff;
		} else {
			strncpy(BUFFOUT + cnt, arr[i].realptr, linestr);

			cnt += linestr;
		}

	}

	if (cnt != 0)
		if (write(fd, BUFFOUT, cnt) != cnt)
			return ERRNUM = WRITE_ERR;

	if (write(fd, "\n\n\n", NEWLINE_CNT) != NEWLINE_CNT)
                        return ERRNUM = WRITE_ERR;

	return NO_ERR;
}
