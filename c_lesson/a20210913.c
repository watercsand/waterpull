#define _CRT_SECURE_NO_WARNINNGS 1
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>

int lesson_0913_1()
{
	int* p = malloc(44);
	int i = 0;
	if (p == NULL)
	{
		free(p);
		return 0;
	}
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}

	printf("\n");
	int* ptr = realloc(p, 100);//realloc是调整之后内存的大小
	if (ptr != NULL)
	{
		*(p + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
	
	free(ptr);
	p = NULL;
	return 0;
}

int lesson_0913_2()
{
	int* p = (int*)malloc(40);
	int i = 0;
	/*
	对动态开辟的内存的越界访问
	万一malloc失败，p就被赋值为NULL

	
	*/
	
	free(p);
	p = NULL;
	return 0;
}

int lesson_0913_3()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		return 0;
	}
	int* p2 = realloc(p, 80);
	if (p2 != NULL)
	{
		p = p2;
	}
	/*realloc开辟新空间
	int* p = realloc(NULL, 40);

	常见的错误
	对NULL指针解引用操作
	p没从释放开始的空间开始释放
	对同一块动态内存进行多次释放
	动态开辟内存忘记释放（内存泄漏）
	*/
	



	return 0;
}

/*
柔性数组
struct s
{
	int n;
	int arr[0];//柔性数组成员
}



*/
struct s5
{
	int n;
	int arr[];
};

int lesson_0913_4()
{
	struct s5* s1 = (struct s5*)malloc(sizeof(struct s5) + 5 * sizeof(int));
	//printf("%d\n", sizeof(s1));
	if (s1 == NULL)
	{
		return 0;
	}
	s1->n = 100;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		s1->arr[i] = i;
	}
	struct s5* ptr = realloc(s1, 44);
	if (ptr != NULL)
	{
		s1 = ptr;
	}
	else
	{
		return 0;
	}
	for (i = 5; i < 10; i++)
	{
		s1->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", s1->arr[i]);
	}
	printf("\n");

	free(s1);
	s1 = NULL;

	return 0;
}


















































































































