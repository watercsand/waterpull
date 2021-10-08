#ifndef __clink_h__
#define __clink_h__
struct lnode* init_clink(struct lnode* head, int len);// 创建一个循环链表
void clink_print(struct lnode* start);// 打印循环列表
void del_clink(struct lnode* start);// 删除循环链表中的所有元素
int clink_len(struct lnode* start);// 计算循环列表的长度
struct lnode* insert_clink(struct lnode* insert, int place, int number);// 在循环列表中插入元素
struct lnode* del_clink_single(struct lnode* head, int place);
int clink_index(struct lnode* head, int number);








#endif