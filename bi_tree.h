#pragma once

/*
	自己的思路还是差点，大多是直接复制，有的是走神，没有过脑子
	这里自己要好好思考下，p117联
*/

#define elem int


typedef struct BiNode bi_tree,bi_node,*pbi_tree;
struct BiNode {
	elem k;
	struct BiNode *lchild, *rchild;
	bool ltag, rtag;

	//采用线索二叉树，方便bst和avl删除操作和翻转操作
	//否则查找前驱比较麻烦
	//ltag:
	//		0 lchild表示节点的的左孩子
	//		1 lchild表示节点的前驱,当本节点为叶子的时候，1的话可以删除节点
};

//////////////////InThread二叉树//////////////////////////////////////////////////////////
//将二叉树线索化(中序)
void inthread(pbi_tree&p, pbi_tree& pre);
//将二叉树线索化(中序)
void createinthread(pbi_tree p);


//获取线索二叉树中序序列下的第一个节点（中序），bst删除的时候(删除第三种情况:p104)需要使用
pbi_tree firstnode(pbi_tree p);
//中序线索二叉树中节点p在中序序列下的后继节点
pbi_tree nextnode(pbi_tree p);

pbi_tree prenode(pbi_tree p, elem k, pbi_tree &pre);

//中序遍历线索二叉树,使用上面两个方法，异常简单，因此，
void bithreadtree_inoder(pbi_tree p);




///////////////////BST 二叉排序树/////////////////////////////////////////////////////////
//递归插入数据，按照bst性质
//1.左子树小于根节点
//2.右子树大于根节点
int bst_insert(pbi_tree &t, elem k);
int bst_delete(pbi_tree &t, elem k);
void bst_create(pbi_tree &t, elem k[], int n);
//查找二叉树排序树,按照bst性质
//二分查找，avl也可以这么查找
pbi_tree bst_search(pbi_tree t, elem k, pbi_tree &p);


//二叉树遍历
void bitree_preoder(pbi_tree t);
void bitree_inoder(pbi_tree t);
void bitree_postoder(pbi_tree t);
