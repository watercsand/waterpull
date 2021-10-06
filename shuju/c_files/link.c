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

// ��ʼ��һ��Ԫ��
// ��һ�������Ǵ���ĵ�ַ������ҪΪNULL
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
// ��ӡ����Ԫ�ص�ֵ
// ��һ������������ĵ�ַ
void list_print_single(struct lnode* L)
{
	printf("number = %d\n", L->data);
	printf("next place = %p\n\n", L->next);
}

// ��ʼ��һ������������
// ��һ������������ĵ�ַ��Ҫ����NULL��
// �ڶ�������������ĳ���
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
		first->next = tmp;	// ǰ��һ����next,������һ���ĵ�ַ
		first = tmp;
	}
	return head;
}

// ��ӡһ��������
// ��һ������������Ԫ�ص��׵�ַ���б����һ��Ԫ�ص�ֵ����ΪNULL
// Ҳ���Բ�Ϊ������׵�ַ��������Ҳ����Ӧ�����
void list_print(struct lnode* head)
{
	int i = 0;
	struct lnode* first = head;
	struct lnode* next = first->next;
	while (first->next != NULL)	// ����ѭ��������len - 1����Ϊnext�޷����� NULL->next
	{
		printf("%d\n", i);
		i++;
		list_print_single(first);
		first = next;
		next = first->next;
	}
	printf("%d\n", i);
	list_print_single(first);
	// ������������Ϊ�Ҳ�����һ��Ԫ���ˣ�
	// ��Ȼû����һ��Ԫ�ص����ݣ������¸���ַ��
}


// �ж����Ա��Ƿ�Ϊ�ձ�
// �����Ա�Ϊ�ձ���ture 1,���򷵻�false 0
int list_empty(struct lnode L)
{
	;
	return 0;
}

// �����Ա����,�������Ա��ͷ��㣬���Ա��е����һ��Ԫ�ر���ΪNULL
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

// �����Ա�L�еĵ�i��λ��Ԫ��ֵ���ظ�e
// ��һ��Ԫ����ͷ���ĵ�ַ��
// �ڶ���Ԫ����Ԫ�ص���������0��ʼ
// ������������Ҫ����ֵ�ĵ�ַ
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

// �����Ա�L�в��������ֵe��ȵ�Ԫ�أ�
// ������ҳɹ�������Ԫ���ڱ�����ű�ʾ�ɹ�
// ���򣬷���-1��ʾʧ��
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

// ��������ĳ���
// ��������ĵ�ַ
// ��������ĳ���
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

// �����Ա�L�в�����Ԫ��
// ��һ������������ĵ�ַ
// �ڶ��������ǲ����λ�ã�������ʼΪ0
// �����������ǲ����Ԫ��e
// ���ֵ����������������Ԫ��
// ���ֵ��С������ǰ������Ԫ��
// ������Ӻ��������ʼ��ַ����Ϊ���������ͷԪ�أ�
struct lnode* list_insert(struct lnode* L, int i, int e)
{
	int len = list_len(L);
	if (i < 0)
	{
		i = 0;
	}
	else if (i >= len + 1)	// ��ֹԽ�����
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

// ɾ�����Ա��Ԫ��
// ɾ�����Ա�L�е�i��λ��Ԫ�أ�
// ����e������ֵ
// ��һ������������ĵ�ַ
// ��һ��������Ҫɾ��Ԫ�صĵ�ַ
// �����������Ƿ��ص�Ԫ��e
// ����ɾ�����������ʼλ�ã���Ϊ����ɾ��ͷԪ�أ�
// ���ֵ�����������һ��Ԫ�صĻ�����ɾ��
// ���ֵ̫С������ǰ���һ��Ԫ�صĻ�����ɾ��
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







