//汉诺塔原型：求最少移动多少次能将所有塔从 a 移动到 b

//汉诺塔来源于印度传说的一个故事，上帝创造世界时作了三个金刚石柱子，在一根柱子上从上往下，
//按从小到大顺序摞着64片黄金圆盘，上帝命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上，
//并且规定，在小圆盘上不能放大圆盘，在三根柱子之间每次只能移动一个圆盘，只能移动在最顶端的圆盘。

#include <iostream>
using namespace std;
int cnt;
int hno (int a)
{
	if(a==1)return ++cnt;			//***初始条件*** 
	return hno(a-1)*2+1;			//***递归关系*** 
}
int main()
{
	int n;
	scanf("%d",&n);
	int sum;
	sum = hno(n);
	printf("%d",sum);
	return 0;
}


//***汉诺塔变型： k 号盘从 a 移动到 b 时，移动所有盘子的次数

//我们用 1，2，...，n 表示 n个盘子的编号，编号越大盘子就越大。
//在移动过程中，有的圆盘移动次数多，有的少。告知盘子总数和盘号，计算该盘子的移动次数。
 
// low 变型 找规律直接写
// 	n  k  ans  sum
// 	1  1   1    1 

//  2  1   2    3 
//  2  2   1 	3

//  3  1   4    7
//  3  2   2    7
//  3  3   1    7

#include <iostream>
using namespace std;
long long p(int n,int m)
{
	long long i,sum=1;
	for(i=0;i<m;i++)
	{
		sum *= n;
	}
	return sum;
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	printf("%lld",p(2,(n-k)));
	return 0;
}

 
 

