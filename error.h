/**
 * @file
 *
 * @brief Set of functions for error handling.
 *
 * @author Varnike
 *
 * @date 21 Sep, 1:40 UTC+3.
 */


#ifndef ERROR_H
#define ERROR_H

/**
 * @brief Stores most recent error code.
 *
 * Heavily lightweight errno analog.
 */
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
/**
 * Returns a pointer to the textual description of the code errtype.
 *
 * Uses error enumeration to determine error string.
 * @param errt error code.
 *
 * @return Pointer to a null-terminated byte string corresponding to the errtype code.
 */

const char *errmsg(int errt);
#endif //ERROR_H
