c//Input Format
//测试输入包含若干测试用例，每个测试用例占2行，第1行给出正整数K(< 10000 )，第2行给出K个整数，中间用空格分隔。当K为0时，输入结束，该用例不被处理。
//
//Output Format
//对每个测试用例，在1行里输出最大和、最大连续子序列的第一个和最后一个元素，中间用空格分隔。
//如果最大连续子序列不唯一，则输出序号i和j最小的那个（如输入样例的第2、3组）。
//若所有K个元素都是负数，则定义其最大和为0，输出整个序列的首尾元素。
//输入数据
//6
//-2 11 -4 13 -5 -2
//10
//-10 1 2 3 4 -5 -23 3 7  -21
//6
//5 -8 3 2 5 0
//1
//10
//3
//-1 -5 -2
//3
//-1 0 -2
//0
//输出数据
//20 11 13
//10 1 4
//10 3 5
//10 10 10
//0 -1 -2

//***AC了但是，感觉写的很 low 特判有点多***（待提高） 

#include <iostream>
using namespace std;
int k,a[10010];
int main(){
	while(cin >> k && k)
	{
		bool p=1,p1=0;
		int i,j;
		for(i=0;i<k;i++) 
		{
			cin >> a[i];
			if(a[i]>0) p=0;
			if(a[i]==0) p1=1;
		}
		
		int max=0,x,y;
		for(i=0;i<k;i++)
		{
			int sum = 0;
			for(j=i;j<k;j++)
			{
				sum += a[j];
				if(sum>max)
				{
					x = i,y = j;
					max = sum;
				}
				if(sum == max && i+j<x+y)x = i, y = j;
			}
		}
		if(p&&p1)printf("0 0 0");
		else if(p)printf("0 %d %d",a[0],a[k-1]);
		else printf("%d %d %d",max,a[x],a[y]); 
	}
	return 0;
}




