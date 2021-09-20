#ifndef ERROR_H
#define ERROR_H

extern int errnum;

enum errtype {
	NO_ERR	     = 0,
	POINTER_ERR  = 1,
	MALLOC_ERR   = 2,
	MAXLINES_ERR = 3,
	MAXLEN_ERR   = 4,
	READ_ERR     = 5,
	OUTPUT_ERR   = 6,
	FILE_PTR_ERR = 7
};
#endif //ERROR_H
