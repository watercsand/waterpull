#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#include <string.h>






#include "circle.h"
#include "complex.h"
#include "matrix.h"


int main()
{
	float* m1 = NULL;
	float* m2 = NULL;
	float* m3 = NULL;

	m1 = init_matrix(m1, 3, 3);
	m2 = init_matrix(m2, 3, 3);
	m3 = init_matrix(m3, 3, 3);
	// printf("%p\n", m3);
	float fz[] = { 3, -1, 2, 1, 5, 0, 2, 4, 5 };
	float fz2[] = { 7, 5, -2, 5, 1, 9, 4, 2, 1 };
	assigned_matrix_arr(m1, fz, 3, 3);
	//print_matrix_arr(m1, 3, 3);
	assigned_matrix_single(m1, 7, 1, 2, 3, 3);
	print_matrix_arr(m1, 3, 3);
	//print_matrix_single(m1, 0, 2, 3, 3);
	
	assigned_matrix_arr(m2, fz2, 3, 3);
	print_matrix_arr(m2, 3, 3);
	add_matrix(m3, m1, m2, 3, 3);
	print_matrix_arr(m3, 3, 3);
	subtraction_matrix(m3, m1, m2, 3, 3);
	print_matrix_arr(m3, 3, 3);
	free(m1);
	free(m2);
	free(m3);
	m1 = NULL;
	m2 = NULL;
	m3 = NULL;
	printf("***************************************************\n");
	m1 = init_matrix(m1, 4, 3);
	m2 = init_matrix(m2, 3, 2);
	m3 = init_matrix(m3, 4, 2);
	float a1[] = { 5,2,4,3,8,2,6,0,4,0,1,6 };
	float a2[] = { 2,4,1,3,3,2 };
	assigned_matrix_arr(m1, a1, 4, 3);
	assigned_matrix_arr(m2, a2, 3, 2);
	print_matrix_arr(m1, 4, 3);
	print_matrix_arr(m2, 3, 2);
	multiply_matrix(m3, m1, m2, 4, 3, 2);

	print_matrix_arr(m3, 4, 2);
	init_matrix_zero(m3, 4, 2);
	print_matrix_arr(m3, 4, 2);
	free(m1);
	free(m2);
	free(m3);
	m1 = NULL;
	m2 = NULL;
	m3 = NULL;
	printf("********************************************\n");
	m1 = init_matrix_unit(m1, 4);
	m2 = init_matrix(m2, 5, 3);
	float b1[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	assigned_matrix_arr(m2, b1, 5, 3);
	print_matrix_arr(m1, 4, 4);
	print_matrix_arr(m2, 5, 3);
	multiply_matrix_number(m2, 2.0f, 5, 3);
	print_matrix_arr(m2, 5, 3);
	multiply_matrix_number(m2, 0.5f, 5, 3);
	print_matrix_arr(m2, 5, 3);
	// multiply_matrix_row(m2, 3, 3, 5, 3);
	// print_matrix_arr(m2, 5, 3);
	// self_add_matrix_row(m2, -4, 0, 1, 5, 3);
	// print_matrix_arr(m2, 5, 3);
	int a3 = rank_matrix(m2, 5, 3);
	printf("rank a3 = %d\n", a3);
	free(m1);
	free(m2);
	m1 = NULL;
	m2 = NULL;
	float a4[] = { 1, 1, -2, 1, 4,
					2, -1, -1, 1, 2,
					2, -3, 1, -1, 2,
					3, 6, -9, 7, 9 };
	m1 = init_matrix(m1, 4, 5);
	assigned_matrix_arr(m1, a4, 4, 5);
	print_matrix_arr(m1, 4, 5);
	rank_matrix(m1, 4, 5);
	print_matrix_arr(m1, 4, 5);
	m2 = init_matrix(m2, 4, 4);
	float a5[] = { 0, 1, 7, -1,-1,2,4,3,2,1,0,-1,3,2,2,1 };
	assigned_matrix_arr(m2, a5, 4, 4);
	algebra_remain_formula(m1, 1, 1, 4);
	print_matrix_arr(m2, 4, 4);
	exchange_matrix_row(m2, 0, 1, 4);
	print_matrix_arr(m2, 4, 4);

	free(m1);
	free(m2);
	m1 = NULL;
	m2 = NULL;
	m3 = init_matrix(m3, 4, 4);
	float a6[] = { 1,2,3,4,0,5,6,7,0,0,8,9,0,0,10,11 };
	assigned_matrix_arr(m3, a6, 4, 4);
	printf("*************************************************************\n");
	print_matrix_arr(m3, 4, 4);
	int a7 = is_zero_matrix(m3, 2, 4);
	printf("%d\n*********\n", a7);

	a7 = is_zero_matrix(m3, 1, 4);
	printf("%d\n", a7);
	free(m3);
	m3 = NULL;
	printf("***********************************************************\n");
	m1 = init_matrix(m1, 4, 4);
	m2 = init_matrix(m2, 4, 4);
	float a8[] = { 1,3,-1,2,1,-5,3,-4,0,2,1,-1,-5,1,3,-3 };
	print_matrix_arr(m1, 4, 4);
	print_matrix_arr(m2, 4, 4);
	assigned_matrix_arr(m1, a8, 4, 4);
	print_matrix_arr(m1, 4, 4);
	print_matrix_arr(m2, 4, 4);
	upper_triangle_matrix( m1, 4, 4);
	print_matrix_arr(m1, 4, 4);
	free(m1);
	free(m2);
	m1 = NULL;
	m2 = NULL;
	system("pause");
	return 0;
}