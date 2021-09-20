#include <stdio.h>
#include <algorithm.h>

int cmpstr(const void *str1, const void *str2);
int cmpstr_rvrs(const void *str1, const void* str2);
int read_str(char **mass);
void print_str(char **mass, size_t strcnt);
void swap(void *v[], int, int);
void sort_str((void ** str), (int (*)(void*, void*)) (cmpstr))

//const int MAXLINES = 5000;

int main() {
	char *str[MAXLINES] = {0};
	int nlines = 0;
	if ((nlines = read_str(str)) == EOF) {
		;//TODO err
	}
	const char **main = str;
	qsort((void **) str, 0, nlines - 1, (int (*)(void*, void*)) (cmpstr));
	print_str(str, nlines);

	qsort((void **) str, 0, nlines - 1, (int (*)(void*, void*)) (cmpstr_rvrs));
        print_str(str, nlines);

	print_str(main, nlines);

}
