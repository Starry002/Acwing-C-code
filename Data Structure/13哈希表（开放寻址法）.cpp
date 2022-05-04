//维护一个集合，支持如下几种操作：
//I x，插入一个数 x；
//Q x，询问数 x 是否在集合中出现过；
//现在要进行 N 次操作，对于每个询问操作输出对应的结果。

//输入格式
//第一行包含整数 N，表示操作数量。
//接下来 N 行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。

//输出格式
//对于每个询问指令 Q x，输出一个询问结果，如果 x 在集合中出现过，则输出 Yes，否则输出 No。
//每个结果占一行。

//数据范围
//1≤N≤105
//-109≤x≤109

//输入样例：
//5
//I 1
//I 2
//I 3
//Q 2
//Q 5

//输出样例：
//Yes
//No

//第一遍  2022/03/25
//第二遍  2022/04/06 
#include <iostream>
#include <cstring>                  					// memset 在 cstring 库里面 ，按字节赋值，一般赋值为 1 或 0 （每字节都相同） 
using namespace std;
const int N = 200003 , null = 0x3f3f3f3f;               // null 是数据范围之外的一个值，用于表示空指针 
int h[N];												// N 一般要取大于 两到三倍（yxc经验之谈） 数据范围的第一个质数，并且离 2 的次方最远（降低冲突概率）

int find(int x)											//如果 k 在哈希表中，返回的就是 k 的位置，否则返回的是 应该插入的位置（ k ） 
{
    int i,k = (x % N + N) % N;
    while(h[k] != null && h[k] != x)
    {
    	k++;
    	if(k==N) k = 0;									//如果走到头，回头看前面还有没有坑 
	}
    return k;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    memset(h,0x3f,sizeof h);          					//按字节赋值，初始化链表，使其指向空（0x3f3f3f3f）
    
    while(n--)
    {
	    int x; 
        char op[2];
        scanf("%s%d",op,&x);
        int k = find(x);								//先让 x 找坑（ k ） 
        if(*op == 'I') h[k] = x;						//开放寻址法 ， 直接插入 k 即可（蹲坑） 
        else 
        {
            if(h[k] != null) puts("Yes");
            else puts("No");
        }
    }
    
    return 0;
}

//求质数代码：
//int i,j;
//for(i=2e5;;i++)
//{
//    bool flag = true;
//    for(j=2;j*j<=i;j++)
//    { 
//	    if(i % j == 0)
//	    {
//	        flag = false;
//	        break;
//	    }
//	} 
//    if(flag)
//    {
//        cout << i << endl;
//        break;
//    }
//}
