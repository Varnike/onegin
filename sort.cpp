#include "sort.h"

void _myqsort(void *arr, size_t ssize, int left, int right, int (*comp)(const void *, const void *))
{
        assert(arr);

        int i = 0, last = 0;

        if (left >= right)
                return;
	
        swap(((char *)arr + (left * ssize)), ((char *)arr + ((left + right) / 2 * ssize)), ssize);    
	
        last = left;
        for (i = left + 1; i <= right; i++) {
                if ((*comp)((char *)arr + i * ssize, (char *)arr + left * ssize) < 0)
                        swap(((char *)arr + (++last * ssize)), ((char *)arr + (i * ssize)), ssize);
        } 

        swap((void *)((char *)arr + (left * ssize)), (void *)((char *)arr + last * ssize), ssize);

        _myqsort(arr, ssize, left, last-1, comp);
        _myqsort(arr, ssize, last+1, right, comp);
}

void myqsort(void *arr, int linecnt, size_t size, int (*comp)(const void *, const void *))
{
	_myqsort(arr, size, 0, linecnt - 1, comp);
}

void swap(void *dst, void *src, size_t len)
{
	int i = 0;
        for ( ; len >= sizeof(int64_t); i++) {
                int64_t cstr = *((int64_t *)src + i);
                *((int64_t *)src + i) = *((int64_t *)dst + i);
                *((int64_t *)dst + i) = cstr;
                len -= sizeof(int64_t);
        }

	int cnt = 0;
        while (len >= 1) {
                char cstr = *((char *)((int64_t *)src + i + cnt));
                *(((char *)((int64_t *)src + i) + cnt)) = *(((char *)((int64_t *)dst + i) + cnt));
                *(((char *)((int64_t *)dst + i) + cnt)) = cstr;
                len -= sizeof(char); 
		cnt++;
       }
}

int cmp_last_to_front(const void *str1, const void *str2) 
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

	if (pos1 == 0 && pos2 == 0)
		return 0;

	return (pos1 == 0) ? -1 : 1;
}

int cmp_front_to_last(const void *str1, const void *str2)
{ 
	const strsize *s1 = (const strsize *)str1;
        const strsize *s2 = (const strsize *)str2;

	int it = 0;
	for (; tolower(s1->strptr[it]) - tolower(s2->strptr[it]) == 0; it++)
		if (s1->strptr[it] == '\n')
			return 0;

	return tolower(s1->strptr[it]) - tolower(s2->strptr[it]) ;
}

void sortNwrite(textBuff *btext)
{
	// Sorting text lines from start
	myqsort(btext->str, btext->linecnt, sizeof(strsize), cmp_front_to_last);
        if (print_str(btext) != NO_ERR)
                fprintf(stderr, "%s\n", errmsg(ERRNUM));

	// Sorting text from back to start	
        qsort(btext->str, btext->linecnt, sizeof(strsize), cmp_last_to_front);
        if (print_str(btext) != NO_ERR)
                fprintf(stderr, "%s\n", errmsg(ERRNUM));

	// Printing original text 
        if (fwrite(btext->buff, sizeof(char), btext->buffsize, btext->file_out) != btext->buffsize) {
                ERRNUM = WRITE_ERR;
                fprintf(stderr, "%s\n", errmsg(ERRNUM));
        }
}
