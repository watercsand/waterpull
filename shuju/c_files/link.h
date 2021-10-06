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
void get_elem(struct lnode* L, int i, int* e);// 将线性表L中的第i个位置元素值返回给e
int locate_elem(struct lnode* L, int e);// 在线性表L中查找与给定值e相等的元素，
int list_len(struct lnode* head);// 计算链表的长度
struct lnode* list_insert(struct lnode* L, int i, int e);// 在线性表L中插入新元素
struct lnode* list_delete(struct lnode* L, int i, int* e);// 删除线性表的元素
void list_del_all(struct lnode* head);// 删除链表的所有元素
#endif