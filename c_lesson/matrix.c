#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

/*--------------------------------------------------------------------
Author: watercsand
git:	waterpull
email: 1337259688@qq.com
area:	China

this file only upload on the github
only for learning
if you see this file on any other website
!!!!!that all without permisson!!!!!
!!!!!   prohibit commercial    !!!!!
Any illegal act will be investigated
if you find any of this illegal activity
please send me an email (although I only check email occasionally)
thank you

in addition
I copied some of this stuff from the internet
especially the comments section
If you find out that I have infringed
Please contact with me
I'll delete it
--------------------------------------------------------------------*/

//将矩阵全部元素置为0
//第一个参数是矩阵的地址，第二个参数是矩阵的行数
//第三个参数是矩阵的列数
void init_matrix_zero(float* matrix, int row, int column)
{
	// printf("in the zero\n");
	// printf("%d %d\n", row, column);
	int i = 0;
	int j = 0;
	int move = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			move = i * column+ j;
			//printf("move = %d\n", move);
			*(matrix + move) = 0;
		}
	}
}

//开辟矩阵的内存空间，全部元素置为0，记得不用这个矩阵后要释放内存，并置为空指针
//开辟成功返回新的指针（记得接收），失败返回0
float* init_matrix(float* matrix, int row, int column)
{
	//printf("in the init\n");
	float* ptr1 = realloc(matrix, sizeof(float) * row * column);
	if (ptr1 == NULL)
	{
		printf("inti_matrix,内存开辟失败\n");
		return 0;
	}
	else
	{
		matrix = ptr1;
		init_matrix_zero(matrix, row, column);
		return matrix;
	}
}

//对矩阵的单个元素进行赋值，第一个是要赋值的元素的地址，第二个是要赋值的元素的值，
//第三个是第几行的元素，第四个是第几列的元素，
//第五个是这是一个几行的矩阵，第六个是这是一个几列的矩阵
void assigned_matrix_single(float* matrix, float number_assign, int x, int y, int row, int column)
{
	//printf("in the assinged\n");
	int move = x * column + y;
	//printf("move = %d\n", move);
	//printf("number assign = %f\n", number_assign);
	*(matrix + move) = number_assign;

}

//对矩阵进行单位化（单位矩阵）
//第一个参数是矩阵的地址
//第二个参数是行（列）
void matrix_unit(float* matrix, int row)
{
	int i = 0;
	float a = 1.0f;
	for (i = 0; i < row; i++)
	{
		assigned_matrix_single(matrix, a, i, i, row, row);
	}
}

//对矩阵进行创建并进行单位化
//第一个参数是矩阵的地址
//第二个参数是单位矩阵的行（列）数，记得接收返回的地址
//开辟成功返回地址，失败返回0
float* init_matrix_unit(float* matrix, int row)
{
	float* ptr = NULL;
	ptr = init_matrix(matrix, row, row);
	if (ptr == 0)
	{
		return 0;
	}
	else
	{
		matrix = ptr;
		matrix_unit(matrix, row);
		return matrix;
	}
	}

//对矩阵的全部元素全部进行赋值
//第一个元素是要赋值的元素的地址，第二个元素是要赋值元素的数组的地址
// 第三个是行， 第四个是列
void assigned_matrix_arr(float* matrix, float* assign_arr, int row, int column)
{
	int i = 0;
	int j = 0;
	int move = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			move = 0;
			move = i * column + j;
			*(matrix + move) = *(assign_arr + move);
		}
	}
}

//打印单个矩阵元素的值，传入是第几行，第几列的第几个元素
// 这个数组有几行几列
//这个函数开始计数为0，
// 要访问3*3matrix第二行，第三列元素，
// print_matrix_single(ptr, 1, 2, 3, 3)
void print_matrix_single(float* matrix, int x, int y, int row, int column)
{
	//printf("in single\n");
	int move = x * column + y;
	printf("%20.8f\n", *(matrix + move));
}

//打印所有矩阵元素的值
//第一个参数是矩阵的地址
// 第二个参数是这个矩阵有多少行，第三个参数是这个矩阵有多少列
void print_matrix_arr(float* matrix, int row, int column)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			int move = 0;
			move = i * column + j;
			printf("%20.8f ", *(matrix + move));
		}
		printf("\n");
	}
	printf("\n");
}

