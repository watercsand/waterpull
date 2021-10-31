#include <stdio.h>
#include <string.h>
#include <malloc.h>

// 计算字符串的长度
// 第一个参数是开始的地址，要求有'\0'结尾
// 返回一个长度值
int str_len(char* start)
{
	int i = 0;
	while (start[i] != '\0')
	{
		i++;
	}
	return i;
}

// 新建一个数组,
// 第一个参数为长度
// 返回一个指针，开辟失败返回NULL
int* nu(int len)
{
	int* a = NULL;
	int i = 0;
	a = malloc(sizeof(int) * len);
	if (a != NULL)
	{
		for (i = 0; i < len; i++)
		{
			*(a + i) = 0;
		}
		return a;
	}
	else
	{
		return NULL;
	}
}

// 求解next数组
// 第一个参数是模式字符串
// 第二个参数是next数组的地址(使用前要先开辟内存)
// 此算法为方便算法，next数组并不从0开始
void next(char* target, int* next)
{
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < (int)strlen(target))
	{
		if (j == 0 || target[i - 1] == target[j - 1])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

// 打印数组
// 第一个参数是开始位置，第二个参数是长度
// 第10个数换行一次
void number_printer(int* start, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", *(start + i));
		if ((i % 10 == 0) && (i != 0))
		{
			printf("\n");
		}
	}
	if (i % 10 != 0)
	{
		printf("\n");
	}
}

// kmp算法
// 第一个参数是目标串
// 第二个参数是模式串
// 返回模式串在目标串中的位置
// 找不到返回-1
int index_kmp(char* target, char* modle)
{
	int target_len = 0;//分别计算两个字符串的长度
	int modle_len = 0;
	int* ne = NULL;
	int* ne2 = NULL;
	int i = 1;
	int j = 1;
	target_len = strlen(target);
	modle_len = strlen(modle);
	ne = nu(modle_len + 1);// 开辟next数组
	next(modle, ne);// 初始化next数组
	while (i <= target_len && j <= modle_len)
	{
		if (j == 0 || target[i - 1] == modle[j - 1])
		{
			i++;
			j++;
		}
		else
		{
			j = ne[j];
		}
	}
	if (j > modle_len)
	{
		return i - modle_len;
	}
	free(ne);
	ne = NULL;
	if (j > target_len)
	{
		return i - target_len;
	}
	return -1;
}

