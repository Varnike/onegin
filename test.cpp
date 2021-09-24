#include <iostream>
#include <stdlib.h>
#include "file.h"
#include "onegin.h"

const char *FIN_NAME  = "textin.txt";
const char *FOUT_NAME = "sorted.txt";

int main() 
{
	const int fd     = open_file(FIN_NAME, O_RDONLY);
        const int fd_out = open_file(FOUT_NAME, O_WRONLY);

	if (fd == -1 || fd_out == -1)
		return -1;

	int pr_state = onegin(fd, fd_out);

	close_file(fd);
	close_file(fd_out);
	if (pr_state < 0)
		return 1;
	return 0;
}