//对两个矩阵进行相加
//第一个是结果保存的矩阵，第二个是加数矩阵，第三个是被加数矩阵，第四个是行，第五个是列
//前三个参数都要传入地址
void add_matrix(float* matrix3, float* matrix1, float* matrix2, int row, int column)
{
	int i = 0;
	int j = 0;
	int move = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			move = i * row + j;
			// printf("%d ", move);
			// printf("%p\n", matrix3 + move);
			// printf("%f %f ", *(matrix1 + move), *(matrix2 + move));
			*(matrix3 + move) = *(matrix1 + move) + *(matrix2 + move);
		}
	}
}

//对两个矩阵进行相减
//第一个是结果保存的矩阵，第二个是减数矩阵，第三个是被减数矩阵，第四个是行，第五个是列
//前三个参数都要传入地址
void subtraction_matrix(float* matrix3, float* matrix1, float* matrix2, int row, int column)
{
	int i = 0;
	int j = 0;
	int move = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			move = i * row + j;
			*(matrix3 + move) = *(matrix1 + move) - *(matrix2 + move);
		}
	}
}

// 对两个矩阵进行相乘
// 第一个参数是保存结果的矩阵，第二个参数是乘数矩阵，第三个参数是被乘数矩阵
// 第四个参数是乘数矩阵的行，第五个参数是乘数矩阵的列，
// 因为乘数矩阵的列必须等于被乘数矩阵的行，所以被乘数的行就等于乘数矩阵的列
// 第六个参数是被乘数矩阵的列
void multiply_matrix(float* matrix3, float* matrix1, float* matrix2, int row1, int column1, int column2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int m = row1 * column2;
	// printf("%d\n", k);
	int move1 = 0;//0 --> column1
	int move2 = 0;//0 --> column2
	int move3 = 0;
	float each_sum = 0;
	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < column2; j++)
		{
			each_sum = 0;
			move1 = i * column1;
			move2 = j * column2;
			move3 = i * column2 + j;
			int move_in1 = move1;
			int move_in2 = move2;
			
			for (k = 0; k < column1; k++)
			{
				move_in1 = move1 + k;
				move_in2 = column2 * k + j;
				// printf("move_in1 = %d  move_in2 = %d ", move_in1, move_in2);
				// printf("%f %f\n", *(matrix1 + move_in2), *(matrix2 + move_in2));
				each_sum += ((*(matrix1 + move_in1)) * (*(matrix2 + move_in2)));
			}
			// printf("move3 = %d\n", move3);
			// printf("each_sum = %f \n \n",each_sum);
			
			*(matrix3 + move3) = each_sum;
		}
		
	}
}

//对单个矩阵进行倍数相乘
//第一个参数是矩阵的地址，第二个参数是要乘的位数
//第三个参数是矩阵的行数，第四个参数是矩阵的列数
void multiply_matrix_number(float* matrix, float number, int row, int column)
{
	int i = 0;
	int j = 0;
	int move = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			move = i * column + j;
			*(matrix + move) *= number;
		}
	}
}

//对矩阵的某一行进行倍数相乘
//第一个参数是矩阵的地址，第二个参数是要乘的倍率
//第三个参数是哪一行要被乘
//第四个参数是这个矩阵有多少行，第五个参数是这个矩阵有多少列
void multiply_matrix_row(float* matrix, float number, int row_assign, int row, int column)
{
	int i = 0;
	int move = 0;
	for (i = 0; i < column; i++)
	{
		move = row_assign * column + i;
		*(matrix + move) *= number;
	}
}

//矩阵初等行变换，将某一行元素的若干倍相加到另一行处
//第一个参数矩阵的地址，第二个参数要乘的倍率
//第三个参数是哪一行的几倍，第四个参数要被改变的行
//第五个参数矩阵有多少列
void self_add_matrix_row(float* matrix, float number, int row_assign1, int row_assign2, int column)
{
	int i = 0;
	int move1 = 0;
	int move2 = 0;
	float num_1 = 0;
	for (i = 0; i < column; i++)
	{
		move1 = row_assign1 * column + i;
		move2 = row_assign2 * column + i;
		num_1 = *(matrix + move1);
		num_1 *= number;
		*(matrix + move2) += num_1;
	}
}

//交换两行元素的值
//第一个参数是矩阵的地址，第二和三个参数是要交换的行的行数
//第四个参数是矩阵的列数
void exchange_matrix_row(float* matrix, int row_assign1, int row_assign2, int column)
{
	int i = 0;
	int j = 0;
	int move1 = 0;
	int move2 = 0;
	float tmp = 0;
	for (i = 0; i < column; i++)
	{
		move1 = row_assign1 * column + i;
		move2 = row_assign2 * column + i;
		tmp = *(matrix + move1);
		*(matrix + move1) = *(matrix + move2);
		*(matrix + move2) = tmp;
	}
}

