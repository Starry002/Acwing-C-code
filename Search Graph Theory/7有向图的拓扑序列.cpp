//给定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。
//请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 ?1。
//若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y 之前，则称 A 是该图的一个拓扑序列。

//输入格式
//第一行包含两个整数 n 和 m。
//接下来 m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y 的有向边 (x,y)。

//输出格式
//共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。
//否则输出 -1。

//数据范围
//1≤n,m≤105

//输入样例：
//3 3
//1 2
//2 3
//1 3

//输出样例：
//1 2 3

//第一遍  2022/04/06
//PS:有向无环图 = 拓扑图
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int n,m;
int h[N],e[N],ne[N],idx;							// h[N]  存储每个单链表的头节点 ，ne[N] 中存储的是图中节点能到达的其他节点（顺序不重要）
int q[N],d[N];										// d[N] 存储每个点的入度（距离/层数） ， q[N] 是队列 

void add(int a,int b)								//给图中的点建边 
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort()										//判断是否是拓扑序列 
{
    int hh = 0 , tt = -1; 
    for(int i=1;i<=n;i++)							//找到所有入度为 0 的点 ，让其入队 
        if(!d[i])
            q[++tt] = i;
            
    while(hh<=tt) 
    {
        int t = q[hh++];							//取出队头元素 
        for(int i = h[t];i!=-1;i=ne[i])				//扩展下一层（按照边来遍历搜索其他节点） 
        {
            int j = e[i];							// j 是图中的节点 （按图中的节点编号来搜，不是按边来搜 ）
            d[j]--;									//删除队头指向 j 的入度 ，长度 - 1  
            if(d[j]==0) q[++tt] = j;				//当 j 的入度为 0 时，入队（修成正果） 
        }
    }
    return tt == n-1;								//如果所有元素都入队（下标从 0 开始 ，因此是 n - 1），满足拓扑序列 ，返回 1 
}

int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);							//初始化表头！ 
    
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);									//建立有向图（单向建边） 
        d[b]++;										//距离（长度） + 1 
    }
    
    if(topsort())									//如果是拓扑序列 直接输出队列中的元素即可 
		for(int i=0;i<n;i++) 
			cout << q[i] << ' ';
    else puts("-1");
    
    return 0;
}
