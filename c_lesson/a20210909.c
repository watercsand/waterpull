#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

/*
memmove
void* memmove(void* dest, const void* src, size_t count);

memcpyֻҪ�����ص����ڴ濽��
memmove�����ص��ڴ�Ŀ���

*/
int lesson_0909_1()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	memmove(arr + 2, arr, 20);
	for (i = 0; i < 10; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	return 0;
}

void* my_memmove(void* dest, void* src, size_t count)
{
	assert(dest != NULL);
	assert(src != NULL);
	if (dest < src || (char*)dest > ((char*)src + count))
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);

		}
	} 
	return src;
}

int lesson_0909_2()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,3,2,1 };
	int ret = memcmp(arr1, arr2, 8);
	printf("%d\n", ret);
	ret = memcmp(arr1, arr2, 16);
	printf("%d\n", ret);
	return 0;
}

void d_print_arr(int* arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
		if (i % 10 == 0 && i != 0)
		{
			printf("\n");
		}
	}
	if (i % 10 != 0)
	{
		printf("\n");
	}
}

int lesson_0909_3()
{
	int arr[10] = { 0 };
	memset(arr, 1, 10);
	d_print_arr(arr, 10);

	return 0;
}

/*
�ṹ������
����
�����Ķ���
��ʼ��
�ڴ����
����
λ�ε����
����ֲ��

ö�����͵Ķ���
ö�ٵ��ŵ�
	  ʹ��
����
	�������͵Ķ���
	���ϵ��ص�
	���ϴ�С�ļ���
*/

struct student
{
	char name[20];
	char tele[12];
	char sex[10];
	int age;
};

struct note
{
	int date;
	struct note* next;
	
};

struct t
{
	double weight;
	short age;
};

struct s
{
	char c;
	struct t st;
	int a;
	double d;
	char arr[20];
};

int lesson_0909_4()
{
	struct s a = { 'c', {55.6, 30}, 100, 3.14, "hello world" };
	printf("%c %d %lf %s\n", a.c, a.a, a.d, a.arr);
	printf("%lf %d\n", a.st.weight, a.st.age);
	return 0;
}

/*
struct s1
{
	char c1;
	int a;
	char c2;
};
1   4
1   4
4   4
12

struct s2
{
	char c1;
	char c2;
	int a;
};
1	1    
1   1 
2   4
4   4
8

������
������Ĭ�ϵ�һ�������� �� �ó�Ա�Ĵ�С�ıȽ�ֵ 
������ = ������Ĭ�ϵ�һ����������ó�Ա��С�Ľ�Сֵ 
*/
struct  s3
{
	double d;
	char c;
	int i;
};

int lesson_0909_5()
{
	struct s3 a;
	printf("%d\n", sizeof(a));
	return 0;
}

/*
struct  s3
{
	double d;
	char c;
	int i;
};
d    8
c    4
i    4
sum--16

*/
#pragma pack(4)
struct s4
{
	char c;
	struct s3 s3;
	double d;
};
#pragma pack()

int lesson_0909_6()
{
	struct s4 a;
	printf("%d\n", sizeof(a));
	return 0;
}

/*
�����ڴ�����ԭ��
ƽ̨ԭ��
ĳЩӲ��ƽֻ̨�ܷ�ĳЩ��ַ��ȡĳЩ�ض����͵����ݣ������׳�Ӳ���쳣

����ԭ�����ݽṹ��������ջ��Ӧ�þ����� ���������߽��Ƕ��롣
Ϊ�˷���δ������ڴ棬��������Ҫ�����ڴ���ʣ��������ڴ���ʽ���Ҫһ�η���

����ƽṹ�����ʱ����ͬһС�ͱ���������һ��

�޸Ķ�����
#pragma pack(4)
struct xxx
{
	
};
#pragma pack()
ȡ��Ĭ�϶�����


*/

int lesson_0909_7()
{
	printf("%d\n", offsetof(struct s4, c));
	printf("%d\n", offsetof(struct s4, s3));
	printf("%d\n", offsetof(struct s4, d));
	
	return 0;
}

void init_s(struct s* tmp)
{
	tmp->a = 100;
	tmp->c = 'w';
	tmp->d = 3.14;
}
void struct_s_print(struct s tmp)
{
	printf("%d ", tmp.a);
	printf("%c ", tmp.c);
	printf("%lf \n", tmp.d);

}


void struct_s_print2(struct s* tmp)
{
	printf("%d ", tmp->a);
	printf("%c ", tmp->c);
	printf("%lf \n", tmp->d);

}


int lesson_0909_8()
{
	struct s a = { 0 };
	init_s(&a);
	struct_s_print(a);
	struct_s_print2(&a);
	return 0;
}

struct a
{
	int a : 2;
	int b : 5;
	int c : 10;
	int d : 30;
};

int lesson_0909_9()
{
	struct a s1;
	printf("%d\n", sizeof(s1));
	return 0;
}

struct a2
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};

int lesson_0909_10()
{
	struct a2 s = { 0 };
	s.a = 10;
	s.b = 20;
	s.c = 3;
	s.d = 4;
	return 0;
}

enum sex
{
	male,
	female,
	secret
};

int lesson_0909_11()
{
	enum sex s = male;

	return 0;
}

enum color
{
	red,
	yellow,
	blue
};

int lesson_0909_12()
{
	enum sex s = male;
	enum color c = blue;
	printf("%d %d %d", red, blue, yellow);
	return 0;
}

/*
����
����һϵ�еĳ�Ա��������һ��ռ�




*/


union un
{
	char c;
	int i;
};

int lesson_0909_13()
{
	union un u;
	printf("%d\n", sizeof(u));
	printf("%p %p %p\n", &(u), &(u.c), &(u.i));
	return 0;
}

int check_union_sys()
{
	union un u;
	u.i = 1;
	return u.c;
}































