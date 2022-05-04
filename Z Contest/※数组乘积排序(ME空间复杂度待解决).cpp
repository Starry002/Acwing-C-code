//给定两组数A=(a1,a2,a3,……,an)和B=(b1,b2,b3,……,bm)。将这两组数两两相乘ai*bj，得到一组数C，C共包含n*m个数。对C按照非递减的顺序排序，并找到第k大的值。
//
//Input Format
//输入包含多组测试数据。
//每组测试数据的第一行有三个整数：n(1<=n<=10000),m(1<=m<=10000),k(1<=k<=m*n)。
//第二行包含n个整数，用来表示A。
//第三行包含m个整数，用来表示B。
//
//Output Format
//每组测试数据的结果占一行
//
//输入数据
//1 3 3
//1
//3 2 1
//
//3 3 7
//1 2 3
//1 2 3
//输出数据
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

