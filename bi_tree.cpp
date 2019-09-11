#include "bi_tree.h"
#include <malloc.h>
#include <stdio.h>


void visit(pbi_tree t) {
	//static int i = 0;
	printf("k:%d\n", t->k);
}


void inthread(pbi_tree&p, pbi_tree& pre){
	if (p){
		inthread(p->lchild, pre);		//������������
		if (p->lchild == nullptr){		//������Ϊ�գ�����ǰ������
			p->lchild = pre;
			p->ltag = true;
		}
		if (pre && pre->rchild == nullptr){ //����ǰ���ڵ�ĺ������
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
	if (p){						//�ǿն�������������
		inthread(p, pre);		//������������
		pre->rchild = nullptr;	//������������һ���ڵ�
		pre->rtag = true;
	}
}

pbi_tree firstnode(pbi_tree p){
	while (p->ltag == true){ //��ȡ�����½ڵ㣬��һ����Ҷ�ӽڵ㣬�п���ֻ��������
		p = p->lchild;
	}
	return p;
}

//˼·:
//��ȡp�ĺ�̽ڵ㣬�����������й涨�����rchildΪnull�����ֵ����Ϊ��̽ڵ㣬
//���rchid������ֵ����������һ��������˻�Ҫ���㣬������µĵ�һ���ڵ�

pbi_tree nextnode(pbi_tree p){
	if (p->rtag == false){
		return firstnode(p);   /*���rchildΪһ���������ȡ�����ĵ�һ���ڵ�*/
	}

	return p->rchild; //���rchild����Ϊnull�����¼���Ǻ���
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
// 		//����������
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
	/*�����ڵ�*/
	if (t == 0){
		t = (pbi_tree)malloc(sizeof bi_tree);
		t->k = k;
		t->lchild = t->rchild = 0;
		t->ltag = t->rtag = false;
		return 1;
	}
	else if (t && t->k == k){
		return 0;
	} else if (k < t->k ) { //���input key Ӧ�ò���������������������С��root
		return bst_insert(t->lchild, k);
	} else if (k > t->k) {
		return bst_insert(t->rchild, k);
	}
}

int bst_delete(pbi_tree &p, elem k)
{
	/*
	1.�����ɾ������Ҷ�ӽڵ㣬��ֱ��ɾ���������ƻ�����������������
	2.���ڵ�zֻ��һ��������or��������������һ����Ϊz�ĸ��ڵ�����������z��λ��
	3.���ڵ�z������������������z��ֱ�Ӻ�����z*/
// 	pbi_tree t = p;
// 	for (pbi_tree t = firstnode(t); t!=nullptr;nextnode(t)){
// 		if (t->ltag == true && t->rtag == true) {/*ȫΪҶ�ӽڵ㣬��ֱ��ɾ��*/
// 			/*�ҵ�ǰ��*/
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
// 	//����������
// 	while (t != nullptr && t->k !=k) {
// 
// 		if (t->k == k){
// 			pbi_tree c = t;
// 			/*����ɾ��*/
// 			if (c->ltag==true && c->rtag==true){
// 				/*ȫΪҶ�ӽڵ㣬��ֱ��ɾ��*/
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
		//���ֲ���
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

