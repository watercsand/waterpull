#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "link.h"

// 创建一个循环链表
// 第一个参数是链表的地址（要为NULL）
// 第二个参数是链表的长度
struct lnode* init_clink(struct lnode* head, int len)
{
	struct lnode* a = NULL;
	a = init_list(head, len);
	head = a;
	struct lnode* first = a;
	int i = 0;
	for (i = 0; i < len - 1; i++)
	{
		// list_print_single(head);
		head = head->next;
	}
	head->next = a;
	return a;
}

// 打印循环列表
// 第一个参数是链表的首元素地址
// 打印个数为列表的长度（即一圈）
void clink_print(struct lnode* start)
{
	struct lnode* begin = start;
	int i = 0;
	do
	{
		printf("%d\n", i);
		i++;
		list_print_single(start);

		start = start->next;
	} 	while (start != begin);
}

// 删除循环链表中的所有元素
// 第一个地址为链表中任意一个元素的地址
// 将会进行一圈的删除
void del_clink(struct lnode* start)
{
	struct lnode* begin = start;
	struct lnode* tmp = start->next;
	do
	{
		free(start);
		start = tmp;
		tmp = start->next;
	} 	while (start != begin);
	start = NULL;
}


// 计算循环列表的长度
// 输入的参数是循环列表的任意一个地址
// 返回计算循环列表的长度
int clink_len(struct lnode* start)
{
	struct lnode* begin = start;
	struct lnode* tmp = start->next;
	int len = 0;
	while (start->next != begin)
	{
		start = start->next;
		len++;
	}
	len += 1;
	return len;
}

// 在循环列表中插入元素
// 第一个参数是循环列表的地址，
// 第地二个参数是插入元素的位置
//		插入的位置元素下标均为索引值，从0开始
//		插入的元素的位置会自动钳制在列表的长度
//		若长度大于列表的长度，
//			且插入元素的位置与列表长度求余后等于列表的长度，
//			则首地址不变,即追加
//		若长度大于列表的长度，
//			且插入元素的位置与列表长度求余后不等于列表的长度，
//			首地址依然不变
//		若插入位置输入为0，
//			首元素地址才会变化，并返回新的首元素地址
//		无论首元素位置是否发生变化，都会返回值，
//			但除了插入位置为0的情况以外，你都可以不接收
//			即使插入的位置为0，你没有接收，也不会报错
//			但可能导致您的链表顺序错误
// 第三个参数是插入的元素的内容和
// 备注 这个函数中有判断链表长度的函数，可能导致效率变低
struct lnode* insert_clink(struct lnode* insert, int place, int number)
{
	struct lnode* tmp = insert;
	struct lnode* in = NULL;
	struct lnode* re = insert;
	if (place < 0)
	{
		place = 0;
	}
	in = init_list_single(in);
	in->data = number;
	int i = 0;
	int len = clink_len(insert);
	if (((place % len) == 0) && (place != 0))
	{
		;
	}
	else//判断插入的位置
	{
		place = place % len;
	}
	while (i < place - 1)
	{
		insert = insert->next;
		i++;
	}
	in->next = insert->next;
	insert->next = in;
	insert = re;
	if (place == 0)//纠正插入的位置
	{
		// printf("in the len1\n");
		for (i = 0; i < len + 2; i++)
		{
			insert = insert->next;
		}
		return insert;
	}
	else
	{
		return insert;
	}
}

// 删除循环链表的一个元素
// 第一个参数是循环链表的地址
// 第二个参数是要删除元素距离地址的偏移量（索引 从0开始）
//		若大于列表长度则删除最后一个元素
//		若小于列表长度则删除最前的一个元素
// 返回一个链表的地址，仅在删除首元素地址时需要接收
//		不接收会导致错误（error级）
struct lnode* del_clink_single(struct lnode* head, int place)
{
	struct lnode* re = head;
	struct lnode* first = head;
	struct lnode* ne = head->next;
	int len = clink_len(head);// 链表的长度
	if ((place != 0) && (place >= len))
	{
		place = len - 1;
	}
	int i = 0;
	if (place < 0)
	{
		place = 0;
	}
	if (place == 0)//删除是首元素地址的情况
	{
		i = 0;
		while (i < place)
		{
			head = head->next;
			i++;
		}
		i = 0;
		while (i < len - 1)// 链表的顺序摆正，算法有待优化
		{
			head = head->next;
			i++;
		}
		// printf("head=%p\n", head);
		ne = head->next;
		head->next = head->next->next;
		// printf("next=%p\n", ne);
		head = head->next;
		free(ne);
		ne = NULL;
		return head;
	}
	else//一般情况
	{
		i = 0;
		while (i < place - 1)
		{
			head = head->next;
			i++;
		}
		i = 0;
		// printf("place=%p\n", head);
		ne = head->next;
		head->next = head->next->next;
		free(ne);
		ne = NULL;
		return first;
	}
}

int clink_index(struct lnode* head, int number)
{
	int i = 0;
	struct lnode* begin = head;
	do
	{
		if (number == head->data)
		{
			return i;
		}
		head = head->next;
		i++;
	} while (head != begin);
	return -1;

}





