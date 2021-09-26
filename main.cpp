#include <iostream>
#include <stdlib.h>
#include "file.h"
#include "onegin.h"

int main(int argc, char *argv[]) 
{
	switch(argc) {	
	case 2:
		if (strcmp(argv[1], "-h") == 0) {
			printf("Usage: %s [input fille name] [output file name]\n", argv[0]);
			return 0;
		}
		break;
	case 3:	
		break;
	default:
		fprintf(stderr,"Wrong amount of parameters\n"
                        "Usage: %s [input fille name] [output file name]\n", argv[0]);
                return 1;
		break;
	}
	
	const char *FIN_NAME  = argv[1];
	const char *FOUT_NAME =	argv[2];
	
	int err_state = sort_onegin(FIN_NAME, FOUT_NAME);

	return err_state;
}
