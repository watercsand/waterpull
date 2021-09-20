#ifndef __complex_h__
#define __complex_h__


struct Complex
{
	float reaplart;
	float imagpart;
};


void assign_complex(struct Complex* a, float real, float imag);//��ʼ��
void add_complex(struct Complex* c, struct Complex* a, struct Complex* b);//�ӷ�
void subtraction_complex(struct Complex* c, struct Complex* a, struct Complex* b);//����
void multiply_complex(struct Complex* c, struct Complex* a, struct Complex* b);//�˷�
void division_complex(struct Complex* c, struct Complex* a, struct Complex* b);//����
void print_complex(struct Complex* a);//��ӡ����
void print_complex_arr(struct Complex* a, int number);//��ӡ��������
float get_real_complex(struct Complex* a);//���ظ�����ʵ��
float get_imag_complex(struct Complex* a);//��˼�������鲿


#endif