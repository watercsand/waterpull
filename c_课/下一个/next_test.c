#include <stdio.h>
#include "next.h"

void next_text()
{
	printf("\nin the next text _________________\n");
	char a[2] = {'a', 'b'};
	int* result = NULL;
	result = find_next(a, 2);
	print_char(result, 2);
}

void next_text2()
{
	printf("\nin the next text _______________2\n");
	char a = 'a';
	int* result = NULL;
	result = find_next(&a, 1);
	print_char(result, 1);
}

void next_text3()
{
	printf("\nin the next text _______________3\n");
	char a[] = "ababaaababaa";
	int* result = NULL;
	int len = sizeof(a) / sizeof(a[0]);
	result = find_next(a, len);
	print_char(result, len);
}