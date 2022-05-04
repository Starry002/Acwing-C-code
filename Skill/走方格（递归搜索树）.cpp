//给定一个 n×m 的方格阵，沿着方格的边线走，从左上角 (0,0) 开始，每次只能往右或者往下走一个单位距离，问走到右下角 (n,m) 一共有多少种不同的走法。

//输入格式
//共一行，包含两个整数 n 和 m。

//输出格式
//共一行，包含一个整数，表示走法数量。

//数据范围
//1≤n,m≤10

//输入样例：2 3

//输出样例：10


#include <iostream>
using namespace std;
int cnt;
int n,m;
void num(int x,int y)
{
    if(x==n && y==m)
    {
        cnt++;
        return ;
    }
    if(x<n)num(x+1,y);
    if(y<m)num(x,y+1);
}
int main ()
{
    cin >> n >> m;
    num(0,0);
    cout << cnt << endl;
    return 0;
}
