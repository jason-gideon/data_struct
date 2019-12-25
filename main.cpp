#include "bi_tree.h"
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include "linklist.h"

#define MAX_ELEM 10

#define TEST


void tree_test() {
	int a[] = { 6, 2, 1,4,3,8,7,11,10, 12 };
	//int a[] = { 6, 2, 1,4,3,8,0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	int * a = new int[MAX_ELEM];
// 	for (int i = 0; i< MAX_ELEM; ++i){
// 		a[i] = i;
// 	}


	pbi_tree h = 0, p = 0;
	int size = sizeof bi_tree;
	//bi_tree* h = (bi_tree*)malloc(sizeof (bi_tree));
	bst_create(h, a, MAX_ELEM);
	createinthread(h);

	pbi_tree pre = h;
	pre = prenode(h, 3, pre);
	//pre = prenode(h, 2, 0);
	//assert(pre->k == 2);



	bitree_preoder(h);
	printf("****************\n");
	bitree_inoder(h);
	printf("****************\n");
	bitree_postoder(h);

}

void link_test() {
	//int datas[] = { 1, 2,3,4,5,6,7,8,9,10 };
	//int datas[] = { 10,9,8,7,6,5,4,3,2,1 };
	int datas[] = { 10,9,6,7,1,3,2,4,8,5 };
	linklist t = 0;
	linklist ll = linklist_create_with_header(datas, 10);
	linklist_print(ll);
	printf("***************\n");


	//linklist_revert_print(ll->next);
	printf("***************\n");

	linklist_increase_print_and_free(ll);
	printf("***************\n");


	linklist_del_between_min_max(ll, 3, 7);
	linklist_print(ll);
	printf("***************\n");


	linklist_sort(ll);
	linklist_print(ll);
	printf("***************\n");



	linklist_revevt(ll);
	linklist_print(ll);
	printf("***************\n");

	linklist_del_min(ll);
	linklist_print(ll);

	printf("***************\n");



	t = linklist_delete_x(ll->next, 1);
	linklist_print(t);

	printf("***************\n");

	t = linklist_delete_x(t, 3);
	linklist_print(t);

	return;
}

int main() {
	//tree_test();

	link_test();

	return 0;
}