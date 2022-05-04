//给定一个整数 n，将数字 1～n 排成一排，将会有很多种排列方法。
//现在，请你按照字典序将所有的排列方法输出。

//输入格式
//共一行，包含一个整数 n。

//输出格式
//按字典序输出所有排列方案，每个方案占一行。

//数据范围
//1≤n≤7

//输入样例：3

//输出样例：
//1 2 3
//1 3 2
//2 1 3
//2 3 1
//3 1 2
//3 2 1

//第一遍  2022/3/27 
#include <iostream>
using namespace std;
const int N = 10;
int path[N];											//保存路径（序列） 
bool st[N];												//记录数字是否被用过 （保存状态） 
int n;
void dfs(int u)											//深度优先搜索 
{
    if(u == n)											//如果撞到南墙了 
    {
        int i;
        for(i=0;i<n;i++) printf("%d ",path[i]);			//输出当前路径中的所有数字 
        puts("");
        return;
    }
    int i;
    for(i=1;i<=n;i++)									//空位上可以选择的数字为:1 ~ n
    {   
        if(!st[i])										//如果第 i 位数字没有被用过 
        {
            path[u] = i;								//将第 i 位数字保存到序列当中 
            st[i] = true;								//标记第 i 位数字已经用过 
            dfs(u+1);									//递归填下一位 ， 不撞南墙不回头 
            st[i] = false;								//回溯，删除第 i 位数字的标记（恢复现场） 
        }

    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}
