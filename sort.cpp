#include "sort.h"

void myqsort(strsize *arr, int left, int right, int (*comp)(const void *, const void *))
{
	assert(arr);

	int i = 0, last = 0;

	if (left >= right) 
		return; 
	
	swap(arr + left, arr + (left+ right) / 2);
	
	last = left;

	for (i = left + 1; i <= right; i++) {
		if (comp(&arr[i], &arr[left]) < 0)
			swap(arr + (++last), arr + i);
	}

	swap(arr + left, arr + last);
	myqsort(arr, left, last-1, comp);
	myqsort(arr, last+1, right, comp);
}

void swap(strsize *val1, strsize *val2)
{
	strsize temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

int cmp_from_back(const void *str1, const void *str2) 
{
	const strsize *s1 = (const strsize *)str1;
	const strsize *s2 = (const strsize *)str2;

	int pos1 = s1->len - 1;
	int pos2 = s2->len - 1; 

	while(isTrash(s1->strptr[pos1]) && pos1 >= 0) {
		pos1--;
	}

	while(isTrash(s2->strptr[pos2]) && pos2 >= 0) {
		pos2--;
	}
	
	while (pos1 >= 0 && pos2 >= 0) {
		if (tolower(s1->strptr[pos1--]) - tolower(s2->strptr[pos2--]) != 0) 	
			return (tolower(s1->strptr[pos1 + 1]) - tolower(s2->strptr[pos2 + 1]));
	}

	if (pos1 ==0 && pos2 == 0)
		return 0;

	return (pos1 == 0) ? -1 : 1;
}

int cmp_from_start(const void *str1, const void *str2)
{ 
	const strsize *s1 = (const strsize *)str1;
        const strsize *s2 = (const strsize *)str2;

	int it = 0;
	for (;tolower(s1->strptr[it]) - tolower(s2->strptr[it]) == 0; it++)
		if (s1->strptr[it] == '\n')
			return 0;

	return tolower(s1->strptr[it]) - tolower(s2->strptr[it]) ;
}

void sortNwrite(char *buff, strsize *str, int fd_out, int buffsize, int linecnt)
{
	myqsort(str, 0, linecnt - 1, (int (*)(const void *, const void *))(cmp_from_start));
        if (print_str(fd_out, str, linecnt) != NO_ERR)
                fprintf(stderr, "%s\n", errmsg(ERRNUM));


        qsort(str, linecnt, sizeof(strsize), (int (*)(const void *, const void *))(cmp_from_back));
        if (print_str(fd_out, str, linecnt) != NO_ERR)
                fprintf(stderr, "%s\n", errmsg(ERRNUM));


        if (write(fd_out, buff, buffsize) != buffsize) {
                ERRNUM = WRITE_ERR;
                fprintf(stderr, "%s\n", errmsg(ERRNUM));
        }
}
