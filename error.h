#ifndef ERROR_H
#define ERROR_H

extern int ERRNUM;

enum errtype {
	NO_ERR	       = 0,
	UNKNOWN_ERR    = 1,
	CALLOC_ERR     = 2,
	READ_ERR       = 3,
	WRITE_ERR      = 4,
	STRUCT_PTR_ERR = 5,
	BUFF_PTR_ERR   = 6,
	FILE_SIZE_ERR  = 7,
	CLOSEF_ERR     = 8
};

const char *errmsg(int errt);
#endif //ERROR_H
