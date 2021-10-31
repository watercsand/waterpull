#include <stdio.h>
#include <malloc.h>
#include "matrix.h"

struct matrix* init(int h, int l)
{
	int* front = NULL;
	int* end = NULL;
	int each_size = sizeof(int) * l;
	int i = 0;
	
	for (i = 0; i < h; i++)
	{
		front = malloc(each_size);
		end = front + l;
	}
	return NULL;
}

void free_2d(int* start, int h, int l)
{
	;
}
