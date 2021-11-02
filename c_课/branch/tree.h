#ifndef __tree_h__
#define __tree_h__
int get_completely_tree_deep(int node);
struct branch_two* init_full_tree(int deep);
void print_full_tree(struct branch_two* head);
void free_full_tree(struct branch_two* head);

#endif