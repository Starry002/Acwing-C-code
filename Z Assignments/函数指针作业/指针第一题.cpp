#include <iostream>
using namespace std;
int main()
{
	int m,n;
	printf("请输入矩阵的行数和列数\n");
	cin >> m >> n;
	int a[m][n] = {0};
	printf("请输入矩阵\n");
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<m;i++)
	{
		int linesum = 0;
		for(int j=0;j<n;j++) linesum += a[i][j];
		printf("%d\n",linesum);
	}
	return 0;
}

