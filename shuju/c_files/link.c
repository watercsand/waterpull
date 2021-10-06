#include <stdio.h>
#include "link.h"
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

// 初始化一个元素
// 第一个参数是传入的地址，输入要为NULL
struct lnode* init_list_single(struct lnode* L)
{
	static int f = 0;
	struct lnode* re = NULL;
	if (L == NULL)
	{
		re = malloc(sizeof(struct lnode));
	}
	if (re == NULL)
	{
		L = NULL;
		return NULL;
	}
	else
	{
		L = re;
	}
	L->data = f;
	f++;
	L->next = NULL;
	// printf("init ok\n");
	return L;
}
// 打印单个元素的值
// 第一个参数是链表的地址
void list_print_single(struct lnode* L)
{
	printf("number = %d\n", L->data);
	printf("next place = %p\n\n", L->next);
}

// 初始化一个长串的链表
// 第一个参数是链表的地址，要输入NULL，
// 第二个参数是链表的长度
struct lnode* init_list(struct lnode* L, int len)
{
	int i = 0;
	struct lnode* tmp = NULL;
	struct lnode* t = NULL;
	struct lnode* first = init_list_single(L);
	struct lnode* head = first;
	for (i = 0; i < len - 1; i++)
	{
		tmp = init_list_single(t);
		// printf("%p\n", tmp);
		first->next = tmp;	// 前面一个的next,就是下一个的地址
		first = tmp;
	}
	return head;
}

// 打印一整个链表
// 第一个参数是链表元素的首地址，列表最后一个元素的值必须为NULL
// 也可以不为链表的首地址，但长度也会相应的相减
void list_print(struct lnode* head)
{
	int i = 0;
	struct lnode* first = head;
	struct lnode* next = first->next;
	while (first->next != NULL)	// 这里循环次数是len - 1，因为next无法访问 NULL->next
	{
		printf("%d\n", i);
		i++;
		list_print_single(first);
		first = next;
		next = first->next;
	}
	printf("%d\n", i);
	list_print_single(first);
	// 单独出来是因为找不到下一个元素了，
	// 自然没有下一个元素的数据（即下下个地址）
}


// 判断线性表是否为空表
// 或线性表为空表返回ture 1,否则返回false 0
int list_empty(struct lnode L)
{
	;
	return 0;
}

// 将线性表清空,传入线性表的头结点，线性表中的最后一个元素必须为NULL
void list_clear(struct lnode* L)
{
	struct lnode* first = L;
	struct lnode* next = first->next;
	while (first->next != NULL)
	{
		first->data = 0;
		first = next;
		next = first->next;
	}
	first->data = 0;
}

// 将线性表L中的第i个位置元素值返回给e
// 第一个元素是头结点的地址，
// 第二个元素是元素的索引，从0开始
// 第三个参数是要返回值的地址
void get_elem(struct lnode* L, int i, int* e)
{
	int j = 0;
	struct lnode* first = L;
	struct lnode* next = first->next;
	while (j <= i)
	{
		*e = first->data;
		if (first->next == NULL)
		{
			break;
		}
		first = next;
		next = first->next;
		j++;
		// printf("%d\n", j);
	}
	if (j < i)
	{
		*e = 0x7fffffff;
	}
}

// 在线性表L中查找与给定值e相等的元素，
// 如果查找成功，返回元素在表中序号表示成功
// 否则，返回-1表示失败
int locate_elem(struct lnode* L, int e)
{
	struct lnode* first = L;
	struct lnode* next = first->next;
	int i = 0;
	while (1)
	{
		if (first->data == e)
		{
			return i;
		}
		if (first->next == NULL)
		{
			return -1;
		}

		i++;
		first = next;
		next = first->next;
	}
}

// 计算链表的长度
// 输入链表的地址
// 返回链表的长度
int list_len(struct lnode* head)
{
	int i = 0;
	struct lnode* first = head;
	struct lnode* next = first->next;
	while (first->next != NULL)
	{
		i++;
		first = next;
		next = first->next;
		// printf("i=%d\n", i);
	}
	i++;
	return i;
}

// 在线性表L中插入新元素
// 第一个参数是数组的地址
// 第二个参数是插入的位置，索引开始为0
// 第三个参数是插入的元素e
// 如果值过大则在最后插入新元素
// 如果值过小则在最前插入新元素
// 返回添加后链表的起始地址（因为可能添加了头元素）
struct lnode* list_insert(struct lnode* L, int i, int e)
{
	int len = list_len(L);
	if (i < 0)
	{
		i = 0;
	}
	else if (i >= len + 1)	// 防止越界访问
	{
		i = len;
	}
	struct lnode* insert = NULL;
	insert = init_list_single(insert);
	insert->data = e;
	struct lnode* first = L;
	struct lnode* next = first->next;
	struct lnode* front = NULL;
	struct lnode* end = NULL;
	struct lnode* tmp = NULL;
	int j = 0;
	if (i == 0)
	{
		// printf("aaa\n");
		insert->next = L;
		return insert;
	}
	else if (i == len)
	{
		while (first->next != NULL)
		{
			first = next;
			next = first->next;
		}
		// printf("first_place=%p\n", first);
		first->next = insert;
		return L;
	}
	else
	{
		while (first->next->next != NULL)
		{
			if (j >= i - 1)
			{
				break;
			}
			first = next;
			next = first->next;
			
			j++;
		}
		front = first;
		end = first->next;
		// printf("first_place=%p\n", first);
		front->next = insert;
		insert->next = end;
		return L;
	}
	return L;
}

// 删除线性表的元素
// 删除线性表L中第i个位置元素，
// 并用e返回其值
// 第一个参数是链表的地址
// 第一个参数是要删除元素的地址
// 第三个参数是返回的元素e
// 返回删除后的链表起始位置（因为可能删除头元素）
// 如果值过大则在最后一个元素的基础上删除
// 如果值太小则在最前面的一个元素的基础上删除
struct lnode* list_delete(struct lnode* L, int i, int* e)
{
	int len = list_len(L);
	if (len == 0)
	{
		return NULL;
	}
	struct lnode* first = L;
	struct lnode* next = first->next;
	struct lnode* re = NULL;
	struct lnode* tmp = NULL;
	int j = 0;
	// printf("len=%d\n", len);
	// printf("first_place=%d\n", i);
	if (i < 0)
	{
		i = 0;
	}
	else if (i > len - 1)
	{
		i = len - 1;
	}
	// printf("del_place = %d\n", i);
	// list_print(L);
	while (j < i - 1)
	{
		next = first->next;
		first = next;
		j++;
	}
	// printf("first=%p\n", first);
	if (i == 0)
	{
		re = first->next;
		// printf("return_place=%p\n", re);
		*e = first->data;
		free(first);
		first = NULL;
		return re;
	}
	else if ((i > 0) && (i <= len - 1))
	{
		re = L;
		// printf("return_place2=%p\n", re);
		// printf("release_place=%p\n", first);
		*e = first->next->data;
		tmp = first->next;
		// printf("tmp = %p\n", tmp);
		first->next = first->next->next;
		free(tmp);
		tmp = NULL;
		return re;
	}
	else
	{
		return L;
	}
}







