struct root//��
{
	int number;//��Ԫ��
	int* end;//��̽ڵ�
	int branch_num;//��̽ڵ����
};

struct branch//��֦
{
	int number;//��֦Ԫ��
	int* front;//ǰ���ڵ�
	int* end;//��̽ڵ�
	int branch_num;//��̽ڵ����
};

struct leaf//Ҷ��
{
	int number;//Ҷ��Ԫ��
	int* front;//ǰ���ڵ�
};

struct root_two//�������ĸ�
{
	int number;//Ԫ��
	struct branch_two* left;//�����ֵ
	struct branch_two* right;//�����ֵ
};

struct branch_two//����������֦
{
	int number;//Ԫ��
	struct branch_two* front;//ǰ��Ԫ��
	struct branch_two* left;//�����ֵ
	struct branch_two* right;//�����ֵ
};

struct leaf_two//��������Ҷ��
{
	int number;//Ԫ��
	struct branch_two* front;//ǰ��Ԫ��
};