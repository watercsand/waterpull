#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <windows.h>



/*
��̬�ڴ�
malloc
free
calloc
realloc
�������ڴ����
��������



ջ��
�ֲ�����
��������ʽ����

����
��̬�ڴ�ķ���

��̬��
ȫ�ֱ���
��̬����

c99 ���Դ����仯���ȵ�����
linux centos 7 8 ֧��c99





*/

int lesson_0912_1()
{
	int k = 0;
	while (k < 10)
	{
		int a = 10;
		int* p = (int*)malloc(40);
		if (p == NULL)
		{
			printf("%s\n", strerror(errno));
		}
		else
		{
			printf("�������ٿռ�\n");
			int i = 0;
			for (i = 0; i < a; i++)
			{
				*(p + i) = i;
			}
			for (i = 0; i < a; i++)
			{
				printf("%d ", *(p + i));
			}
			printf("\n");
			//Sleep(3000);
			k++;
			free(p);
			//Sleep(3000);
			p = NULL;//��ֹ�ٴ�ʹ��ָ��
		}
		
		//����̬����Ŀռ䲻��ʹ�õ�ʱ��
		//Ӧ�û�������ϵͳ
		//free�Զ�̬�ڴ���л���
	}
	/*
	malloc���ڴ�������һ���������õĿռ䣬������ָ�����ռ��ָ��
	����ֵĬ��ֵvoid*
	�������ptrָ��Ŀռ䲻�Ƕ�̬���ٵģ���ôfree��������Ϊ��δ�����
	�������ptr��NULLָ�룬����ʲô���鲻��
	*/

	return 0;
}

int lesson_0912_2()
{
	//calloc���ʼ������Ϊ0
	//malloc������г�ʼ����Ч�ʽϸ�
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p+i));
		}
	}
	printf("\n");
	//�ͷſռ�
	free(p);
	p = NULL;


	return 0;
}

int lesson_0912_3()
{
	//realloc
	/*
	������̬�ڴ�Ĵ�С

	*/
	int* p = (int*)malloc(20);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i) = i;
		}
	}
	//������ʹ��malloc���ٵ�20���ֽڵĿռ�
	//�������20���ֽڲ����������ǵ�ʹ��
	//ϣ���ܿ���40���ֽڵĿռ�
	//ʹ��realloc��������̬���ٵ��ڴ�ռ�
	/*
	realloc
	void* realloc()
	
	*/
	int* p2 = realloc(p, 40);
	if (p2 == NULL)
	{
		printf("fail to realloc\n");
	}

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (p2 == NULL)
		{
			free(p);
			break;
		}
		printf("%d ", *(p2 + i));
	}
	printf("\n");
	free(p2);
	p2 = NULL;
	return 0;
	/*
	reallocʹ�õ�ע������
	���pָ��Ŀռ�֮�����㹻���ڴ�ռ����׷�ӣ���ֱ��׷�ӣ��󷵻�p
	���pָ��Ŀռ�֮��û���㹻���ڴ�ռ����׷�ӣ�
	��realloc������������һ���µ��ڴ�����������һ���µ��ڴ�����
	����������������Ŀռ䣬���Ұ�ԭ���ڴ�����ݿ����������ͷžɵĿռ�
	
	*
	*/

}
















