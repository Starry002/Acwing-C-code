//����������A=(a1,a2,a3,����,an)��B=(b1,b2,b3,����,bm)�������������������ai*bj���õ�һ����C��C������n*m��������C���շǵݼ���˳�����򣬲��ҵ���k���ֵ��
//
//Input Format
//�����������������ݡ�
//ÿ��������ݵĵ�һ��������������n(1<=n<=10000),m(1<=m<=10000),k(1<=k<=m*n)��
//�ڶ��а���n��������������ʾA��
//�����а���m��������������ʾB��
//
//Output Format
//ÿ��������ݵĽ��ռһ��
//
//��������
//1 3 3
//1
//3 2 1
//
//3 3 7
//1 2 3
//1 2 3
//�������
//3
//6

#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k;
int a[10010],b[10010];
long long c[100000010];
int main(){
	while(cin >> n >> m >> k)
	{
		int x,i,j,l=0;
		for(i=0;i<n;i++) cin >> a[i];
		for(j=0;j<m;j++) cin >> b[j];
		for(i = 0;i<n;i++)
		{
			for(j = 0;j<m;j++,l++)
			{
				c[l] = a[i] * b[j];
			}
		}
	    sort(c,c+n*m);
		cout << c[k-1] << endl;
	}
	return 0;
}

