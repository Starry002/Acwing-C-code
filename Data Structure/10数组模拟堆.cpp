//堆排序 
//输入一个长度为 n 的整数数列，从小到大输出前 m 小的数。

//输入格式
//第一行包含整数 n 和 m。
//第二行包含 n 个整数，表示整数数列。

//输出格式
//共一行，包含 m 个整数，表示整数数列中前 m 小的数。

//数据范围
//1≤m≤n≤105，
//1≤数列中元素≤109

//输入样例：
//5 3
//4 5 1 3 2

//输出样例：
//1 2 3

//第一遍  2022/3/21
//第二遍  2022/3/23
//第三遍  2022/4/2
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int n,m;
int h[N],size;										//用一维数组存下一棵树，根节点为 1 ，左儿子节点为 2*n ， 右儿子节点为 2*n+1 

void down(int u)									//实现 down 操作 （生成大根堆，小数在上） 
{
    int t = u;										//用 t 做中间变量，存储下标 
    if(u*2<=size && h[u*2]<h[t]) t = u*2;			//！！如果左儿子存在（小于size），且值小于 u 节点，让 t 等于左儿子
    if(u*2+1<=size && h[u*2+1]<h[t]) t = u*2+1;		//！！如果右儿子存在（小于size），且值小于 u 节点，让 t 等于右儿子
    if(u!=t)										//如果最终下标 t 不等于当前下标 u  
    {
        swap(h[u],h[t]);							//交换 t 和 u 节点的值 
        down(t);									//递归处理，直到 u 节点的值小于左右儿子的值 
    }
}

void up(int u)										//实现 up 操作（生成大根堆，小数在上） 
{
	while(u/2 && h[u/2]>h[u])						//如果 u 节点存在儿子节点，并且值大于左右儿子的值节点 
	{
		swap(h[u/2],h[u]);							//交换 u 节点与左/右儿子的值
		u /= 2;										//让 u 的下标变为左/右儿子节点的下标
	}
}

int main()
{
    scanf("%d %d",&n,&m);
    size = n;
    
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);		//数组下标从 1 开始！！！！！ ，如果从 0 开始 左儿子也是 0 
    
    for(int i=n/2;i;i--) down(i);					//初始化大根堆，i 从 n/2 开始，是因为后面的没有儿子节点了 
    
    while(m--)										//用大根堆输出堆顶，并重新生成大根堆 
    {
        printf("%d ",h[1]);							//输出大根堆的堆顶，即最小数 
        h[1] = h[size];								//让最后一个元素覆盖堆顶
        size--;										//下标总数减 1 （ 实现堆元素的删除） 
        down(1);									//将放在堆顶的元素 down，重新生成大根堆 
    }
    
    return 0;
}
