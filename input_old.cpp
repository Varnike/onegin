#include "input.h"

char *BUFF = NULL;

int read_str(FILE *file, char **str)
{
	size_t fsize = getFileSize(file);
	
	BUFF = (char *) malloc(sizeof(char) * fsize);

	//TODO ferror = 0;
	fread(BUFF, sizeof(char), fsize, file);
	

	//TODO
	if (file == NULL) {
		errnum = POINTER_ERR;
		return EOF;
	}
	
	int nlines = count_lines(BUFF, fsize); 
	printf("___nlines = %d___\n", nlines);
	return nlines;
}

int read_in_str(char **str, int nlines) {
	//char **str = (char**) calloc(sizeof(int), nlines); 

	int curr_ptr  = 0;
	int curr_line = 0;
	int prev_cnt  = 0;

	for (int i = 0; i != fsize && curr_line <= nlines; i++) {
		if (BUFF[i] == '\0') {
			if (BUFF[i - 1] == '\0') {
				curr_ptr = i + 1;
				continue;
			}
			char *p = (char*) calloc(sizeof(char), strlen(BUFF + curr_ptr));
			strcpy(p, BUFF + curr_ptr);
			str[curr_line++] = p;
			curr_ptr = i + 1;
			printf("---%s\n", str[curr_line -1]);
		}
	}	
///	free(BUFF);	
	if (str == NULL) printf("FUUUCK!\n");	
#if 0
	int len = 0, nlines = 0;
	char *ptr = NULL; 
	char linein[MAXLEN] = {0};

	while (len = getline(file, linein, MAXLEN) > 0) {
		if (nlines > MAXLINE) {
			errnum = MAXLINES_ERR;
			return EOF;
		}

		if (linein[0] == '\0' || linein[0] == '\n')
			continue;

		if ((ptr = (char*) calloc(sizeof(char), len)) == NULL) {
			errnum = MALLOC_ERR;
			return EOF;
		}
		
		strcpy(ptr, linein);
		str[nlines++] = ptr;	
	}
#endif
	return nlines;
}



int getline(FILE *file, char *str,const int lim)
{
	assert(file);
	//TODO
	int c = 0, cnt = 0;

	for (; cnt < lim - 1 && (c = fgetc(file)) != EOF && c != '\n'; ++cnt)
		str[cnt] = c;

	if (c == '\n') {
		str[cnt] = '\0';
		++cnt;
	} else if (cnt != 0) {
		str[cnt++] = '\0';
	}

	return cnt;
}


int getFileSize(FILE *file)
{
	if (file == NULL)
		return EOF;

	fseek(file, 0, SEEK_END);
	size_t fsize = ftell(file);
	fseek(file, 0, SEEK_SET);

	return fsize;	
}

int cntline(char *str, const size_t len) 
{
	int cnt = 0;
	int charcnt = 0;
	for (int i = 0; i != len, i++) {
		if ()
	}
}

int set_lines(char *str, const size_t len)
{
	int cnt = 0;
	int charcnt = 0;
	for (int i = 0; i != len; i++) {
		if (str[i] == '\n') {
			str[i] = '\0';
			if (charcnt == 0) 
				continue;
			charcnt = 0;
			cnt++;
		}
		else 
			charcnt++;
	}
	return cnt;
}
