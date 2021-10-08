#ifndef __clink_h__
#define __clink_h__
struct lnode* init_clink(struct lnode* head, int len);// ����һ��ѭ������
void clink_print(struct lnode* start);// ��ӡѭ���б�
void del_clink(struct lnode* start);// ɾ��ѭ�������е�����Ԫ��
int clink_len(struct lnode* start);// ����ѭ���б�ĳ���
struct lnode* insert_clink(struct lnode* insert, int place, int number);// ��ѭ���б��в���Ԫ��
struct lnode* del_clink_single(struct lnode* head, int place);
int clink_index(struct lnode* head, int number);








#endif