#pragma once

#define elem int
//插入排序
//直接插入排序,
//折半插入排序
//shell排序


//直接插入排序
void sort_insert(int *d, int len) {
	//一次遍历找最小的，放到最开始
	//然后循环

	for (int i = 2; i < len;++i){
		if (d[i - 1] > d[i])	{			//前后比较
			d[0] = d[i];		//拷贝到哨兵
			for (int j = i - 1; d[j] > d[0];--j){ //从后往前遍历，进行移位
				d[j + 1] = d[j];
			}

			d[j] = d[0];
		}
	}
}


//存在3处疑点，没有想明白
// 折半排序
//本身是有序顺序表
//通过折半查找要插入的位置
//移位
void sort_bi_insert(int * d, int len) {
	for (int i = 2; i < len; ++i){
		int h = i - 1; //NOTE: h为for的范围内!! 
		int l = 1;
		int mid = 0;

		d[0] = d[i];


		//对折半查找到之后的high与low没有深入思考
		//high应该是 <low 或者==low
		//折半查找
		while (h>=l){ //NOTE: h>=l
			mid = (h - l) / 2;
			if (d[0] > d[mid]){ //在后半段找
				l = mid + 1;
			} else {
				h = mid - 1;
			}
		}

		//NOTE:这里为什么要用h做索引？
		//h应当是要插入的位置有关，下面对该插入的位置今昔
		//h+1，因此，我个人认为应该是 while(h >=l)这条判断
		//如果推出，说明h < l ,说明，h位置的值应该< l位置的值
		//因此，这里要替换h+1


		//for (int j = i - 1; d[mid] > d[0]; --j) {//NOTE: 错误，
		for (int j = i -1				/*这里的-1，是为了下面的+1做准备*/
			; j >= h + 1; --j){		//移动位置
			d[j + 1] = d[j];
		}

		//d[mid] = d[0]; //NOTE: 错误
		d[h + 1] = d[0];
	}
}

// shell排序
//对直接插入算法的优化
//取步长d为集合，在子集合中先有序，再最后排一次序
void sort_shell(int * d, int len) {
	for (int k = len / 2; k > 0;k=k/2){			//以步长为k分组,shell一般采用k=k/2，直到k为1
		//NOTE:为什么 i = k+1?
		for (int i = k+1; len > i; ++i)	{		//保证步长内的组是有序的 d[i+nk]
			
			//子表内比较
			if (d[i - k] > d[i]){ //位置异常

				//移位，插入，如顺序插入法一直
				d[0] = d[i];
				for (int j = i - k; j >0 && d[0] < d[j]; j-=k){
					d[j + k] = d[j];
				}
				d[j + k] = d[0];
			}
		}
	}
}

//交换排序
