#include <stdio.h>
#include "complex.h"
#include <assert.h>
//初始化复数
void assign_complex(struct Complex* a, float real, float imag)
{
	a->reaplart = real;
	a->imagpart = imag;
}

//对两个复数相加，第一个为赋值后的值，第二个和第三个为加数与被加数
//返回c变量
void add_complex(struct Complex* c, struct Complex* a, struct Complex* b)
{
	c->reaplart = a->reaplart + b->reaplart;
	c->imagpart = a->imagpart + b->imagpart;
}

//对两个复数相减，第一个为赋值后的值，第二个和第三个为加数与被加数
//返回c变量
void subtraction_complex(struct Complex* c, struct Complex* a, struct Complex* b)
{
	c->reaplart = a->reaplart - b->reaplart;
	c->imagpart = a->imagpart - b->imagpart;
}


/*
(a.re + a.im)*(b.re + b.im)
a.re*b.re + a.re*b.im + a.im*b.re + a.im*b.im
a.re*b.re -a.im*b.im +a.re*b.im + a.im*b.re
*/
//对两个复数相乘，第一个为赋值后的值，第二个和第三个为乘数与被乘数
//返回c变量
void multiply_complex(struct Complex* c, struct Complex* a, struct Complex* b)
{
	c->reaplart = (a->reaplart) * (b->reaplart) - ((a->imagpart) * (b->imagpart));
	c->imagpart = ((a->reaplart) * (b->imagpart)) + ((a->imagpart) * (b->reaplart));
}

/*
(a.re+a.im)/(b.re+b.im)
(a.re + a.im)*(b.re - b.im)/((b.re + b.im)*(b.re - b.im))
(a.re*b.re - a.re*b.im + a.im*b.re + a.im*b.im)/(b.re*b.re + b.im*b.im)
(a.re*b.re + a.im*b.im)/(b.re*b.re + b.im*b.im)     +     (a.im*b.re - a.re*b.im)/(b.re*b.re + b.im*b.im)
*/
//对两个复数相除，第一个为赋值后的值，第二个和第三个为除数与被除数
//返回c变量
void division_complex(struct Complex* c, struct Complex* a, struct Complex* b)
{
	c->reaplart = (((a->reaplart) * (b->reaplart)) + ((a->imagpart) * (b->imagpart))) / (((b->reaplart) * (b->reaplart)) + ((b->imagpart) * (b->imagpart)));
	c->imagpart = (((a->imagpart) * (b->reaplart)) - ((a->reaplart) * (b->imagpart))) / ((b->reaplart * b->reaplart) + ((b->imagpart) * (b->imagpart)));
}

//打印复数的值
void print_complex(struct Complex* a)
{
	printf("%f ", a->reaplart);
	printf("%f\n", a->imagpart);
}


//打印复数数组的值
void print_complex_arr(struct Complex* a, int number)
{
	assert(number > 0);
	int i = 0;
	for (i = 0; i < number; i++)
	{
		print_complex(&a[i]);
	}
	printf("\n");
}

//返回复数的实部
float get_real_complex(struct Complex* a)
{
	return a->reaplart;
}

//反回复数的虚部
float get_imag_complex(struct Complex* a)
{
	return a->imagpart;
}



/*struct Complex com[3] = { {2,3}, {3,4}, {0} };
add_complex(&com[2], &com[1], &com[0]);
print_complex_arr(com, sizeof(com)/sizeof(com[0]));
subtraction_complex(&com[2], &com[0], &com[1]);
print_complex_arr(com, sizeof(com)/sizeof(com[0]));
multiply_complex(&com[2], &com[0], &com[1]);
print_complex_arr(com, sizeof(com) / sizeof(com[0]));
division_complex(&com[2], &com[0], &com[1]);
print_complex_arr(com, sizeof(com) / sizeof(com[0]));
struct Complex com2[5] = { 0 };
assign_complex(&com2[0], 8, 6);
assign_complex(&com2[1], 4, 3);
multiply_complex(&com2[2], &com2[0], &com2[1]);
add_complex(&com2[3], &com2[0], &com2[1]);
division_complex(&com2[4], &com2[2], &com2[3]);
print_complex_arr(com2, sizeof(com2) / sizeof(com2[0]));
*/