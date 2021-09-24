#include <iostream>
#include <stdlib.h>
#include "file.h"
#include "onegin.h"



int main() 
{
	const char *fin_name  = "textin.txt";
	const char *fout_name = "sorted.txt";
	const int fd     = open_file(fin_name, O_RDONLY);
        const int fd_out = open_file(fout_name, O_WRONLY);

	if (fd == -1 || fd_out == -1)
		return -1;

	int pr_state = onegin(fd, fd_out);

	close_file(fd);
	close_file(fd_out);
	if (pr_state < 0)
		return 1;
	return 0;
}
