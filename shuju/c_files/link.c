#include <stdio.h>
#include "link.h"
#include <malloc.h>
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
	while(first->next != NULL)	// 这里循环次数是len - 1，因为next无法访问 NULL->next
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


//在线性表L中第i个位置插入新元素e TODO
struct lnode* list_insert(struct lnode* L, int i, int e)
{
	int len = list_len(L);
	if (i < 0)
	{
		i = 0;
	}
	else if (i > len)	// 防止越界访问
	{
		i = len;
	}
	
	// printf("len=%d\n", len);
	struct lnode* insert = NULL;
	struct lnode* first = L;
	struct lnode* next = L->next;
	insert = init_list_single(insert);
	struct lnode* front = NULL;
	struct lnode* end = NULL;
	struct lnode* l_return = L;
	int j = 0;
	while ((first->next != NULL) && (i != 0))// 停留在要插入元素的位置
	{
		first = next;
		next = first->next;
		j++;
		if (j >= i - 1)
		{
			break;
		}
	}
	if (first->next == NULL)// 如果是最后一个元素，则直接追加
	{
		first->next = insert;
		insert->data = e;
		insert->next = NULL;
	}
	else if(i > 0)
	{
		// printf("next3=%p\n", first);
		front = first;
		end = first->next;
		// printf("front=%p\n", front);
		// printf("end=%p\n", end);
		insert->next = end;
		// printf("insert next=%p\n", insert->next);
		insert->data = e;
		front->next = insert;
	}
	else if (i == 0)
	{
		end = first;
		// printf("end3=%p\n", end);
		insert->data = e;
		insert->next = end;
		L = insert;
		//printf("L=%p\n", L);
		//printf("L->next=%p\n", L->next);
		//printf("number=%d\n", L->data);
		//printf("next_number=%d\n", L->next->data);
		//list_print(L);
		return L;
		
	}
	return l_return;
}

// 删除线性表L中第i个位置元素，
// 并用e返回其值
void list_delete(struct lnode* L, int i, int* e)
{
	;
}







