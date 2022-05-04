//给定一个包含 n 个点（编号为 1～n）的无向图，初始时图中没有边。
//现在要进行 m 个操作，操作共有三种：
//C a b，在点 a 和点 b 之间连一条边，a 和 b 可能相等；
//Q1 a b，询问点 a 和点 b 是否在同一个连通块中，a 和 b 可能相等；
//Q2 a，询问点 a 所在连通块中点的数量；

//输入格式
//第一行输入整数 n 和 m。
//接下来 m 行，每行包含一个操作指令，指令为 C a b，Q1 a b 或 Q2 a 中的一种。

//输出格式
//对于每个询问指令 Q1 a b，如果 a 和 b 在同一个连通块中，则输出 Yes，否则输出 No。
//对于每个询问指令 Q2 a，输出一个整数表示点 a 所在连通块中点的数量
//每个结果占一行。

//数据范围
//1≤n,m≤105

//输入样例：
//5 5
//C 1 2
//Q1 1 2
//Q2 1
//C 2 5
//Q2 5

//输出样例：
//Yes
//2
//3

//第一遍  2022/3/19
//第二遍  2022/4/1
#include <iostream>
using namespace std;
const int N = 1e5+10;
int p[N],size1[N];										//定义 size1 数组，只记录根节点的 size1 

int find (int x)										//***并查集核心操作 , 找祖宗节点 + 路径压缩 
{
    if(p[x] != x) p[x] = find(p[x]);					//递归找祖宗节点 
    return p[x];										//回溯时，把祖宗是谁传下来（路径压缩优化）	
}

int main ()
{
    int m,n;
    scanf("%d%d",&n,&m);
    
    int i;
    for(i=0;i<=n;i++) 									//初始化 
	{
		size1[i] = 1;									//每个点长度为 1  
		p[i] = i;										//给每个数字编号 
	}
    
    while(m--)
    {
        char op[5];
        int a,b;
        scanf("%s",op);
        if(op[0] == 'C') 
		{
			scanf("%d%d",&a,&b);
			if(find(a) != find(b))						//如果 a 和 b 不在一个集合中，才进行以下操作 
			{
				size1[find(b)] += size1[find(a)];		// 将 a 所在集合的 size1 记入 b所在的集合 size1 
				p[find(a)] = b;							//让 a 的祖宗等于 b 
			}

		} 
        else if (op[1] == '1')
        {
        	scanf("%d%d",&a,&b);
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else 
        {
        	scanf("%d",&a);
        	printf("%d\n",size1[find(a)]); 				//输出集合 a 的连通块点的数量 
		}
    }

    
    return 0;
}
