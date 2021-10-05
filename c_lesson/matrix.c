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
//�Ծ���������
void division_matrix(float* matrix3, float* matrix1, float* matrix2, int row1, int column1, int column2)
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
���������ʽ������������ʽ


*/
//��������ʽ
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

//�������

















