//求解矩阵的秩
//
int rank_matrix(float* matrix, int row, int column)
{
	int i = 0;
	int j = 0;
	int up_line = 0;
	float magnification = 0;
	int move = 0;
	float up_line_num = 0;
	float move_num = 0;
	for (i = 0; i < column; i++)
	{
		up_line = i;
		for (j = i + 1; j < row; j++)
		{
			
			move = i + j * column;
			up_line_num = *(matrix + up_line + i*column);
			move_num = *(matrix + move);
			if (up_line_num == 0)
			{
				continue;
			}
			magnification = move_num / up_line_num;
			print_matrix_arr(matrix, row, column);
			// printf("%d %d %f\n", i, j, magnification);
			magnification = -magnification;
			self_add_matrix_row(matrix, magnification, i, j, column);
			//printf("%f %f\n", *(matrix + move), magnification);

		}
		//printf("\n");
		
	}
	return column;
}

//求解矩阵是否为满秩矩阵，如果是返回1，如果不是返回-1
int full_rank_matrix(float* matrix, int row, int column)
{
	return 0;
}

/*
矩阵可逆的充分必要条件：AB=E；A为满秩矩阵（即r (A)=n）；
A的特征值全不为0；A的行列式|A|≠0，也可表述为A不是奇异矩阵（即行列式为0的矩阵）
*/
void reverse_matrix(float* matrix, int row, int column)
{
	;
}

