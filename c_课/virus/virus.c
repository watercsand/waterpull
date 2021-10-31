#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "kmp.h"

// ��״����ƥ���㷨
// ��һ�������ǲ��˵Ĳ���
// �ڶ��������ǲ�����ģ��
// ��ƥ���򷵻�1
// ��ƥ���򷵻�-1
int compare(char* patient_virus, char* virus_model)
{
	int pa_len = strlen(patient_virus);
	int vir_len = strlen(virus_model);
	int i = 0;
	int j = 0;
	int flag = -1;
	// printf("patient_virus = %s\n", patient_virus);
	// printf("virus_model = %s\n", virus_model);
	// printf("patient_virus_len = %d \nvirus_model_len = %d\n", pa_len, vir_len);
	char* compare_copy = NULL;
	compare_copy = malloc(sizeof(char) * (2*vir_len + 1));
	// ���������ģʽΪaabb,��compare_copyΪaabbaabb,
	// compare_char��ֱ�ȡaabb,abba,bbaa,baab
	char* compare_char = NULL;
	compare_char = malloc(sizeof(char) * (vir_len + 1));
	if (compare_char == NULL)
	{
		free(compare_copy);
		compare_copy = NULL;
		return -2;//�����ڴ�ʧ��
	}
	*(compare_char + vir_len) = '\0';
	
	if (compare_copy == NULL)
	{
		return -2;//�����ڴ�ʧ��
	}
	else // compare_copy�ĸ�ֵ
	{
		*(compare_copy + 2*vir_len) = '\0';
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < vir_len; j++)
			{
				*(compare_copy + i * vir_len + j) = *(virus_model + j);
			}
		}
	}
	// printf("compare_copy = %s\n", compare_copy);
	
	for (i = 0; i < vir_len; i++)
	{
		for (j = 0; j < vir_len; j++)
		{
			*(compare_char + j) = *(compare_copy + j + i);
		}
		// printf("each_char%d = %s\n", i, compare_char);
		flag = index_kmp(patient_virus, compare_char);//kmp�㷨ģʽƥ��
		if (flag != -1)// �ҵ�ƥ�������1
		{
			return 1;
		}
	}
	free(compare_copy);
	compare_copy = NULL;
	free(compare_char);
	compare_char = NULL;
	return -1;//û���ҵ�������-1
}