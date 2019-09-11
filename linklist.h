#pragma once
#include <corecrt_malloc.h>

#define elem int

typedef struct lnode {
	elem d;
	struct lnode* next;
}lnode, *linklist;


linklist linklist_create_with_header(elem * array, int len) {
	//创建头节点
	
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


//p37练习
//1. 设计一个递归算法，删除不带头节点的单链表上所有x的值
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
	//头节点单独处理
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

//2.在带头节点的单链表L中,删除所有值为x的结点



//3.L为带头节点的单链表，编写算法实现从头到尾反向输出每个结点的值
//NOTE:使用递归，或者栈可以实现反转输出
void linklist_revert_print(linklist listl) {
	lnode* p = listl;
	if (p)	{
		linklist_revert_print(p->next);
		printf("%d\n", p->d);
	}
}

//4.编写带头节点的单链表L中删除一个最小值节点的高效算法
//NOTE:先查找最小值，记录pre和p，最后删除
void linklist_del_min(linklist header) {
	lnode* h = header;
	lnode* p = header->next;
	lnode* pre = h;
	lnode* min = p;
	lnode* minpre = pre;
	//查找p值，保留pre
	while (p){
		if (p->d < min->d)	{
			min = p;
			minpre = pre;
		}

		p = p->next;
		pre = pre->next;
	}

	//删除
	if (min&& minpre)	{
		minpre->next = min->next;
		free(min);
	}
}

//5.编解一个带头节点的单链表就地逆置
//NOTE，我们知道逆置可以用头插法，栈也是先进后出的特性
// 因此，可以用头插法和栈的方式
void linklist_revevt(linklist header) {
	//采用头插法
	lnode* h = header;
	lnode* pre = header;
	lnode* p = header->next;
	lnode* m = 0;

	h->next = nullptr;

	//N:断开header与p，遍历p然后用头插法
	//插入到header中
	while (p){
		//遍历p

		lnode* c = p;			//保存c，用于头插，
		p = p->next;			//更新p到下一个
		c->next = 0;			//初始化头插下一个为null

		//采用头插法:
		lnode*lafter = h->next;
		h->next = c;
		c->next = lafter;
	}
}

//6.带头节点单链表，使元素递增有序
//NOTE:单链表的排序问题
// 头断开，然后遍历p，遍历p的同时，遍历头结点新链表，找到要插入的位置，插入
void linklist_sort(linklist header) {
	lnode* h = header;
	lnode* pre = header;
	lnode* p = header->next;
	
	h->next = nullptr;

	while (p){
		lnode* c = p;			//保存c，用于头插，
		p = p->next;

		//查找要插入的位置
		//NOTE: 重点，这里一开始使用了newp->d > c->d，导致排序正好相反... 凸显自己逻辑不清楚，特别是排比的时候
		// newp->d < c->d 为正确的，for完成时，退出的时候，newp为>p的，因此p要插入元素，newp为新队列要比较的，如果
		// newp>p,则说明p应当插入到newp前面，因此满足最下面两句，头插
		lnode* newpre = h;
		for (lnode* newp = h->next; newp != 0 && newp->d < c->d; newp = newp->next, newpre = newpre->next);

		//尾插，找最小值插入到前面
		//找到插入的结点，插入
		c->next = newpre->next;
		newpre->next = c;
	}
}

//7头节点单链表，数值无序，删表中大于最小值，小于最大值
//NOTE:删除时，需要把pre记住
void  linklist_del_between_min_max(linklist header, int min, int max) {
	lnode* h = header;
	lnode* pre = header;
	lnode* p = header->next;

	while (p){
		lnode* c = p;
		p = p->next;
		
		if (min< c->d && c->d < max){		//NOTE:一开始写错误， min > c->d，逻辑混乱，考虑的对象错了，应该以c->d为基准
			//删除
			pre->next = c->next;
			free(c);
			continue;
			//删除后，pre还是下一个pre
		}

		pre = pre->next;
	}
}

//8.两个单链表，找到两个链表的公共结点
//Q：什么是公共结点？指针一样?value一样？

//9. 给定头节点，递增输出单链表个节点数据，并释放所有存储空间。（不用数组做辅助）
//NOTE：先将表排序，然后遍历输出，销毁？
void linklist_increase_print_and_free(linklist header) {
	lnode* h = header;
	lnode* pre = header;
	lnode* p = header->next;

	h->next = 0;

	//进行排序，从小到大
	while (p) {
		lnode* c = p;
		p = p->next;
		c->next = 0;

		lnode* newpre = h;		//NOTE:重要:下面是要找到newpre，就是new>c的pre，因此下面newp->d < c->d是正确的，即只要<就循环！！！
		for (lnode* newp = h->next; newp != 0 && newp->d < c->d /*容易错，逻辑混乱*/; newp = newp->next, newpre = newpre->next);

		c->next = newpre->next;
		newpre->next = c;
	}


	//进行显示和删除
	lnode* q = header->next;
	while (q){
		lnode* c = q;
		q = q->next;

		printf("%d\n", c->d);
		free(c);
	}
}

//10. 头节点，分为a,b链表，a中序号为奇数，b中序号为偶数
void linklist_seprate_odd_list(linklist header) {
	lnode* h = header;
	lnode* pre = header;
	lnode* p = header->next;



}