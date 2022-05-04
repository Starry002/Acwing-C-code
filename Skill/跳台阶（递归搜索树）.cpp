//一个楼梯共有 n 级台阶，每次可以走一级或者两级，问从第 0 级台阶走到第 n 级台阶一共有多少种方案。

//输入格式
//共一行，包含一个整数 n。

//输出格式
//共一行，包含一个整数，表示方案数。

//数据范围
//1≤n≤15

//输入样例：5

//输出样例：8

#include <iostream>
using namespace std;
int fps(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;
    return fps(n-1)+fps(n-2);
}
int main ()
{
    int n;
    cin >> n;
    cout << fps(n) << endl;;
    return  0;
}
