#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <Windows.h>
#include "brunch.h"

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

// �������������ȡ��
// ��һ�����ǻ������ڶ�����������
// ��������ȡ����ֵ
int log_floor(int base, int number)
{
	int result = (int)floor(log(number) / log(base));
	return result;
}

// ������ȫ�����������
// ����Ϊ�ڵ�ĸ���
// ������ȫ��������������
int get_completely_tree_deep(int node)
{
	int base = 2;
	int result = log_floor(base, node);
	result++;
	return result;
}

//����˷�
// ��һ�������ǵ������ڶ���������ָ��
int factorial(int base, int num)
{
	int i = 0;
	if (num == 0)
	{
		return 1;
	}
	else if (num < 0)
	{
		return 0;
	}
	int result = 1;
	for (i = 1; i <= num; i++)
	{
		result *= base;
	}
	return result;
}

// ��ʼ����������
// ������Ҫ�Ķ��������
struct branch_two* init_full_tree(int deep)
{
	if (deep <= 0)
	{
		deep = 1;
	}
	int tree_size[3] = { 0, 0, 0 };
	int gift = 1;
	int sum_size = 0;
	struct branch_two* r = NULL;
	struct branch_two* father = NULL;
	struct branch_two* child_left = NULL;
	struct branch_two* child_right = NULL;
	if (deep >= 3)//�и��ڵ�,����֦����Ҷ��
	{
		tree_size[0] = sizeof(struct branch_two);
		tree_size[1] = sizeof(struct branch_two) *(factorial(2, deep - 1) - 2);
		tree_size[2] = sizeof(struct branch_two)*factorial(2, deep - 1);
	}
	else if (deep == 2)//�и��ڵ㣬��Ҷ��
	{
		tree_size[0] = sizeof(struct branch_two);
		tree_size[1] = 0;
		tree_size[2] = sizeof(struct branch_two) * 2;
	}
	else
	{
		tree_size[0] = sizeof(struct branch_two);
		tree_size[1] = 0;
		tree_size[2] = 0;
	}
	sum_size = tree_size[0] + tree_size[1] + tree_size[2];
	
	// printf("root = %d\n", tree_size[0]);
	// printf("branch = %d\n", tree_size[1]);
	// printf("leaf = %d\n", tree_size[2]);
	// printf("size = %d\n", sum_size);
	r = malloc(sum_size);
	if (r == NULL)
	{
		return NULL;
	}
	int i = 0;
	int j = 0;
	int layer_number = 0;
	int max_number = factorial(2, deep) - 1;
	int move = 0;
	for (i = 0; i < deep; i++)
	{
		layer_number = factorial(2, i);
		for (j = 0; j < layer_number; j++)
		{
			// printf("move = %d\n", move);
			if (i < deep - 1)//���ú�̽ڵ�
			{
				child_left = r + move * 2 + 1;//���ӽڵ�ƫ����
				child_right = r + move * 2 + 2;//���ӽڵ�ƫ����;
				(r + move)->left = child_left;
				(r + move)->right = child_right;
			}
			else if(i >= deep - 1)//Ҷ�ӽڵ��޺��Ԫ��
			{
				child_left = NULL;
				child_right = NULL;
				(r + move)->left = child_left;
				(r + move)->right = child_right;
			}
			if (move != 0)//����ǰ���ڵ�
			{
				father = r + (int)(move - 1)/2;//���ڵ�ƫ����
				(r + move)->front = father;
			}
			else if(move == 0)
			{
				father = NULL;
				(r + move)->front = father;
			}
			(r + move)->number = move + 1;
			move = layer_number + j;
		}
	}
	return r;
}

// �õ�����������������
// ����һ����������root�ڵ�
// ���ض�������������
int get_full_tree_layers(struct branch_two* head)
{
	int layer = 0;
	struct branch_two* copy = head;
	while (copy->left != NULL)
	{
		// printf("place = %p\n", copy);
		copy = copy->left;
		layer++;
	}
	layer++;
	return layer;
}

// ��ӡ������֦�ڵ�
// ����һ����֦�ڵ�ĵ�ַ
void print_branch(struct branch_two* node)
{
	printf("number-------> %d\n", node->number);
	printf("front--------> %p\n", node->front);
	printf("child_left---> %p\n", node->left);
	printf("child_right--> %p\n", node->right);
	printf("myself_place-> %p\n", node);
}

