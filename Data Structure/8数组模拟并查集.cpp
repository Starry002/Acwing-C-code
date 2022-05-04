//一共有 n 个数，编号是 1～n，最开始每个数各自在一个集合中。
//现在要进行 m 个操作，操作共有两种：
//M a b，将编号为 a 和 b 的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
//Q a b，询问编号为 a 和 b 的两个数是否在同一个集合中；

//输入格式
//第一行输入整数 n 和 m。
//接下来 m 行，每行包含一个操作指令，指令为 M a b 或 Q a b 中的一种。

//输出格式
//对于每个询问指令 Q a b，都要输出一个结果，如果 a 和 b 在同一集合内，则输出 Yes，否则输出 No。
//每个结果占一行。

//数据范围
//1≤n,m≤105

//输入样例：
//4 5
//M 1 2
//M 3 4
//Q 1 2
//Q 1 3
//Q 3 4

//输出样例：
//Yes
//No
//Yes

//第一遍  2022/3/19
//第二遍  2022/4/1 
#include <iostream>
using namespace std;
const int N = 1e5+10;
int p[N];

//***并查集核心操作 
int find (int x)										//找祖宗节点 + 路径压缩 
{
    if(p[x] != x) p[x] = find(p[x]);					//递归找祖宗节点 （只有祖宗节点满足 p[x] == x) 
    return p[x];										//回溯时，把祖宗是谁传下来（路径压缩优化）					
}

int main ()
{
    int m,n;
    scanf("%d%d",&n,&m);
    
    int i;
    for(i=0;i<=n;i++) p[i] = i;							//给每一位数字编号，设置祖宗节点为 0  不存数字 
    
    while(m--)
    {
        char op[2];
        int a,b;
        scanf("%s%d%d",op,&a,&b);
        if(op[0] == 'M') p[find(a)] = find(b);			//!合并两个集合，就是让 a 的父辈等于 b 的祖宗节点 
        else
        {
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }

    
    return 0;
}
