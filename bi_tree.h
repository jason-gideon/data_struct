#pragma once

/*
	�Լ���˼·���ǲ�㣬�����ֱ�Ӹ��ƣ��е�������û�й�����
	�����Լ�Ҫ�ú�˼���£�p117��
*/

#define elem int


typedef struct BiNode bi_tree,bi_node,*pbi_tree;
struct BiNode {
	elem k;
	struct BiNode *lchild, *rchild;
	bool ltag, rtag;

	//��������������������bst��avlɾ�������ͷ�ת����
	//�������ǰ���Ƚ��鷳
	//ltag:
	//		0 lchild��ʾ�ڵ�ĵ�����
	//		1 lchild��ʾ�ڵ��ǰ��,�����ڵ�ΪҶ�ӵ�ʱ��1�Ļ�����ɾ���ڵ�
};

//////////////////InThread������//////////////////////////////////////////////////////////
//��������������(����)
void inthread(pbi_tree&p, pbi_tree& pre);
//��������������(����)
void createinthread(pbi_tree p);


//��ȡ�������������������µĵ�һ���ڵ㣨���򣩣�bstɾ����ʱ��(ɾ�����������:p104)��Ҫʹ��
pbi_tree firstnode(pbi_tree p);
//���������������нڵ�p�����������µĺ�̽ڵ�
pbi_tree nextnode(pbi_tree p);

pbi_tree prenode(pbi_tree p, elem k, pbi_tree &pre);

//�����������������,ʹ�����������������쳣�򵥣���ˣ�
void bithreadtree_inoder(pbi_tree p);




///////////////////BST ����������/////////////////////////////////////////////////////////
//�ݹ�������ݣ�����bst����
//1.������С�ڸ��ڵ�
//2.���������ڸ��ڵ�
int bst_insert(pbi_tree &t, elem k);
int bst_delete(pbi_tree &t, elem k);
void bst_create(pbi_tree &t, elem k[], int n);
//���Ҷ�����������,����bst����
//���ֲ��ң�avlҲ������ô����
pbi_tree bst_search(pbi_tree t, elem k, pbi_tree &p);


//����������
void bitree_preoder(pbi_tree t);
void bitree_inoder(pbi_tree t);
void bitree_postoder(pbi_tree t);
