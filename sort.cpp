#include "sort.h"
#if 0
void myqsort(void *v, int left, int right, int (*comp)(void *, void *))
{
	assert(v);

	int i = 0, last = 0;

	if (left >= right) 
		return; 
	
	swap(v, left, (left+ right)/2);
	
	last = left;

	for (i = left+1; i <= right; i++)
		if (comp(v[i], v[left]) < 0)
			swap(v, ++last, i);

	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}

void swap(char *v, int i, void j)
{
	const void *temp = NULL;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
#endif
int cmp_reverse(const void *str1, const void *str2) 
{
	const strsize *s1 = (const strsize *)str1;
	const strsize *s2 = (const strsize *)str2;

	//printf("Compairing two strings: \"%s\" and \"%s\".\n", s1->strptr, s2->strptr);

	int pos1 = s1->len - 1;
	int pos2 = s2->len - 1;

	//printf("%d, %d\n", pos1, pos2); 

	while(!isalpha(s1->strptr[pos1]) && !isdigit(s1->strptr[pos1]) && pos1 >= 0) {
		pos1--;
	}

	while(!isalpha(s2->strptr[pos2]) && !isdigit(s2->strptr[pos2]) && pos2 >= 0) {
		pos2--;
	}
	
	while (pos1 >= 0 && pos2 >= 0) {
		if (s1->strptr[pos1--] - s2->strptr[pos2--] != 0) 	
			return (s1->strptr[pos1 + 1] - s2->strptr[pos2 + 1]);
	}

	if (pos1 + pos2 == 0)
		return 0;

	return (pos1 == 0) ? -1 : 1;
}

int strcomp(const void *str1, const void *str2)
{ 
#if 0
	//printf("Compairing two strings: %s and %s.\n", s1->ptr, s2->ptr);
	const strsize *s1 = (const strsize *)str1;
        const strsize *s2 = (const strsize *)str2;

	int it = 0;
	for (;s1->strptr[it] - s2->strptr[it++] == 0; it++)
		if (s1->strptr[it] == '\n')
			return 0;
	return s1->strptr[it] - s2->strptr[it];
#endif
	//if (str1[it] == '\n')
	return strcmp(((const strsize *)str1)->strptr, ((const strsize *)str2)->strptr);
}
