#pragma once


//交换排序
//冒泡排序
//快速排序



//一次冒泡，将最小的交换到第一个
void exchange_sort(int * d, int len) {

	//n个元素，n-1此之后，基本有序
	for (int i = 0; i < len; ++i)	{
		for (int j = len -1; j>0; --j)	{
			if (d[j-1] > d[j]){

				//swap
				int t = d[j];
				d[j] = d[j - 1];
				d[j - 1] = t;

				//完成一次交换
			}
		}
	}
}

//快速排序
//是冒泡排序的优化，采取分治的办法
//个：分一半，每半进行冒泡？
//NOTE：在数组中找到povit点，经过一次排序后，左边的区间小于p，右边区间大于p

//采用清华，总以当前表中的第一个蒜素作为枢轴值，则将表中比p大的放到右边，小的放到左边
int exchange_sort_partition(int * d, int len, int l, int h) {
	int p = d[l]; //枢轴值

	//只要没有遍历完毕，就是l与h之间还是有大小
	while (l < h) {
		//空出l
		//从high往前找，找到比p小的索引
		while (l < h && d[h] >= p) --h;
		//小的放在p左面
		d[l] = d[h];

		//空出h，则从前往后找，找到比p大的索引
		while (l < h && d[l]] <= p) ++l;

		//大的放在p右面
		d[h] = d[l];

	}

	//放置元素存放的最终位置
	d[l] = p;

	return l;
}

