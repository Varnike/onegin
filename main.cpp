#include <iostream>
#include <stdlib.h>
#include "file.h"
#include "onegin.h"

int main(int argc, char *argv[]) 
{
	int c = 0;
	
	if (argc != 3) {
		fprintf(stderr,"Wrong amount of parameters\n"
			"Usage: %s [input fille name] [output file name]\n", argv[0]);
		return 1;
	}
	
	const char *FIN_NAME  = argv[1];
	const char *FOUT_NAME =	argv[2];

	FILE* file_in   = open_file(FIN_NAME, "r");
        FILE* file_out  = open_file(FOUT_NAME, "w");

	if (file_in == NULL || file_out == NULL)
		return -1;

	int pr_state = onegin(file_in, file_out);

	close_file(file_in);
	close_file(file_out);

	return pr_state;
}
