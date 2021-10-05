#ifndef __link_h__
#define __link_h__

// ����һ����������
struct lnode
{
	int data;
	struct lnode* next;
};


struct lnode* init_list_single(struct lnode* L);// ��ʼ��һ��Ԫ��
void list_print_single(struct lnode* L);// ��ӡ����Ԫ�ص�ֵ
struct lnode* init_list(struct lnode* L, int len);// ��ʼ��һ������������
void list_print(struct lnode* head);// ��ӡһ��������

void list_clear(struct lnode* L);// �����Ա����
void get_elem(struct lnode* L, int i, int* e);
int locate_elem(struct lnode* L, int e);
int list_len(struct lnode* head);// ��������ĳ���
struct lnode* list_insert(struct lnode* L, int i, int e);
#endif