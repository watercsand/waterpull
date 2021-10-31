#include <stdio.h>
#include "virus.h"

void compare_test1()
{
	char p[] = "cdcdcdec";
	char m[] = "cde";
	int result = 0;
	result = compare(p, m);
	// printf("result = %d\n", result);
	printf("patient_virus = %s\n", p);
	printf("virus_model = %s\n", m);
	if (result == 1)
	{
		printf("yes\n");
	}
	else if (result == -1)
	{
		printf("no\n");
	}
	else
	{
		printf("system os wrong\n");
	}
}
