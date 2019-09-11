#pragma once
#include <corecrt_malloc.h>

#define elem int

typedef struct lnode {
	elem d;
	struct lnode* next;
}lnode, *linklist;


linklist linklist_create_with_header(elem * array, int len) {
	//����ͷ�ڵ�
	
	lnode* h = (lnode*)malloc(sizeof lnode);
	h->d = -1;
	h->next = 0;
	lnode* n = h;

	for (int i = 0; i < len; ++i){
		lnode* c = (lnode*)malloc(sizeof lnode);
		c->d = array[i];
		c->next = 0;

		n->next = c;
		n = n->next;
	}
	return h;
}

void linklist_print(linklist lis) {
	//lnode* p = lis->next;
	lnode* p = lis;
	while (p){
		printf(" %d\n", p->d);
		p = p->next;
	}
}


//p37��ϰ
//1. ���һ���ݹ��㷨��ɾ������ͷ�ڵ�ĵ�����������x��ֵ
linklist linklist_delete_x_rec(lnode *non_header, int x) {
	lnode* pre = non_header;
	lnode*p = 0;
	if (pre && pre->next){
		p = pre->next;
		if (p->d == x){

		}
	}
	return 0;
}

linklist linklist_delete_x(lnode *non_header, int x) {
	lnode* pre = non_header;
	lnode* p = non_header;
	//ͷ�ڵ㵥������
	if (p && p->d == x){
		non_header = p->next;
		free(p);
		return non_header;
	}
	
	p = p->next;
	while (p){
		if (p->d == x) {
			lnode* del = p;
			pre->next = p->next;
			p = p->next;

			free(del);
			continue;
		}

		p = p->next;
		pre = pre->next;
	}

	return non_header;
}

//2.�ڴ�ͷ�ڵ�ĵ�����L��,ɾ������ֵΪx�Ľ��



//3.LΪ��ͷ�ڵ�ĵ�������д�㷨ʵ�ִ�ͷ��β�������ÿ������ֵ
//NOTE:ʹ�õݹ飬����ջ����ʵ�ַ�ת���
void linklist_revert_print(linklist listl) {
	lnode* p = listl;
	if (p)	{
		linklist_revert_print(p->next);
		printf("%d\n", p->d);
	}
}

//4.��д��ͷ�ڵ�ĵ�����L��ɾ��һ����Сֵ�ڵ�ĸ�Ч�㷨
//NOTE:�Ȳ�����Сֵ����¼pre��p�����ɾ��
void linklist_del_min(linklist header) {
	lnode* h = header;
	lnode* p = header->next;
	lnode* pre = h;
	lnode* min = p;
	lnode* minpre = pre;
	//����pֵ������pre
	while (p){
		if (p->d < min->d)	{
			min = p;
			minpre = pre;
		}

		p = p->next;
		pre = pre->next;
	}

	//ɾ��
	if (min&& minpre)	{
		minpre->next = min->next;
		free(min);
	}
}

//5.���һ����ͷ�ڵ�ĵ�����͵�����
//NOTE������֪�����ÿ�����ͷ�巨��ջҲ���Ƚ����������
// ��ˣ�������ͷ�巨��ջ�ķ�ʽ
void linklist_revevt(linklist header) {
	//����ͷ�巨
	lnode* h = header;
	lnode* pre = header;
	lnode* p = header->next;
	lnode* m = 0;

	h->next = nullptr;

	//N:�Ͽ�header��p������pȻ����ͷ�巨
	//���뵽header��
	while (p){
		//����p

		lnode* c = p;			//����c������ͷ�壬
		p = p->next;			//����p����һ��
		c->next = 0;			//��ʼ��ͷ����һ��Ϊnull

		//����ͷ�巨:
		lnode*lafter = h->next;
		h->next = c;
		c->next = lafter;
	}
}

//6.��ͷ�ڵ㵥����ʹԪ�ص�������
//NOTE:���������������
// ͷ�Ͽ���Ȼ�����p������p��ͬʱ������ͷ����������ҵ�Ҫ�����λ�ã�����
void linklist_sort(linklist header) {
	lnode* h = header;
	lnode* pre = header;
	lnode* p = header->next;
	
	h->next = nullptr;

	while (p){
		lnode* c = p;			//����c������ͷ�壬
		p = p->next;

		//����Ҫ�����λ��
		//NOTE: �ص㣬����һ��ʼʹ����newp->d > c->d���������������෴... ͹���Լ��߼���������ر����űȵ�ʱ��
		// newp->d < c->d Ϊ��ȷ�ģ�for���ʱ���˳���ʱ��newpΪ>p�ģ����pҪ����Ԫ�أ�newpΪ�¶���Ҫ�Ƚϵģ����
		// newp>p,��˵��pӦ�����뵽newpǰ�棬����������������䣬ͷ��
		lnode* newpre = h;
		for (lnode* newp = h->next; newp != 0 && newp->d < c->d; newp = newp->next, newpre = newpre->next);

		//β�壬����Сֵ���뵽ǰ��
		//�ҵ�����Ľ�㣬����
		c->next = newpre->next;
		newpre->next = c;
	}
}

//7ͷ�ڵ㵥������ֵ����ɾ���д�����Сֵ��С�����ֵ
//NOTE:ɾ��ʱ����Ҫ��pre��ס
void  linklist_del_between_min_max(linklist header, int min, int max) {
	lnode* h = header;
	lnode* pre = header;
	lnode* p = header->next;

	while (p){
		lnode* c = p;
		p = p->next;
		
		if (min< c->d && c->d < max){		//NOTE:һ��ʼд���� min > c->d���߼����ң����ǵĶ�����ˣ�Ӧ����c->dΪ��׼
			//ɾ��
			pre->next = c->next;
			free(c);
			continue;
			//ɾ����pre������һ��pre
		}

		pre = pre->next;
	}
}

//8.�����������ҵ���������Ĺ������
//Q��ʲô�ǹ�����㣿ָ��һ��?valueһ����

//9. ����ͷ�ڵ㣬���������������ڵ����ݣ����ͷ����д洢�ռ䡣������������������
//NOTE���Ƚ�������Ȼ�������������٣�
void linklist_increase_print_and_free(linklist header) {
	lnode* h = header;
	lnode* pre = header;
	lnode* p = header->next;

	h->next = 0;

	//�������򣬴�С����
	while (p) {
		lnode* c = p;
		p = p->next;
		c->next = 0;

		lnode* newpre = h;		//NOTE:��Ҫ:������Ҫ�ҵ�newpre������new>c��pre���������newp->d < c->d����ȷ�ģ���ֻҪ<��ѭ��������
		for (lnode* newp = h->next; newp != 0 && newp->d < c->d /*���״��߼�����*/; newp = newp->next, newpre = newpre->next);

		c->next = newpre->next;
		newpre->next = c;
	}


	//������ʾ��ɾ��
	lnode* q = header->next;
	while (q){
		lnode* c = q;
		q = q->next;

		printf("%d\n", c->d);
		free(c);
	}
}

//10. ͷ�ڵ㣬��Ϊa,b����a�����Ϊ������b�����Ϊż��
void linklist_seprate_odd_list(linklist header) {
	lnode* h = header;
	lnode* pre = header;
	lnode* p = header->next;



}