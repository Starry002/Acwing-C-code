//给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环。
//所有边的长度都是 1，点的编号为 1～n。
//请你求出 1 号点到 n 号点的最短距离，如果从 1 号点无法走到 n 号点，输出 ?1。

//输入格式
//第一行包含两个整数 n 和 m。
//接下来 m 行，每行包含两个整数 a 和 b，表示存在一条从 a 走到 b 的长度为 1 的边。

//输出格式
//输出一个整数，表示 1 号点到 n 号点的最短距离。

//数据范围
//1≤n,m≤105

//输入样例：
//4 5
//1 2
//2 3
//3 4
//1 3
//1 4

//输出样例：
//1

//第一遍  2022/04/06
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5+10;
int n,m;
int h[N],e[N],ne[N],idx;						// h[N] 存储每个单链表的头节点 ，ne[N] 中存储的是图中节点能到达的其他节点（顺序不重要）
int d[N],q[N];									// d[N] 存储每个点的距离（层数） ， q[N] 是队列 

void add(int a,int b)							//给图中的点建边 
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs()										//宽度优先搜索（按图中的节点编号来搜，不是按边来搜 ）  
{
    int hh = 0 , tt  = 0;						// tt = 0 是因为当前队列中已经插入了一个元素（ q[0] = 1 ) 
    memset(d,-1,sizeof d);						//初始化距离！ 
    q[0] = 1 , d[1] = 0;						//从 1 开始扩展 ，1 的层数为 0 
    
    while(hh <= tt)
    {
        int t = q[hh++];						//取出队头元素 
        for(int i=h[t];i!=-1;i=ne[i])			//扩展下一层（按照边来遍历搜索其他节点） 
        {
            int j = e[i];						// j 是图中的节点 （按图中的节点编号来搜，不是按边来搜 ）
            if(d[j] == -1)						//如果 j 点没有被搜过 
            {
                d[j] = d[t] + 1;				//记录 j 点的层数 
                q[++tt] = j;					//让 j 入队（搜索 j 的儿子） 
            }
        }
    }
    return d[n];								//返回第 n 个点的层数 
}

int main()
{
    cin >> n >> m;
    
    memset(h,-1,sizeof h);						//初始化表头！
    
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);								//建立有向图（单向建边） 
    }
    
    cout << bfs() << endl;
    
    return 0;
} 

