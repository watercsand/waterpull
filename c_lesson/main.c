#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <malloc.h>
#include <string.h>




#include "circle.h"
#include "complex.h"
#include "matrix.h"


int main()
{
	int i = 0;
	float* m1 = NULL;
	float* m2 = NULL;
	float* m3 = NULL;
	for (i = 0; i < 1000000; i++)
	{
		
		m1 = init_matrix(m1, 3, 3);
		m2 = init_matrix(m2, 3, 3);
		float a1[] = { 1,2,3,4,5,6,7,8,0 };
		float a2[] = { 1,2,1,1,1,2,2,1,1 };
		assigned_matrix_arr(m1, a1, 3, 3);
		assigned_matrix_arr(m2, a2, 3, 3);
		//m3 = chaperonage_matrix(m2, 3);
		//print_complex_arr(m3, 3, 3);
		//print_matrix_arr(m2, 3, 3);
		m3 = division_matrix(m1, m2, 3, 3);
		//print_matrix_arr(m3, 3, 3);
		//printf("%f\n", a);
		free(m1);
		free(m2);
		//free(m3);
		m1 = NULL;
		m2 = NULL;
		m3 = NULL;
	}
	//float* m1 = 0;
	//m1 = realloc(NULL, 400000);
	//_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}