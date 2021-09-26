#include "onegin.h"

int sort_onegin(const char* name_in, const char* name_out) 
{
	if (name_in == NULL || name_out == NULL)
		return -1;

	textBuff btext = {};
	
	btext.file_in   = open_file(name_in, "r");                                                  
        btext.file_out  = open_file(name_out, "w");                                                 
                                                                                                     
        if (btext.file_in == NULL || btext.file_out == NULL)
		return -1;


	int err = read_from_file(&btext, name_in);
	if (!err)
        	sortNwrite(&btext);

	free(btext.buff);
	free(btext.str);

	return err;
}

int read_from_file(textBuff *btext, const char* name_in)
{
	btext->buffsize = getFileSize(name_in);                                                    
        if (btext->buffsize == EOF)
		return -1;                                                                                                                                                                
        btext->buff = (char  *) calloc(sizeof(char),  btext->buffsize + 1);
        if (btext->buff == NULL) {
		ERRNUM = CALLOC_ERR;                                                                 
                perror(errmsg(ERRNUM));
		return -1;		
        }                                                                                            
                                                                                                     
        btext->linecnt =  readNcnt(btext);
	if (btext->linecnt == EOF) {
		perror(errmsg(ERRNUM));
		return -1;		
        }                                                                                            
                                                                                                     
        btext->str = (strsize *) calloc(sizeof(strsize), btext->linecnt);
	if (btext->str == NULL) {
		ERRNUM = CALLOC_ERR;
		perror(errmsg(ERRNUM));
		return -1;		
        }                                                                                            
                                                                                                     
        if (read_in_str(btext) != btext->linecnt) {                                  
                perror(errmsg(ERRNUM));
		return -1;
        }

	return 0;
}
