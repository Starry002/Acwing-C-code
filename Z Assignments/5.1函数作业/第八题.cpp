#include<stdio.h>
int average_num(int a[],int n)
{
	double age,sum=0;
	int cnt = 0,i;
	for(i=0;i<n;i++) sum += a[i];
	age = sum/n;
	for(i=0;i<n;i++)
		if(a[i]<age) cnt++;
	return cnt;
}
void main()
{
	FILE *fp = fopen("in.txt","r");
	int n,a[100],i,num;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		fscanf(fp,"%d",&a[i]);
	num=average_num(a,n);
	printf("the num is:%d\n",num);
}
