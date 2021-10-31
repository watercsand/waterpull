#include <stdio.h>
#include <string.h>
#include <malloc.h>

// �����ַ����ĳ���
// ��һ�������ǿ�ʼ�ĵ�ַ��Ҫ����'\0'��β
// ����һ������ֵ
int str_len(char* start)
{
	int i = 0;
	while (start[i] != '\0')
	{
		i++;
	}
	return i;
}

// �½�һ������,
// ��һ������Ϊ����
// ����һ��ָ�룬����ʧ�ܷ���NULL
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

// ���next����
// ��һ��������ģʽ�ַ���
// �ڶ���������next����ĵ�ַ(ʹ��ǰҪ�ȿ����ڴ�)
// ���㷨Ϊ�����㷨��next���鲢����0��ʼ
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

// ��ӡ����
// ��һ�������ǿ�ʼλ�ã��ڶ��������ǳ���
// ��10��������һ��
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

// kmp�㷨
// ��һ��������Ŀ�괮
// �ڶ���������ģʽ��
// ����ģʽ����Ŀ�괮�е�λ��
// �Ҳ�������-1
int index_kmp(char* target, char* modle)
{
	int target_len = 0;//�ֱ���������ַ����ĳ���
	int modle_len = 0;
	int* ne = NULL;
	int* ne2 = NULL;
	int i = 1;
	int j = 1;
	target_len = strlen(target);
	modle_len = strlen(modle);
	ne = nu(modle_len + 1);// ����next����
	next(modle, ne);// ��ʼ��next����
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

