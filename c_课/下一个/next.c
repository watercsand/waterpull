#include <stdio.h>
#include <string.h>
#include <malloc.h>

int* find_next(char* begin, int len)
{
	void print_char(int* begin, int len);
	int i = 0;
	int* re = NULL;
	int* re2 = NULL;
	int pt = 1;
	int front = 0;
	int link;
	char b;
	int link2 = 0;
	if (len > 2)
	{
		re2 = realloc(re, sizeof(int) * len);
		if (re2 != NULL)
		{
			re = re2;
			re2 = NULL;
		}
		else
		{
			return NULL;
		}
		*(re) = 0;
		*(re + 1) = 1;
		for (i = 2; i < len; i++)
		{
			
		}
	}
	else if (len == 2)
	{
		re2 = realloc(re, sizeof(int) * 2);
		if (re2 != NULL)
		{
			re = re2;
			re2 = NULL;
		}
		else
		{
			return NULL;
		}
		*(re) = 0;
		*(re + 1) = 1;
		// printf("%d %d\n", *(re), *(re + 1));
	}
	else
	{
		re2 = realloc(re, sizeof(int));
		if (re2 != NULL)
		{
			re = re2;
			re2 = NULL;
		}
		else
		{
			return NULL;
		}
		*(re) = 0;
	}
	return re;


}

void print_char(int* begin, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", *(begin + i));
		if ((i % 10 == 0) && (i != 0))
		{
			printf("\n");
		}
	}
	if (i % 10 != 0)
	{
		printf("\n");
	}
}