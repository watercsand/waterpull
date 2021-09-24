#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

//������ȫ��Ԫ����Ϊ0
//��һ�������Ǿ���ĵ�ַ���ڶ��������Ǿ��������
//�����������Ǿ��������
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

//���پ�����ڴ�ռ䣬ȫ��Ԫ����Ϊ0���ǵò�����������Ҫ�ͷ��ڴ棬����Ϊ��ָ��
//���ٳɹ������µ�ָ�루�ǵý��գ���ʧ�ܷ���0
float* init_matrix(float* matrix, int row, int column)
{
	//printf("in the init\n");
	float* ptr1 = realloc(matrix, sizeof(float) * row * column);
	if (ptr1 == NULL)
	{
		printf("inti_matrix,�ڴ濪��ʧ��\n");
		return 0;
	}
	else
	{
		matrix = ptr1;
		init_matrix_zero(matrix, row, column);
		return matrix;
	}
}

//�Ծ���ĵ���Ԫ�ؽ��и�ֵ����һ����Ҫ��ֵ��Ԫ�صĵ�ַ���ڶ�����Ҫ��ֵ��Ԫ�ص�ֵ��
//�������ǵڼ��е�Ԫ�أ����ĸ��ǵڼ��е�Ԫ�أ�
//�����������һ�����еľ��󣬵�����������һ�����еľ���
void assigned_matrix_single(float* matrix, float number_assign, int x, int y, int row, int column)
{
	//printf("in the assinged\n");
	int move = x * column + y;
	//printf("move = %d\n", move);
	//printf("number assign = %f\n", number_assign);
	*(matrix + move) = number_assign;

}

//�Ծ�����е�λ������λ����
//��һ�������Ǿ���ĵ�ַ
//�ڶ����������У��У�
void matrix_unit(float* matrix, int row)
{
	int i = 0;
	float a = 1.0f;
	for (i = 0; i < row; i++)
	{
		assigned_matrix_single(matrix, a, i, i, row, row);
	}
}

//�Ծ�����д��������е�λ��
//��һ�������Ǿ���ĵ�ַ
//�ڶ��������ǵ�λ������У��У������ǵý��շ��صĵ�ַ
//���ٳɹ����ص�ַ��ʧ�ܷ���0
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

//�Ծ����ȫ��Ԫ��ȫ�����и�ֵ
//��һ��Ԫ����Ҫ��ֵ��Ԫ�صĵ�ַ���ڶ���Ԫ����Ҫ��ֵԪ�ص�����ĵ�ַ
// ���������У� ���ĸ�����
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

//��ӡ��������Ԫ�ص�ֵ�������ǵڼ��У��ڼ��еĵڼ���Ԫ��
// ��������м��м���
//���������ʼ����Ϊ0��
// Ҫ����3*3matrix�ڶ��У�������Ԫ�أ�
// print_matrix_single(ptr, 1, 2, 3, 3)
void print_matrix_single(float* matrix, int x, int y, int row, int column)
{
	//printf("in single\n");
	int move = x * column + y;
	printf("%20.8f\n", *(matrix + move));
}

//��ӡ���о���Ԫ�ص�ֵ
//��һ�������Ǿ���ĵ�ַ
// �ڶ�����������������ж����У���������������������ж�����
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

//����������������
//��һ���ǽ������ľ��󣬵ڶ����Ǽ������󣬵������Ǳ��������󣬵��ĸ����У����������
//ǰ����������Ҫ�����ַ
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

//����������������
//��һ���ǽ������ľ��󣬵ڶ����Ǽ������󣬵������Ǳ��������󣬵��ĸ����У����������
//ǰ����������Ҫ�����ַ
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

// ����������������
// ��һ�������Ǳ������ľ��󣬵ڶ��������ǳ������󣬵����������Ǳ���������
// ���ĸ������ǳ���������У�����������ǳ���������У�
// ��Ϊ����������б�����ڱ�����������У����Ա��������о͵��ڳ����������
// �����������Ǳ������������
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

//�Ե���������б������
//��һ�������Ǿ���ĵ�ַ���ڶ���������Ҫ�˵�λ��
//�����������Ǿ�������������ĸ������Ǿ��������
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

//�Ծ����ĳһ�н��б������
//��һ�������Ǿ���ĵ�ַ���ڶ���������Ҫ�˵ı���
//��������������һ��Ҫ����
//���ĸ���������������ж����У��������������������ж�����
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

//��������б任����ĳһ��Ԫ�ص����ɱ���ӵ���һ�д�
//��һ����������ĵ�ַ���ڶ�������Ҫ�˵ı���
//��������������һ�еļ��������ĸ�����Ҫ���ı����
//��������������ж�����
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

//��������Ԫ�ص�ֵ
//��һ�������Ǿ���ĵ�ַ���ڶ�������������Ҫ�������е�����
//���ĸ������Ǿ��������
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

