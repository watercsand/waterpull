#include "link.h"
#include <stdio.h>
#include <malloc.h>

void text()
{
	printf("in the text\n");
	struct lnode* n1 = NULL;
	n1 = init_list_single(n1);
	printf("%p\n", n1);
	list_print_single(n1);
	free(n1);
	n1 = NULL;
}

void text2()
{
	printf("in the text 2!\n\n");
	struct lnode* n1 = NULL;
	int len = 20;
	n1 = init_list(n1, len);
	list_print(n1);
	list_clear(n1);
	list_print(n1);
	free(n1);
	n1 = NULL;
}

void text3()
{
	printf("in the text 3!\n");
	struct lnode* n1 = NULL;
	int len = 10;
	n1 = init_list(n1, len);
	list_print(n1);
	int k = 0;
	for (k = 0; k < 11; k++)
	{
		printf("k=%d  ", k);
		int result = 0;
		get_elem(n1, k, &result);
		printf("result = %d\n", result);
	}
	int re = 0;
	int find = 0;
	for (find = 20; find <= 31; find++)
	{
		re = locate_elem(n1, find);
		printf("find=%d\n", re);
	}
	int insert_num = 345;// 测试过大的输入
	int insert_place = 12;
	list_insert(n1, insert_place, insert_num);
	list_print(n1);
	printf("************************************\n");
	insert_num = 187;// 测试开头的输入
	insert_place = 0;
	n1 = list_insert(n1, insert_place, insert_num);
	list_print(n1);
	printf("************************************2\n");
	insert_num = 467;// 测试过小的输入
	insert_place = -1;
	n1 = list_insert(n1, insert_place, insert_num);
	list_print(n1);
	printf("************************************3\n");
	insert_num = 66;// 测试为尾的输入
	insert_place = 13;
	n1 = list_insert(n1, insert_place, insert_num);
	list_print(n1);
	printf("************************************4\n");
	insert_num = 764;// 测试正常的输入
	insert_place = 7;
	n1 = list_insert(n1, insert_place, insert_num);
	list_print(n1);
	free(n1);
	n1 = NULL;
}



