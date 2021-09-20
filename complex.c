#include <stdio.h>
#include "complex.h"
#include <assert.h>
//��ʼ������
void assign_complex(struct Complex* a, float real, float imag)
{
	a->reaplart = real;
	a->imagpart = imag;
}

//������������ӣ���һ��Ϊ��ֵ���ֵ���ڶ����͵�����Ϊ�����뱻����
//����c����
void add_complex(struct Complex* c, struct Complex* a, struct Complex* b)
{
	c->reaplart = a->reaplart + b->reaplart;
	c->imagpart = a->imagpart + b->imagpart;
}

//�����������������һ��Ϊ��ֵ���ֵ���ڶ����͵�����Ϊ�����뱻����
//����c����
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
//������������ˣ���һ��Ϊ��ֵ���ֵ���ڶ����͵�����Ϊ�����뱻����
//����c����
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
//�����������������һ��Ϊ��ֵ���ֵ���ڶ����͵�����Ϊ�����뱻����
//����c����
void division_complex(struct Complex* c, struct Complex* a, struct Complex* b)
{
	c->reaplart = (((a->reaplart) * (b->reaplart)) + ((a->imagpart) * (b->imagpart))) / (((b->reaplart) * (b->reaplart)) + ((b->imagpart) * (b->imagpart)));
	c->imagpart = (((a->imagpart) * (b->reaplart)) - ((a->reaplart) * (b->imagpart))) / ((b->reaplart * b->reaplart) + ((b->imagpart) * (b->imagpart)));
}

//��ӡ������ֵ
void print_complex(struct Complex* a)
{
	printf("%f ", a->reaplart);
	printf("%f\n", a->imagpart);
}


//��ӡ���������ֵ
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

//���ظ�����ʵ��
float get_real_complex(struct Complex* a)
{
	return a->reaplart;
}

//���ظ������鲿
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