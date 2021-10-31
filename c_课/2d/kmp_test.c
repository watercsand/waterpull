#include <stdio.h>
#include "kmp.h"

void kmp_test1()
{
	char s1[] = "ababcabcacbab";
	char s2[] = "abcac";
	int result = 0;
	result = index_kmp(s1, s2);
	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	printf("result = %d\n", result);
}