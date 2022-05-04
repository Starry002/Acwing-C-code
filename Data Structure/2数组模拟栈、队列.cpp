1.栈 
//实现一个栈，栈初始为空，支持四种操作：
//push x – 向栈顶插入一个数 x；
//pop – 从栈顶弹出一个数；
//empty – 判断栈是否为空；
//query – 查询栈顶元素。
//现在要对栈进行 M 个操作，其中的每个操作 3 和操作 4 都要输出相应的结果。

//输入格式
//第一行包含整数 M，表示操作次数。
//接下来 M 行，每行包含一个操作命令，操作命令为 push x，pop，empty，query 中的一种。

//输出格式
//对于每个 empty 和 query 操作都要输出一个查询结果，每个结果占一行。
//其中，empty 操作的查询结果为 YES 或 NO，query 操作的查询结果为一个整数，表示栈顶元素的值。

//数据范围
//1≤M≤100000,
//1≤x≤109
//所有操作保证合法。

//输入样例：
//10
//push 5
//query
//push 6
//pop
//query
//pop
//empty
//push 4
//query
//empty

//输出样例：
//5
//5
//YES
//4
//NO

//第一遍  2022/03/13
//第二遍  2022/03/29
//第三遍  2022/04/11
//第四遍  2022/05/04 
#include <iostream>
using namespace std;
const int N = 1e5+10;
int stk[N],tt;

int main ()
{
    int m;
    cin >> m;
    
    int x;
    string op;
    while(m--)
    {
        cin >> op;
        if(op == "push") cin >> x , stk[++tt] = x;									//从 1 开始存储下标 ，方便判断队列是否为空（下标为 0 ）
        if(op == "pop") tt--;														//删除最后一个元素（栈顶元素） 
        if(op == "empty") cout << (tt ? "NO" : "YES") << endl;						//条件判断：（表达式 1 ? 表达式 2 ：表达式 3） 
        if(op == "query") cout << stk[tt] << endl;									// 1 true 2 ， 1 false 3 
    }
    
    return 0;
}


2.队列
//实现一个队列，队列初始为空，支持四种操作：
//push x – 向队尾插入一个数 x；
//pop – 从队头弹出一个数；
//empty – 判断队列是否为空；
//query – 查询队头元素。
//现在要对队列进行 M 个操作，其中的每个操作 3 和操作 4 都要输出相应的结果。

//输入格式
//第一行包含整数 M，表示操作次数。
//接下来 M 行，每行包含一个操作命令，操作命令为 push x，pop，empty，query 中的一种。

//输出格式
//对于每个 empty 和 query 操作都要输出一个查询结果，每个结果占一行。
//其中，empty 操作的查询结果为 YES 或 NO，query 操作的查询结果为一个整数，表示队头元素的值。

//数据范围
//1≤M≤100000,
//1≤x≤109,
//所有操作保证合法。

//输入样例：
//10
//push 6
//empty
//query
//pop
//empty
//push 3
//push 4
//pop
//query
//push 6

//输出样例：
//NO
//6
//YES
//4

//第一遍  2022/03/13
//第二遍  2022/03/29
//第三遍  2022/04/11
//第四遍  2022/05/04 
#include <iostream>
using namespace std;
const int N = 1e5+10;
int q[N],hh,tt=-1;														// q 存储队列 ， hh 是队头 ， tt 是队尾 

int main()
{
    int m;
    cin >> m;
    
    int x;
    string op;
    while(m--)
    {
        cin >> op;
        if(op == "push") cin >> x ， q[++tt] = x;						//从 0 开始存储下标 ， 方便队头输出
        if(op == "pop") hh++;											//从队头弹出一个数 ， 注意是加 下标 ! 
        if(op == "empty") cout << (hh<=tt ? "NO" : "YES") << endl;		//队头的下标 小于等于 队尾的下标 就存在元素！！ 
        if(op == "query") cout << q[hh] << endl;
    }
    
    return 0;
}
