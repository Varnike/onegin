#include "sort.h"

void myqsort(void *arr, size_t ssize, int left, int right, int (*comp)(const void *, const void *))
{
        assert(arr);

        int i = 0, last = 0;

        if (left >= right)
                return;
	
        swap(((char *)arr + (left * ssize)), ((char *)arr + ((left + right) / 2 * ssize)), ssize);    
        last = left;
        for (i = left + 1; i <= right; i++) {
                if (comp((char *)arr + i * ssize, (char *)arr + left * ssize) < 0)
                        swap(((char *)arr + (++last * ssize)), (void *)((char *)arr + i * ssize), ssize);
        } 
        swap((void *)((char *)arr + (left * ssize)), (void *)((char *)arr + right * ssize), ssize);
        myqsort(arr, ssize, left, last-1, comp);
        myqsort(arr, ssize, last+1, right, comp);
}

void swap(void *dst, void *src, size_t len)
{


        for (int i = 0; len >= 8; i++) {
                int64_t cstr = *((int64_t *)src + i);
                *((int64_t *)src + i) = *((int64_t *)dst + i);
                *((int64_t *)dst + i) = cstr;
                len -= 8;
        }

        if (len >= 4) {
                int32_t cstr = *((int32_t *)src);
                *((int32_t *)src) = *((int32_t *)dst);
                *((int32_t *)dst) = cstr;
                len -= 4;
        }

        if (len >= 2) {
                int16_t cstr = *((int16_t *)src);
                *((int16_t *)src) = *((int16_t *)dst);
                *((int16_t *)dst) = cstr;
                len -= 2;
        }

        if (len >= 1) {
                char cstr = *((char *)src);
                *((char *)src) = *((char *)dst);
                *((char *)dst) = cstr;
        }
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

void sortNwrite(char *buff, strsize *str, FILE *file_out, int buffsize, int linecnt)
{
	myqsort((void *)str, sizeof(strsize), 0, linecnt - 1, (int (*)(const void *, const void *))(cmp_from_start));
        if (print_str(file_out, str, linecnt) != NO_ERR)
                fprintf(stderr, "%s\n", errmsg(ERRNUM));


        qsort(str, linecnt, sizeof(strsize), (int (*)(const void *, const void *))(cmp_from_back));
        if (print_str(file_out, str, linecnt) != NO_ERR)
                fprintf(stderr, "%s\n", errmsg(ERRNUM));


        if (fwrite(buff, sizeof(char), buffsize, file_out) != buffsize) {
                ERRNUM = WRITE_ERR;
                fprintf(stderr, "%s\n", errmsg(ERRNUM));
        }
}
