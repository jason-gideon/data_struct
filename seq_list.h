#pragma once

//删除最小，并返回被删元素，空出的位置由最后一个元素填补
void seq_del_min(int * d, int len) {
	int x = 0;
	for (int i = 0; i < len; ++i) {
		if (d[i] < d[x]) {
			x = i;
		}
	}

	//删除

}

void seq_revert(int * d, int len) {
	for (int i = 0; i > 0; --i) {
		int r = d[i];

	}
}


//11.找两个列表的中位数
//两个列表的中位数
//1.若a=b，则就是a
//2.若a<b, 则忽略a的前半段，b的后半段
//3.若a>b,则忽略a的后半段，b的前半段

int seq_mid(int a[], int b[], int n) {
	//序列a，b的首位数，末位数，中位数
	int s1 = 0;
	int s2 = 0;

	int e1 = n - 1;
	int e2 = n - 1;

	int mid1 = (s1 + e1) / 2;
	int mid2 = (s2 + e2) / 2;
	
	//
	while (s1 != e1 || s2!=e2)	{
		//获取本次范围内的中位数
		mid1 = (s1 + e1) / 2;
		mid2 = (s2 + e2) / 2;

		if (a[mid1] == b[mid2]){
			//如果中位数大小一致，则这个值就是中位数
			return a[mid1];
		}
		
		if (a[mid1] < b[mid2]){
			//如果a<b则，舍弃a前面，b后面

			if ((s1+e1)%2 == 0){ //偶数
				s1 = mid1 + 1;
				e2 = mid2;
			}
			else
			{
				s1 = mid1; //奇数
				e2 = mid2;
			}
			


		} else	{
			//如果a>b，则舍弃a后面，b前面
			s2 = mid2;
			e1 = mid1;

		}
	}
}