#include "bi_tree.h"
#include <malloc.h>
#include <stdio.h>


void visit(pbi_tree t) {
	//static int i = 0;
	printf("k:%d\n", t->k);
}


void inthread(pbi_tree&p, pbi_tree& pre){
	if (p){
		inthread(p->lchild, pre);		//线索化左子树
		if (p->lchild == nullptr){		//左子树为空，则建立前驱线索
			p->lchild = pre;
			p->ltag = true;
		}
		if (pre && pre->rchild == nullptr){ //建立前驱节点的后继线索
			pre->rchild = p;
			pre->rtag = true;
		}
		pre = p;
		inthread(p->rchild, pre);
	}
}

void createinthread(pbi_tree p)
{
	pbi_tree pre = p;
	if (p){						//非空二叉树，线索化
		inthread(p, pre);		//线索化二叉树
		pre->rchild = nullptr;	//处理遍历的最后一个节点
		pre->rtag = true;
	}
}

pbi_tree firstnode(pbi_tree p){
	while (p->ltag == true){ //获取最坐下节点，不一定是叶子节点，有可能只有右子树
		p = p->lchild;
	}
	return p;
}

//思路:
//获取p的后继节点，线索二叉树中规定，如果rchild为null，则该值可以为后继节点，
//如果rchid本身有值，则是另外一棵树，因此还要计算，这个树下的第一个节点

pbi_tree nextnode(pbi_tree p){
	if (p->rtag == false){
		return firstnode(p);   /*如果rchild为一个树，则获取此树的第一个节点*/
	}

	return p->rchild; //如果rchild本身为null，则记录的是后驱
}

pbi_tree prenode(pbi_tree p, elem k, pbi_tree& pre)
{
	if (p){
		//if (p->ltag == false)
		{
			pbi_tree c = prenode(p->lchild, k, p);
		}

		if (p->ltag == false && p->k == k){
			pre = p;
		}
		
		//if (p->rtag == false)
		{
			pbi_tree c = prenode(p->rchild, k, p);
			
		}
	}


// 	pbi_tree pre = p;
// 	prenode(p->lchild, pre);
// 
// 
// 	pbi_tree pre = nullptr;
// 	while (p && p->k != k){
// 		pre = p;
// 		//遍历二叉树
// 	}

	return 0;
}

void bithreadtree_inoder(pbi_tree p)
{
	for (pbi_tree p=firstnode(p); p!=nullptr; nextnode(p)){
		visit(p);
	}
}

int bst_insert(pbi_tree &t, elem k)
{
	/*创建节点*/
	if (t == 0){
		t = (pbi_tree)malloc(sizeof bi_tree);
		t->k = k;
		t->lchild = t->rchild = 0;
		t->ltag = t->rtag = false;
		return 1;
	}
	else if (t && t->k == k){
		return 0;
	} else if (k < t->k ) { //如果input key 应该插入左子树，左子树必须小于root
		return bst_insert(t->lchild, k);
	} else if (k > t->k) {
		return bst_insert(t->rchild, k);
	}
}

int bst_delete(pbi_tree &p, elem k)
{
	/*
	1.如果被删除的是叶子节点，则直接删除，不会破坏二叉排序树的性质
	2.若节点z只有一颗左子树or右子树，则让下一个成为z的父节点的子树，替代z的位置
	3.若节点z有左右两颗子树，则z的直接后继替代z*/
// 	pbi_tree t = p;
// 	for (pbi_tree t = firstnode(t); t!=nullptr;nextnode(t)){
// 		if (t->ltag == true && t->rtag == true) {/*全为叶子节点，则直接删除*/
// 			/*找到前驱*/
// 			pbi_tree parent = t->lchild;
// 			parent->lchild = 
// 		}
// 	}
// 	
// 
// 
// 	
// 	
// 	
// 	
// 
// 	//遍历二叉树
// 	while (t != nullptr && t->k !=k) {
// 
// 		if (t->k == k){
// 			pbi_tree c = t;
// 			/*进行删除*/
// 			if (c->ltag==true && c->rtag==true){
// 				/*全为叶子节点，则直接删除*/
// 
// 			}
// 
// 		}else if (t->k > k) {
// 			t = t->lchild;
// 		} else {
// 			t = t->rchild;
// 		}
// 	}

	return 0;
}

void bst_create(pbi_tree &t, elem k[], int n)
{
	t = nullptr;
	int i = 0;
	while (i < n){
		bst_insert(t, k[i]);
		++i;
	}
}


pbi_tree bst_search(pbi_tree t, elem k, pbi_tree &p)
{
	p = 0;
	while (t && k != t->k){
		p = t;
		//二分查找
		if (t->k > k){
			t = t->lchild;
		}
		else {
			t = t->rchild;
		}
	}
	return t;
}


void bitree_preoder(pbi_tree t)
{
	if (t){
		visit(t);
		bitree_preoder(t->lchild);
		bitree_preoder(t->rchild);
	}
}

void bitree_inoder(pbi_tree t)
{
	if (t) {
		bitree_inoder(t->lchild);
		visit(t);
		bitree_inoder(t->rchild);
	}
}

void bitree_postoder(pbi_tree t)
{
	if (t) {
		bitree_postoder(t->lchild);
		bitree_postoder(t->rchild);
		visit(t);
	}
}

