#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "link.h"

// ����һ��ѭ������
// ��һ������������ĵ�ַ��ҪΪNULL��
// �ڶ�������������ĳ���
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

// ��ӡѭ���б�
// ��һ���������������Ԫ�ص�ַ
// ��ӡ����Ϊ�б�ĳ��ȣ���һȦ��
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

// ɾ��ѭ�������е�����Ԫ��
// ��һ����ַΪ����������һ��Ԫ�صĵ�ַ
// �������һȦ��ɾ��
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


// ����ѭ���б�ĳ���
// ����Ĳ�����ѭ���б������һ����ַ
// ���ؼ���ѭ���б�ĳ���
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

// ��ѭ���б��в���Ԫ��
// ��һ��������ѭ���б�ĵ�ַ��
// �ڵض��������ǲ���Ԫ�ص�λ��
//		�����λ��Ԫ���±��Ϊ����ֵ����0��ʼ
//		�����Ԫ�ص�λ�û��Զ�ǯ�����б�ĳ���
//		�����ȴ����б�ĳ��ȣ�
//			�Ҳ���Ԫ�ص�λ�����б������������б�ĳ��ȣ�
//			���׵�ַ����,��׷��
//		�����ȴ����б�ĳ��ȣ�
//			�Ҳ���Ԫ�ص�λ�����б�������󲻵����б�ĳ��ȣ�
//			�׵�ַ��Ȼ����
//		������λ������Ϊ0��
//			��Ԫ�ص�ַ�Ż�仯���������µ���Ԫ�ص�ַ
//		������Ԫ��λ���Ƿ����仯�����᷵��ֵ��
//			�����˲���λ��Ϊ0��������⣬�㶼���Բ�����
//			��ʹ�����λ��Ϊ0����û�н��գ�Ҳ���ᱨ��
//			�����ܵ�����������˳�����
// �����������ǲ����Ԫ�ص����ݺ�
// ��ע ������������ж������ȵĺ��������ܵ���Ч�ʱ��
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
	else//�жϲ����λ��
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
	if (place == 0)//���������λ��
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

// ɾ��ѭ�������һ��Ԫ��
// ��һ��������ѭ������ĵ�ַ
// �ڶ���������Ҫɾ��Ԫ�ؾ����ַ��ƫ���������� ��0��ʼ��
//		�������б�����ɾ�����һ��Ԫ��
//		��С���б�����ɾ����ǰ��һ��Ԫ��
// ����һ������ĵ�ַ������ɾ����Ԫ�ص�ַʱ��Ҫ����
//		�����ջᵼ�´���error����
struct lnode* del_clink_single(struct lnode* head, int place)
{
	struct lnode* re = head;
	struct lnode* first = head;
	struct lnode* ne = head->next;
	int len = clink_len(head);// ����ĳ���
	if ((place != 0) && (place >= len))
	{
		place = len - 1;
	}
	int i = 0;
	if (place < 0)
	{
		place = 0;
	}
	if (place == 0)//ɾ������Ԫ�ص�ַ�����
	{
		i = 0;
		while (i < place)
		{
			head = head->next;
			i++;
		}
		i = 0;
		while (i < len - 1)// �����˳��������㷨�д��Ż�
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
	else//һ�����
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





