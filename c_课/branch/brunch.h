struct root//根
{
	int number;//根元素
	int* end;//后继节点
	int branch_num;//后继节点个数
};

struct branch//树枝
{
	int number;//树枝元素
	int* front;//前驱节点
	int* end;//后继节点
	int branch_num;//后继节点个数
};

struct leaf//叶子
{
	int number;//叶子元素
	int* front;//前驱节点
};

struct root_two//二叉树的根
{
	int number;//元素
	struct branch_two* left;//后继左值
	struct branch_two* right;//后继右值
};

struct branch_two//二叉树的树枝
{
	int number;//元素
	struct branch_two* front;//前驱元素
	struct branch_two* left;//后继左值
	struct branch_two* right;//后继右值
};

struct leaf_two//二叉树的叶子
{
	int number;//元素
	struct branch_two* front;//前驱元素
};