//判断矩阵(上三角)的前几行下部分是否为0，是返回0，不是返回1
/*如 | 4 4 4 4 |
	 | 0 4 4 4 |
	 | 0 0 4 4 |
	 | 0 0 4 4 |
	 前2行就满足条件
	 前3行就不满足条件
*/
//使用的前提是矩阵为方阵
//第一个参数是矩阵的地址，第二个参数是到第几行
//第三个参数是矩阵有多少行
int is_zero_matrix(float* matrix, int x, int row)
{
	int column = row;
	int i = 0;
	int j = 0;
	int move = 0;
	
	for (i = 1; i < row; i++)
	{		
		for (j = 0; j < i; j++)
		{
			if (j > x)
			{
				break;
			}
			move = i * column + j;
			// printf("%d ", move);
			// printf("%f \n", *(matrix + move));
			if (*(matrix + move) != 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

//转为上三角行列式
//第一个参数是保存结果的矩阵，第二个参数是输入的矩阵
//第三个参数是矩阵的行数，第四个参数是矩阵的列数
int upper_triangle_matrix(float* matrix1, int row)
{
	int i = 0;
	int j = 0;
	int column = row;
	int move_up_line = 0;
	int move_each_line = 0;
	float move_up = 0;
	float each_line = 0;
	int k = 0;
	int flag = 0;
	float mag = 0;//倍率
	for (i = 0; i < column - 1; i++)
	{
		for (j = i + 1; j < row; j++)
		{
			move_up_line = i * column + i;
			move_each_line = j * column + i;
			move_up = *(matrix1 + move_up_line);
			each_line = *(matrix1 + move_each_line);
			//printf("move_up=%f each_line=%f\n", move_up, each_line);
			//printf("up_line=%d each_line=%d\n", move_up_line, move_each_line);
			flag = 0;
			while (move_up == 0)
			{
				for (k = 0; k < row - i - 1; k++)
				{
					//printf("k=%d\n", k);
					exchange_matrix_row(matrix1, j + k - 1, j + k, column);
				}
				flag++;
				//printf("%d\n", flag);
				if (flag > row - i - 1)
				{
					init_matrix_zero(matrix1, row, column);
					return -1;
				}
				move_up = *(matrix1 + move_up_line);
				each_line = *(matrix1 + move_each_line);
			}
			mag = each_line / move_up;
			mag = -mag;
			self_add_matrix_row(matrix1, mag, i, j, column);
		}
	}
	return 1;
}


//对上三角行列式求值
//第一个参数是上三角行列式的地址
//第二个参数是上三角行列式的行（列）
float sum_upper_triangle_matrix(float* matrix, int row)
{
	int column = row;
	int i = 0;
	int move = 0;
	float result = 1;
	int flag = 0;
	flag = upper_triangle_matrix(matrix, row);
	if (flag < 0)
	{
		printf("upper_triangle_matrix fail\n");
		return (float)0xffffffff;
	}
	//print_matrix_arr(matrix, row, column);
	for (i = 0; i < row; i++)
	{
		move = i * column + i;
		//printf("%d\n", move);
		result *= *(matrix + move);
	}
	return result;
}

/*
求代数余子式求上三角行列式


*/
//代数余子式
// 前担是为方阵
//第一个参数是矩阵的地址，第二个参数是行（索引从0开始），第三个参数是列（索引从0开始）
//第四个参数是矩阵一共有多少行（列）
float algebra_remain_formula(const float* matrix, int x, int y, int row)
{
	int i = 0;
	int j = 0;
	int column = row;
	int move1 = 0;
	int move2 = 0;
	float* assign = NULL;
	float* assign2 = NULL;
	float* matrix_copy = NULL;
	float* matrix_copy2 = NULL;
	float result = 0;
	assign2 = realloc(assign, sizeof(float) * (row - 1) * (column - 1));
	if (assign2 == NULL)
	{
		printf("assigns fail\n");
		return (float)0xffffffff;
	}
	else
	{
		assign = assign2;
		assign2 = NULL;
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if ((i != x) && (j != y))
			{
				move2 = i * column + j;
				*(assign + move1) = *(matrix + move2);
				move1++;
			}
		}
	}
	matrix_copy2 = init_matrix(matrix_copy, row - 1, column - 1);
	if (matrix_copy2 == NULL)
	{
		free(assign);
		assign = NULL;
	}
	else
	{
		matrix_copy = matrix_copy2;
		matrix_copy2 = NULL;
		assigned_matrix_arr(matrix_copy, assign, row - 1, column - 1);
	}
	//upper_triangle_matrix(matrix_copy, row - 1);
	result = sum_upper_triangle_matrix(matrix_copy, row - 1);
	//printf("%f\n", result);
	//printf("%f\n", result);
	free(matrix_copy);
	matrix_copy = NULL;
	free(assign);
	assign = NULL;
	//printf("eenndd\n");
	return result;
}

//返回余子式
//第一个参数是是矩阵的地址，第二个参数是索引行（从0开始）
//第三个参数是索引列（从0开始）
float remain_formula(float* matrix, int x, int y, int row)
{
	int flag = 1;
	float result = 0;
	if ((x + y) % 2 == 1)
	{
		flag = -flag;
	}

	result = algebra_remain_formula(matrix, x, y, row);
	//printf("%f\n", result);
	if (result == (int)0xffffff)
	{
		printf("result fail\n");
		return (float)0xffffffff;
	}
	result = flag * result;
	//printf("end\n");
	return result;
}

//打印浮点型数组的值
//第一个参数是数组的地址，第二个参数是数组的长度
void print_float(float* arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%f\n", *(arr + i));
	}
}

//伴随矩阵
//第一个参数是矩阵的地址，第二个参数是矩阵的行（列）
//返回一个结果的矩阵，记得接收，用完释放，小心内存泄漏
float* chaperonage_matrix(float* matrix, int row)
{
	int column = row;
	int i = 0;
	int j = 0;
	float* matrix_copy = NULL;
	float* matrix_copy2 = NULL;
	//float* assign_matrix_copy = NULL;
	//float* assign_matrix_copy2 = NULL;
	float each_result = 0;
	float rank = 0;
	float* matrix_rank = NULL;
	float* matrix_rank2 = NULL;
	float* assign_rank = NULL;
	float* assign_rank2 = NULL;
	//float* assign_rank3 = NULL;
	//float* assign_rank4 = NULL;
	float* matrix_in = NULL;
	float* matrix_in2 = NULL;
	int assign_rank_move = 0;
	matrix_rank2 = init_matrix(matrix_rank, row, column);
	//print_matrix_arr(matrix_rank2, row, column);
	if (matrix_rank2 == NULL)
	{
		return NULL;
	}
	else 
	{
		matrix_rank = matrix_rank2;
		matrix_rank2 = NULL;
		//printf("matrix_rank\n");
		assign_rank2 = realloc(assign_rank, sizeof(float) * row * column);
		//assign_rank4 = realloc(assign_rank, sizeof(float) * row * column);
		if (assign_rank2 == NULL)
		{
			free(matrix_rank);
			matrix_rank = NULL;
			return NULL;
		}
		else
		{
			assign_rank = assign_rank2;
			assign_rank2 = NULL;
		}
		//if (assign_rank4 == NULL)
		//{
		//	free(matrix_rank);
		//	matrix_rank = NULL;
		//	return NULL;
		//}
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				assign_rank_move = i * column + j;
				*(assign_rank + assign_rank_move) = *(matrix + assign_rank_move);
			}
		}
		assigned_matrix_arr(matrix_rank, assign_rank, row, column);
		//free(assign_rank);
		//printf("assign_rank\n");
		//print_matrix_arr(matrix_rank, row, column);
		upper_triangle_matrix(matrix_rank, row);
		//print_float(assign_rank, 25);
		//print_matrix_arr(matrix_rank, row, column);
		rank = sum_upper_triangle_matrix(matrix_rank, row);
		//printf("%f\n", rank);
		if (rank == (float)0xffffffff)
		{
			printf("该矩阵没有伴随矩阵\n");
			free(matrix_rank);
			matrix_rank = NULL;
			free(assign_rank);
			return NULL;
		}
		free(matrix_rank);
		matrix_rank = NULL;
		matrix_copy2 = init_matrix(matrix_copy, row, column);
		if (matrix_copy2 == NULL)
		{
			return NULL;
		}
		else
		{
			matrix_copy = matrix_copy2;
			matrix_copy2 = NULL;
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < column; j++)
				{
					matrix_in2 = init_matrix(matrix_in, row, column);
					if (matrix_in2 == NULL)
					{
						free(assign_rank);
						assign_rank = NULL;
						return NULL;
					}
					matrix_in = matrix_in2;
					matrix_in2 = NULL;
					//printf("%f\n", *(assign_rank + i));
					//printf("%p\n", assign_rank);
					assigned_matrix_arr(matrix_in, assign_rank, row, column);
					//print_matrix_arr(matrix_in, row, column);
					each_result = remain_formula(matrix_in,i,j,row);
					assigned_matrix_single(matrix_copy, each_result, j, i, row, column);
					//printf("%f\n", each_result);
					free(matrix_in);
					matrix_in = NULL;
				}
				//printf("\n");
			}
			//assigned_matrix_arr(matrix_copy, assign_rank, row, column);
		}
	}
	free(assign_rank);
	assign_rank = NULL;
	
	return matrix_copy;
}