// ��ӡһ�������Ŀո�
// ����Ҫ��ӡ�Ŀո�ĸ���
void print_space(int space_number)
{
	int i = 0;
	int number = (int)space_number / 5;//������ӡ����
	int other = space_number % 5;
	for (i = 0; i < number; i++)
	{
		printf("     ");
	}
	for (i = 0; i < other; i++)
	{
		printf(" ");
	}
}

// ��ӡһ�������ĺ���
// ����Ҫ��ӡ�ĺ��߸���
void print_line(int line_number)
{
	int i = 0;
	int eight_number = (int)line_number / 8;
	int other = line_number % 8;
	for (i = 0; i < eight_number; i ++ )
	{
		printf("--------");
	}
	for (i = 0; i < other; i++)
	{
		printf("-");
	}
}

// ��ӡ��������
// ����һ��root�ڵ�
void print_full_tree(struct branch_two* head)
{
	struct branch_two* copy = head;
	struct branch_two* each_branch = NULL;
	int layers = 0;
	layers = get_full_tree_layers(copy);
	printf("layers = %d\n", layers);
	int i = 0;
	int j = 0;
	int k = 0;
	int number_len = 8;
	int space_len = 2;
	int branch_len = 0;//
	int each_number = 0;
	char space_char = ' ';
	char branch_char = '-';
	int move = 0;
	int space_number = factorial(2, layers - 1) * 16;
	int flag = 0;
	for (i = 0; i < layers; i++)
	{
		each_number = factorial(2, i);
		// printf("%d\n", each_number);
		for (j = 0; j < each_number; j++)
		{
			
			move = each_number + j - 1;
			// printf("move = %d\n", move);
			each_branch = copy + move;
			if (j > 0)
			{
				print_space(space_number);
			}
			print_space(space_number - 16);
			printf("number=%-8d ", each_branch->number);
		}
		printf("\n");
		for (j = 0; j < each_number; j++)
		{
			
			move = each_number + j - 1;
			each_branch = copy + move;
			if (j > 0)
			{
				print_space(space_number);
			}
			print_space(space_number - 16);
			printf("front=%p  ", each_branch->front);
		}
		printf("\n");
		for (j = 0; j < each_number; j++)
		{
			
			move = each_number + j - 1;
			each_branch = copy + move;
			if (j > 0)
			{
				print_space(space_number);
			}
			print_space(space_number - 16);
			printf("left=%p   ", each_branch->left);
		}
		printf("\n");
		for (j = 0; j < each_number; j++)
		{
			
			move = each_number + j - 1;
			each_branch = copy + move;
			if (j > 0)
			{
				print_space(space_number);
			}
			print_space(space_number - 16);
			printf("right=%p  ", each_branch->right);
		}
		printf("\n");
		for (j = 0; j < each_number; j++)
		{
			move = each_number + j - 1;
			each_branch = copy + move;
			if (j > 0)
			{
				print_space(space_number);
			}
			print_space(space_number - 16);
			printf("myself=%p ", each_branch);
		}
		printf("\n");
		if (i < layers - 1)
		{
			for (j = 0; j < each_number; j++)
			{
				if (j > 0)
				{
					print_space(space_number*2 - 1);
				}
				if (j == 0)
				{
					print_space(space_number - 9);
				}
				printf("|");
			}
			printf("\n");
			print_space(space_number / 2 - 8);
			for (j = 0; j < each_number; j++)
			{
				print_line(space_number + 1);
				print_space(space_number - 1);
			}
			printf("\n");
			for (j = 0; j <= each_number; j++)
			{
				if (j > 0)
				{
					print_space(space_number - 1);
					printf("|");
					print_space(space_number - 1);
					if (j != each_number)
					{
						printf("|");
					}
				}
				if (j == 0)
				{
					print_space(space_number/2 - 8);
					printf("|");
				}
			}
			printf("\n");
		}
		space_number = space_number / 2;
	}
}

void free_full_tree(struct branch_two* head)
{
	free(head);
	head = NULL;
}



// �ж��Ƿ�Ϊ��������
// �Ƿ���1���񷵻�0
// ����root�ڵ�
int is_full_tree(struct root* r)
{
	return 0;
}

// �ж��Ƿ�Ϊ��ȫ������
// �Ƿ���1���񷵻�0
// ����root�ڵ�
int is_completely_tree(struct root* r)
{
	return 0;
}