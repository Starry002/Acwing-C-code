//维护一个字符串集合，支持两种操作：
//I x 向集合中插入一个字符串 x；
//Q x 询问一个字符串在集合中出现了多少次。
//共有 N 个操作，输入的字符串总长度不超过 105，字符串仅包含小写英文字母。

//输入格式
//第一行包含整数 N，表示操作数。
//接下来 N 行，每行包含一个操作指令，指令为 I x 或 Q x 中的一种。

//输出格式
//对于每个询问指令 Q x，都要输出一个整数作为结果，表示 x 在集合中出现的次数。
//每个结果占一行。

//数据范围
//1≤N≤2*104

//输入样例：
//5
//I abc
//Q abc
//Q ab
//I ab
//Q ab

//输出样例：
//1
//0
//1

//第一遍  2022/3/14
//第二遍  2022/3/30
#include <iostream>
using namespace std;
const int N = 1e5+10;

char str[N];                                        //son存储当前结点的儿子，cnt存储当前节点存的单词总数
int son[N][26],cnt[N],idx;                          //idx是当前结点的下标（下标为零的点，既是根节点，又是空节点

void insert(char str[])								//插入操作 
{
    int p = 0 , i;									//设置根节点 p 
    for (i = 0 ; str[i] ; i++)						//遍历输入的字符串 ，用str[i]判断是否走到结尾（字符数组最后一位是 '/0' ） 
    {
        int u = str[i] - 'a';						//把字母 a - z 映射为数字 0 - 25 ; 
        if(!son[p][u]) son[p][u] = ++ idx;			//如果不存在儿子节点，创建儿子节点 
        p = son[p][u];								//存在儿子节点，走到儿子节点 
    }
    cnt[p]++;										//以 p 点结尾的单词数量加 1 
}

int query(char str[])								//查询操作 
{
    int p = 0 , i;									//设置根节点 p 
    for(i = 0 ; str[i] ; i++)						//遍历输入的字符串 ，用str[i]判断是否走到结尾（字符数组最后一位是 '/0' ）
    {
        int u = str[i] - 'a';						//把字母 a - z 映射为数字 0 - 25 ; 
        if(!son[p][u]) return 0;					//如果不存在儿子节点，退出程序 
        p = son[p][u];								//存在儿子节点，走到儿子节点
    }
    return cnt[p];									//返回以 p 点结尾的单词数量 
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char op[2];
        scanf("%s%s",op,str);
        if(op[0] == 'I') insert(str);
        else printf("%d\n",query(str));
    }
    return 0;
}