//对矩阵进行相除
//第一个参数是被除数矩阵的地址，第二个参数是矩阵除数的地址
//第三个参数是被除数矩阵的行，
//第四个参数是被除数矩阵的列（除数矩阵的行和列与被除数矩阵的列相同）
//返回一个结果的矩阵，记得接收，用完释放，小心内存泄漏
float* division_matrix(float* matrix1, float* matrix2, int row1, int column1)
{
	float* inverse = NULL;
	float* inverse2 = NULL;
	int move_assign = 0;
	int row2 = column1;
	int column2 = column1;
	float* assign = NULL;
	float* assign2 = NULL;
	float* result1 = NULL;
	float* result2 = NULL;
	float* result3 = NULL;
	float* result4 = NULL;
	float proportion = 0;
	int i = 0;
	int j = 0;
	inverse2 = init_matrix(inverse, row2, column2);
	if (inverse2 == NULL)
	{
		return NULL;
	}
	else
	{
		inverse = inverse2;
		inverse2 = NULL;
	}
	assign2 = realloc(assign, sizeof(float) * row2 * column2);
	if (assign2 == NULL)
	{
		free(inverse);
		inverse = NULL;
		return NULL;
	}
	else
	{
		assign = assign2;
		assign2 = NULL;
	}
	for (i = 0; i < row2; i++)
	{
		for (j = 0; j < column2; j++)
		{
			move_assign = i * column2 + j;
			*(assign + move_assign) = *(matrix2 + move_assign);
		}
	}
	assigned_matrix_arr(inverse, assign, row2, column2);
	//free()
	proportion = sum_upper_triangle_matrix(inverse, row2);
	assigned_matrix_arr(inverse, assign, row2, column2);
	result2 = chaperonage_matrix(inverse, row2);
	assigned_matrix_arr(inverse, assign, row2, column2);
	if (result2 == NULL)
	{
		free(assign);
		assign = NULL;
		return NULL;
	}
	else
	{
		result1 = result2;
		result2 = NULL;
	}
	multiply_matrix_number(result1, 1 / proportion, row2, column2);
	//init_matrix_zero(inverse, row2, column2);
	result4 = init_matrix(result3, row1, column2);
	if (result4 == NULL)
	{
		printf("结果矩阵开辟失败\n");
		free(assign);
		assign = NULL;
		free(inverse);
		inverse = NULL;
		free(result1);
		result1 = NULL;
		return NULL;
	}
	else
	{
		result3 = result4;
		result4 = NULL;
	}
	multiply_matrix(result3, matrix1, result1, row1, column1, row2);
	free(assign);
	assign = NULL;
	free(inverse);
	inverse = NULL;
	free(result1);
	result1 = NULL;
	return result3;
}














































