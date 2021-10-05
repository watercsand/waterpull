#include <stdio.h>
#include "link.h"
#include <malloc.h>
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
	while(first->next != NULL)	// ����ѭ��������len - 1����Ϊnext�޷����� NULL->next
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


//�����Ա�L�е�i��λ�ò�����Ԫ��e TODO
struct lnode* list_insert(struct lnode* L, int i, int e)
{
	int len = list_len(L);
	if (i < 0)
	{
		i = 0;
	}
	else if (i > len)	// ��ֹԽ�����
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
	while ((first->next != NULL) && (i != 0))// ͣ����Ҫ����Ԫ�ص�λ��
	{
		first = next;
		next = first->next;
		j++;
		if (j >= i - 1)
		{
			break;
		}
	}
	if (first->next == NULL)// ��������һ��Ԫ�أ���ֱ��׷��
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

// ɾ�����Ա�L�е�i��λ��Ԫ�أ�
// ����e������ֵ
void list_delete(struct lnode* L, int i, int* e)
{
	;
}







