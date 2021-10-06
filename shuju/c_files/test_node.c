#include "link.h"
#include <stdio.h>
#include <malloc.h>

/*--------------------------------------------------------------------
Author: watercsand
git:	waterpull
email: 1337259688@qq.com
area:	China

this file only upload on the github
only for learning
if you see this file on any other website
!!!!!that all without permisson!!!!!
!!!!!   prohibit commercial    !!!!!
Any illegal act will be investigated
if you find any of this illegal activity
please send me an email (although I only check email occasionally)
thank you

in addition
I copied some of this stuff from the internet
especially the comments section
If you find out that I have infringed
Please contact with me
I'll delete it
--------------------------------------------------------------------*/

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

	printf("************************************\n");
	int insert_num = 345;// 测试过小的输入
	int insert_place = -1;
	printf("insert_place=%d\n", insert_place);
	printf("insert_number=%d\n\n", insert_num);
	n1 = list_insert(n1, insert_place, insert_num);
	list_print(n1);

	printf("************************************3\n");
	insert_num = 187;// 测试开头的输入
	insert_place = 0;
	printf("insert_place=%d\n", insert_place);
	printf("insert_number=%d\n\n", insert_num);
	n1 = list_insert(n1, insert_place, insert_num);
	list_print(n1);

	printf("************************************4\n");
	insert_num = 448;// 测试为开头第二个的输入
	insert_place = 1;
	printf("insert_place=%d\n", insert_place);
	printf("insert_number=%d\n\n", insert_num);
	n1 = list_insert(n1, insert_place, insert_num);
	list_print(n1);

	printf("************************************5\n");
	insert_num = 467;// 测试过大的输入
	insert_place = 14;
	printf("insert_place=%d\n", insert_place);
	printf("insert_number=%d\n\n", insert_num);
	n1 = list_insert(n1, insert_place, insert_num);
	list_print(n1);

	printf("************************************6\n");
	insert_num = 66;// 测试为尾的输入
	insert_place = 14;
	printf("insert_place=%d\n", insert_place);
	printf("insert_number=%d\n\n", insert_num);
	n1 = list_insert(n1, insert_place, insert_num);
	list_print(n1);

	printf("************************************7\n");
	insert_num = 764;// 测试正常的输入
	insert_place = 7;
	printf("insert_place=%d\n", insert_place);
	printf("insert_number=%d\n\n", insert_num);
	n1 = list_insert(n1, insert_place, insert_num);
	list_print(n1);

	free(n1);
	n1 = NULL;
}


void text4()
{
	printf("\n*********************************\n");
	printf("in the text4\n");
	struct lnode* n1 = NULL;
	int a = 15;
	n1 = init_list(n1, a);
	list_print(n1);
	printf("**************************\n");
	int result = -1;
	int del_place = -1;
	int i = 0;

	printf("del_place=%d\n", del_place);
	n1 = list_delete(n1, del_place, &result);
	printf("result=%d\n\n", result);
	list_print(n1);
	printf("**************************1\n");

	del_place = 0;
	printf("del_place=%d\n", del_place);
	n1 = list_delete(n1, del_place, &result);
	printf("result=%d\n\n", result);
	list_print(n1);
	printf("**************************2\n");

	del_place = 1;
	printf("del_place=%d\n", del_place);
	n1 = list_delete(n1, del_place, &result);
	printf("result=%d\n\n", result);
	list_print(n1);
	printf("**************************3\n");

	del_place = 5;
	printf("del_place=%d\n", del_place);
	n1 = list_delete(n1, del_place, &result);
	printf("result=%d\n\n", result);
	list_print(n1);
	printf("**************************4\n");

	del_place = 10;
	printf("del_place=%d\n", del_place);
	n1 = list_delete(n1, del_place, &result);
	printf("result=%d\n\n", result);
	list_print(n1);
	printf("**************************5\n");

	del_place = 11;
	printf("del_place=%d\n", del_place);
	n1 = list_delete(n1, del_place, &result);
	printf("result=%d\n\n", result);
	list_print(n1);
	printf("**************************5\n");
}












