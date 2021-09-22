#include "error.h"

int ERRNUM = NO_ERR;

const char *errmsg(int errt)
{
        const char *messages[] = {
                "Success",
                "Unknown error type!",
                "Calloc error!",
                "An error occured while reading from file!",
                "An error occured while writing into file!",
		"Structure pointer error!",
		"Buffer error!",
		"An error occured while trying to get file size!",
		"An error occured while closing file!",
		"An error occured while opening file!"
        };
        if (errt >= 0 && errt <= ERRS_CNT)
                return messages[errt];


        return messages[UNKNOWN_ERR];
}

