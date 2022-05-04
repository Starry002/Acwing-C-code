//给定一颗树，树中包含 n 个结点（编号 1～n）和 n-1 条无向边。
//请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。
//重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

//输入格式
//第一行包含整数 n，表示树的结点数。
//接下来 n?1 行，每行包含两个整数 a 和 b，表示点 a 和点 b 之间存在一条边。

//输出格式
//输出一个整数 m，表示将重心删除后，剩余各个连通块中点数的最大值。

//数据范围
//1≤n≤105

//输入样例
//9
//1 2
//1 7
//1 4
//2 8
//2 5
//4 3
//3 9
//4 6

//输出样例：
//4

//第一遍  2022/04/05 
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
const int N = 1e6+10 , M = N * 2;
int h[N],e[N],ne[N],idx;						// h[N]  存储每个单链表的头节点 ，ne[N] 中存储的是图中节点能到达的其他节点（顺序不重要）
bool st[N];										// st[N] 存储图中节点是否被搜过 
int ans = N;									// ans 记录答案（ 删除一个点后，剩余各个连通块点数的最大值中的最小值） 

void add(int a,int b)							//给图中的点建边 
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int u)									//深度优先搜索（按图中的节点编号来搜，不是按边来搜 ） 
{
    st[u] = true;								//标记已经搜过 
    
    int sum = 1 , res = 0;						// sum 记录所有子树连通块中的点数，初始值为 1（包括自身）， res 记录各个连通块点数的最大值） 
    for(int i = h[u]; i !=-1 ;i=ne[i])			//按照边来遍历搜索其他节点 
    {
        int j = e[i];							// j 是图中的节点 
        if(!st[j])								//如果 j 没有被搜过 
        {
            int s = dfs(j);						//搜索 j ，子连通块中的点数为 s 
            res = max(res,s);					//记录 子树连通块 中最大的点数 
            sum += s;							//记录所有子树连通块的总数
        }
    }
    
    res = max(res,n-sum);						//记录 父树与子树中 最大的点数 
    ans = min(ans,res);							//求所有最大连通块点数中的最小值
    return sum;									//返回子树连通块中的点数（ s = dfs(j) ） 
}

int main()
{
    scanf("%d",&n);
    
    memset(h,-1,sizeof h);						//初始化表头！ 
    
    for(int i=0;i<n -1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);						//建立无向图（双向建边）	
    }
    
    dfs(1);										//递归调用，可从任意节点开始（图） 
    printf("%d",ans);
    
    return 0;
}
