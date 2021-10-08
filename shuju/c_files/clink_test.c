#include <stdio.h>
#include "clink.h"
#include "link.h"
#include <Windows.h>




void text11()
{
	printf("in the text11\n");
	int i = 0;
	while (i < 0x4f)
	{
		struct lnode* n1 = NULL;
		int n1_len = 0xffff;
		n1 = init_clink(n1, n1_len);
		printf("del finish%d\n", i);
		// clink_print(n1);
		del_clink(n1);
		i++;
	}
}

void text12()
{
	printf("in the text12\n");
	int len = 0;
	struct lnode* n1 = NULL;
	int n1_len = 10;
	n1 = init_clink(n1, n1_len);
	len = clink_len(n1);
	printf("len = %d\n", len);
	del_clink(n1);
}

void text13()
{
	printf("\n\nin the text13\n");
	int len = 10;
	int insert_place = 2;
	int insert_number = 4444;
	struct lnode* n1 = NULL;
	n1 = init_clink(n1, len);
	clink_print(n1);
	n1 = insert_clink(n1, insert_place, insert_number);
	clink_print(n1);
	del_clink(n1);
	printf("******************\n");
	n1 = NULL;
	len = 1;
	n1 = init_clink(n1, len);
	clink_print(n1);
	insert_place = 0;
	n1 = insert_clink(n1, insert_place, insert_number);
	clink_print(n1);
	del_clink(n1);
	n1 = NULL;
}

void text14()
{
	printf("\n**************************************************\nin the text14\n");
	int len = 10;
	int del_place = -1;
	struct lnode* n1 = NULL;
	int i = 0x1;
	while (i)
	{
		n1 = init_clink(n1, len);
		clink_print(n1);
		n1 = del_clink_single(n1, del_place);
		clink_print(n1);
		del_clink(n1);
		n1 = NULL;
		if (i % 100 == 0)
		{
			system("cls");
		}
		i--;
	}
	printf("***************************2\n");
	n1 = init_clink(n1, len);
	clink_print(n1);
	del_place = 0;
	n1 = del_clink_single(n1, del_place);
	clink_print(n1);
	del_clink(n1);
	n1 = NULL;

	printf("***************************3\n");
	n1 = init_clink(n1, len);
	clink_print(n1);
	del_place = 1;
	n1 = del_clink_single(n1, del_place);
	clink_print(n1);
	del_clink(n1);
	n1 = NULL;

	printf("***************************4\n");
	n1 = init_clink(n1, len);
	clink_print(n1);
	del_place = 9;
	n1 = del_clink_single(n1, del_place);
	clink_print(n1);
	del_clink(n1);
	n1 = NULL;

	printf("***************************5\n");
	n1 = init_clink(n1, len);
	clink_print(n1);
	del_place = 10;
	n1 = del_clink_single(n1, del_place);
	clink_print(n1);
	del_clink(n1);
	n1 = NULL;


}

void text15()
{
	printf("in the text15\n");
	struct lnode* n1 = NULL;
	int len = 10;
	int find = 133;
	n1 = init_clink(n1, len);
	clink_print(n1);
	int result = -1;
	for (find = 120; find < 140; find += 1)
	{
		result = clink_index(n1, find);
		printf("find = %d  result = %d\n", find, result);
	}
	
	del_clink(n1);
	n1 = NULL;
}