#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

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

/*



*/

//求解矩阵是否为满秩矩阵，如果是返回1，如果不是返回-1
int full_rank_matrix(float* matrix, int row, int column)
{
	



	
}



/*
矩阵可逆的充分必要条件：AB=E；A为满秩矩阵（即r (A)=n）；
A的特征值全不为0；A的行列式|A|≠0，也可表述为A不是奇异矩阵（即行列式为0的矩阵）
*/
void reverse_matrix(float* matrix, int row, int column)
{
	;
}
//对矩阵进行相除
void division_matrix(float* matrix3, float* matrix1, float* matrix2, int row1, int column1, int column2)
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
//第一个参数是矩阵的地址，第二个参数是到第几行
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
//第三个参数是矩阵的行数，第四个矩阵是矩阵的列数
void upper_triangle_matrix(float* matrix1, int row, int column)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int move1 = 0;
	int move2 = 0;
	float move_in1 = 0;
	float move_in2 = 0;
	float magnification = 0;
	for (i = 0; i < column; i++)
	{
		for (j = i; j < row - 1; j++)
		{
			move1 = i + i * column;
			move2 = (j + 1) * column + i;
			move_in1 = *(matrix1 + move1);
			move_in2 = *(matrix1 + move2);
			while (move_in1 == 0)
			{//TODO
				for (k = i; k < row - 1; k++)
				{
					exchange_matrix_row(matrix1, k, k + 1, column);
					move_in1 = *(matrix1 + move1);
					move_in2 = *(matrix1 + move2);
				}
			}
			if (move_in1 == 0)
			{
				init_matrix_zero(matrix1, row, column);
			}
			else
			{
				magnification = move_in2 / move_in1;
				self_add_matrix_row(matrix1, magnification, i, k + 1, column);
			}
			
			// printf("%d %d\n", move1, move2);
			// printf("%f %f\n", move_in1, move_in2);
		}
	}
}

/*
求代数余子式求上三角行列式


*/
//代数余子式
float* algebra_remain_formula(float* matrix, int x, int y, int row)
{
	int comlumn = row;
	int move1 = 0;
	int move2 = 0;
	int up_line = 0;
	int i = 0;
	int j = 0;
	float magnification = 0;

	
	
}

//伴随矩阵

















































