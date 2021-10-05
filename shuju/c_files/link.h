#ifndef __link_h__
#define __link_h__

// 创建一个链表类型
struct lnode
{
	int data;
	struct lnode* next;
};


struct lnode* init_list_single(struct lnode* L);// 初始化一个元素
void list_print_single(struct lnode* L);// 打印单个元素的值
struct lnode* init_list(struct lnode* L, int len);// 初始化一个长串的链表
void list_print(struct lnode* head);// 打印一整个链表

void list_clear(struct lnode* L);// 将线性表清空
void get_elem(struct lnode* L, int i, int* e);
int locate_elem(struct lnode* L, int e);
int list_len(struct lnode* head);// 计算链表的长度
struct lnode* list_insert(struct lnode* L, int i, int e);
#endif