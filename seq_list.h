#pragma once

//ɾ����С�������ر�ɾԪ�أ��ճ���λ�������һ��Ԫ���
void seq_del_min(int * d, int len) {
	int x = 0;
	for (int i = 0; i < len; ++i) {
		if (d[i] < d[x]) {
			x = i;
		}
	}

	//ɾ��

}

void seq_revert(int * d, int len) {
	for (int i = 0; i > 0; --i) {
		int r = d[i];

	}
}


//11.�������б����λ��
//�����б����λ��
//1.��a=b�������a
//2.��a<b, �����a��ǰ��Σ�b�ĺ���
//3.��a>b,�����a�ĺ��Σ�b��ǰ���

int seq_mid(int a[], int b[], int n) {
	//����a��b����λ����ĩλ������λ��
	int s1 = 0;
	int s2 = 0;

	int e1 = n - 1;
	int e2 = n - 1;

	int mid1 = (s1 + e1) / 2;
	int mid2 = (s2 + e2) / 2;
	
	//
	while (s1 != e1 || s2!=e2)	{
		//��ȡ���η�Χ�ڵ���λ��
		mid1 = (s1 + e1) / 2;
		mid2 = (s2 + e2) / 2;

		if (a[mid1] == b[mid2]){
			//�����λ����Сһ�£������ֵ������λ��
			return a[mid1];
		}
		
		if (a[mid1] < b[mid2]){
			//���a<b������aǰ�棬b����

			if ((s1+e1)%2 == 0){ //ż��
				s1 = mid1 + 1;
				e2 = mid2;
			}
			else
			{
				s1 = mid1; //����
				e2 = mid2;
			}
			


		} else	{
			//���a>b��������a���棬bǰ��
			s2 = mid2;
			e1 = mid1;

		}
	}
}