//���������
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

//�������Ƿ�Ϊ���Ⱦ�������Ƿ���1��������Ƿ���-1
int full_rank_matrix(float* matrix, int row, int column)
{
	



	
}



/*
�������ĳ�ֱ�Ҫ������AB=E��AΪ���Ⱦ��󣨼�r (A)=n����
A������ֵȫ��Ϊ0��A������ʽ|A|��0��Ҳ�ɱ���ΪA����������󣨼�����ʽΪ0�ľ���
*/
void reverse_matrix(float* matrix, int row, int column)
{
	;
}

//�жϾ���(������)��ǰ�����²����Ƿ�Ϊ0���Ƿ���0�����Ƿ���1
/*�� | 4 4 4 4 |
	 | 0 4 4 4 |
	 | 0 0 4 4 |
	 | 0 0 4 4 |
	 ǰ2�о���������
	 ǰ3�оͲ���������
*/
//��һ�������Ǿ���ĵ�ַ���ڶ��������ǵ��ڼ���
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

//תΪ����������ʽ
//��һ�������Ǳ������ľ��󣬵ڶ�������������ľ���
//�����������Ǿ�������������ĸ������Ǿ��������
int upper_triangle_matrix(float* matrix1, int row)
{
	int column = row;
	int i = 0;
	int j = 0;
	int k = 0;
	int move_in = 0;
	int move_up = 0;
	int move = 0;
	float up_line = 0;
	float each_line = 0;
	float magnification = 0;
	int flag = 0;
	for (i = 0; i < column - 1; i++)
	{
		move_up = i * column + i;
		for (j = i+1; j < row; j++)
		{
			flag = 0;
			move = j * column + i;
			//printf("%d %d %d %d \n", i, j, move_up, move);
			up_line = *(matrix1 + move_up);
			each_line = *(matrix1 + move);
			while (up_line == 0)
			{
				for (k = 0; k < row - j; k++)
				{
					//printf("%d %d\n", j, k);
					exchange_matrix_row(matrix1, j + k - 1, j + k, column);
					//print_matrix_arr(matrix1, row, column);
					//printf("%d\n", k);
				}
				up_line = *(matrix1 + move);
				//printf("����һ��\n");
				flag++;
				if (flag > row - j)
				{
					init_matrix_zero(matrix1, row, column);
					return -1;
				}

			}
			//printf("%f\n", -(each_line / up_line));
			magnification = -(each_line / up_line);
			//printf("%f\n", magnification);
			self_add_matrix_row(matrix1, magnification, i, j, column);
			//print_matrix_arr(matrix1, row, column);
		}
	}
	return 1;
}


//������������ʽ��ֵ
//��һ������������������ʽ�ĵ�ַ
//�ڶ�������������������ʽ���У��У�
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
���������ʽ������������ʽ


*/
//��������ʽ
// ǰ����Ϊ����
//��һ�������Ǿ���ĵ�ַ���ڶ����������У�������0��ʼ�����������������У�������0��ʼ��
//���ĸ������Ǿ���һ���ж����У��У�
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
	upper_triangle_matrix(matrix_copy, row - 1);
	result = sum_upper_triangle_matrix(matrix_copy, row - 1);
	//printf("%f\n", result);
	free(matrix_copy);
	matrix_copy = NULL;
	free(assign);
	assign = NULL;
	return result;
}

//��������ʽ
//��һ���������Ǿ���ĵ�ַ���ڶ��������������У���0��ʼ��
//�����������������У���0��ʼ��
float remain_formula(float* matrix, int x, int y, int row)
{
	int flag = 1;
	float result = 0;
	if ((x + y) % 2 == 1)
	{
		flag = -flag;
	}

	result = algebra_remain_formula(matrix, x, y, row);
	if (result == (int)0xffffff)
	{
		return (float)0xffffffff;
	}
	result = flag * result;
	return result;
}

//��ӡ�����������ֵ
//��һ������������ĵ�ַ���ڶ�������������ĳ���
void print_float(float* arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%f\n", *(arr + i));
	}
}
//�������
//��һ�������Ǿ���ĵ�ַ���ڶ��������Ǿ�����У��У�
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
			printf("�þ���û�а������\n");
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

//�Ծ���������
float* division_matrix(float* matrix1, float* matrix2, int row1, int column1)
{
	float* inverse = NULL;
	float* inverse2 = NULL;
	int move_assign = 0;
	int row2 = column1;
	int column2 = column1;
	float* assign = NULL;
	float* assign2 = NULL;
	float proportion = 0;
	int i = 0;
	int j = 0;
	printf("aaa:\n");
	print_matrix_arr(matrix2, row2, column2);
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
	//free()
	printf("inverse\n");
	print_matrix_arr(inverse, row2, column2);
	proportion = sum_upper_triangle_matrix(matrix2, row2);
	print_matrix_arr(matrix2, row2, column2);



}














































