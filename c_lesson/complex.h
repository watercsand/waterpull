#ifndef __complex_h__
#define __complex_h__


struct Complex
{
	float reaplart;
	float imagpart;
};


void assign_complex(struct Complex* a, float real, float imag);//初始化
void add_complex(struct Complex* c, struct Complex* a, struct Complex* b);//加法
void subtraction_complex(struct Complex* c, struct Complex* a, struct Complex* b);//减法
void multiply_complex(struct Complex* c, struct Complex* a, struct Complex* b);//乘法
void division_complex(struct Complex* c, struct Complex* a, struct Complex* b);//除法
void print_complex(struct Complex* a);//打印复数
void print_complex_arr(struct Complex* a, int number);//打印复数数组
float get_real_complex(struct Complex* a);//返回复数的实部
float get_imag_complex(struct Complex* a);//反思复数的虚部


#endif