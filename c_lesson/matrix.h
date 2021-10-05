#ifndef __matrix_h__
#define __matrix_h__
void init_matrix_zero(float* matrix, int row, int column);//将矩阵全部元素置为0
float* init_matrix(float* matrix, int row, int column);//开辟矩阵的内存空间,并全置为0
void assigned_matrix_single(float* matrix, float number_assign, int x, int y, int row, int column);//对矩阵的单个元素进行赋值
void matrix_unit(float* matrix, int row);//对矩阵进行单位化（单位矩阵）
float* init_matrix_unit(float* matrix, int row);//对矩阵进行创建并进行单位化
void assigned_matrix_arr(float* matrix, float* assign_arr, int row, int column);//对矩阵的全部元素全部进行赋值
void print_matrix_single(float* matrix, int x, int y, int row, int column);//打印单个矩阵元素的值
void print_matrix_arr(float* matrix, int row, int column);//打印所有矩阵元素的值
void add_matrix(float* matrix3, float* matrix1, float* matrix2, int row, int column);//对两个矩阵进行相加
void subtraction_matrix(float* matrix3, float* matrix1, float* matrix2, int row, int column);//对两个矩阵进行相减
void multiply_matrix(float* matrix3, float* matrix1, float* matrix2, int row1, int column1, int column2);// 对两个矩阵进行相乘
void multiply_matrix_number(float* matrix, float number, int row, int column);//对单个矩阵进行倍数相乘
void multiply_matrix_row(float* matrix, float number, int row_assign, int row, int column);//对矩阵的某一行进行倍数相乘
void self_add_matrix_row(float* matrix, float number, int row_assign1, int row_assign2, int column);//矩阵初等行变换
void exchange_matrix_row(float* matrix, int row_assign1, int row_assign2, int column);//交换两行元素的值
int rank_matrix(float* matrix, int row, int column);

int is_zero_matrix(float* matrix, int x, int row);//判断矩阵(上三角)的前几行下部分是否为0
void upper_triangle_matrix(float* matrix1, int row, int column);//转为上三角行列式
float* algebra_remain_formula(float* matrix, int x, int y, int row);



#endif
