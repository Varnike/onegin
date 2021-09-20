#ifndef ERROR_H
#define ERROR_H

extern int ERRNUM;

const int ERRS_CNT = 9;

enum errtype {
	NO_ERR	       = 0,
	UNKNOWN_ERR    = 1,
	CALLOC_ERR     = 2,
	READ_ERR       = 3,
	WRITE_ERR      = 4,
	STRUCT_PTR_ERR = 5,
	BUFF_PTR_ERR   = 6,
	FILE_SIZE_ERR  = 7,
	FCLOSE_ERR     = 8,
	FOPEN_ERR      = 9
};

const char *errmsg(int errt);
#endif //ERROR_H
