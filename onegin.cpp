#include "onegin.h"

int onegin(const int fd, const int fd_out)
{
	int buffsize = getFileSize("textin.txt");                                                    
        if (buffsize == EOF)                                                                         
                return -1;                                                                           
                                                                                                     
        char *buff = (char  *) calloc(sizeof(char),  buffsize + 1);                                  
        if (buff == NULL) {                                                                          
                ERRNUM = CALLOC_ERR;                                                                 
                perror(errmsg(ERRNUM));
		return -1;		
        }                                                                                            
                                                                                                     
        int linecnt =  readNcnt(fd, buff, buffsize);                                                 
        if (linecnt == EOF) {                                                                        
                free(buff);                                                                          
                perror(errmsg(ERRNUM));
		return -1;		
        }                                                                                            
                                                                                                     
        strsize *str = (strsize *) calloc(sizeof(strsize), linecnt);                                 
        if (str == NULL) {                                                                           
                ERRNUM = CALLOC_ERR;                                                                 
                free(buff);                                                                          
                perror(errmsg(ERRNUM));
		return -1;		
        }                                                                                            
                                                                                                     
        if (read_in_str(str, buff, linecnt, buffsize) != linecnt) {                                  
                free(buff);
                free(str);
                perror(errmsg(ERRNUM));
		return -1;
        }

        sortNwrite(buff, str, fd_out, buffsize, linecnt);

	free(buff);
	free(str);
	return 0;
}
