#include "output.h"

int print_str(textBuff *btext)
{
	static int cnt = 0;
	static char BUFFOUT[BUFSIZ] = {};

	if (btext->str == NULL)
		return ERRNUM = BUFF_PTR_ERR;

	for (size_t i = 0; i != btext->linecnt; i++) {
		int linestr = (btext->str[i].strptr - btext->str[i].realptr) + btext->str[i].len + 1;
		if(fwrite(btext->str[i].realptr, sizeof(char), linestr, 
					btext->file_out) != linestr) {
			return ERRNUM = WRITE_ERR;	
			printf("fff %d\n", linestr);
		}
	}

	fprintf(btext->file_out,"\n\n\n");
	if(fwrite("\n\n\n", sizeof(char), NEWLINE_CNT, btext->file_out) != NEWLINE_CNT)
		return ERRNUM = WRITE_ERR;
         
	return NO_ERR;
}
