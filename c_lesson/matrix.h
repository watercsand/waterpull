#ifndef __matrix_h__
#define __matrix_h__
void init_matrix_zero(float* matrix, int row, int column);//������ȫ��Ԫ����Ϊ0
float* init_matrix(float* matrix, int row, int column);//���پ�����ڴ�ռ�,��ȫ��Ϊ0
void assigned_matrix_single(float* matrix, float number_assign, int x, int y, int row, int column);//�Ծ���ĵ���Ԫ�ؽ��и�ֵ
void matrix_unit(float* matrix, int row);//�Ծ�����е�λ������λ����
float* init_matrix_unit(float* matrix, int row);//�Ծ�����д��������е�λ��
void assigned_matrix_arr(float* matrix, float* assign_arr, int row, int column);//�Ծ����ȫ��Ԫ��ȫ�����и�ֵ
void print_matrix_single(float* matrix, int x, int y, int row, int column);//��ӡ��������Ԫ�ص�ֵ
void print_matrix_arr(float* matrix, int row, int column);//��ӡ���о���Ԫ�ص�ֵ
void add_matrix(float* matrix3, float* matrix1, float* matrix2, int row, int column);//����������������
void subtraction_matrix(float* matrix3, float* matrix1, float* matrix2, int row, int column);//����������������
void multiply_matrix(float* matrix3, float* matrix1, float* matrix2, int row1, int column1, int column2);// ����������������
void multiply_matrix_number(float* matrix, float number, int row, int column);//�Ե���������б������
void multiply_matrix_row(float* matrix, float number, int row_assign, int row, int column);//�Ծ����ĳһ�н��б������
void self_add_matrix_row(float* matrix, float number, int row_assign1, int row_assign2, int column);//��������б任
void exchange_matrix_row(float* matrix, int row_assign1, int row_assign2, int column);//��������Ԫ�ص�ֵ
int rank_matrix(float* matrix, int row, int column);

int is_zero_matrix(float* matrix, int x, int row);//�жϾ���(������)��ǰ�����²����Ƿ�Ϊ0
void upper_triangle_matrix(float* matrix1, int row, int column);//תΪ����������ʽ
float* algebra_remain_formula(float* matrix, int x, int y, int row);



#endif
