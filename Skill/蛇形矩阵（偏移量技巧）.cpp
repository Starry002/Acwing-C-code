//输入两个整数 n 和 m，输出一个 n 行 m 列的矩阵，将数字 1 到 n×m 按照回字蛇形填充至矩阵中。
//
//输入格式： 输入共一行，包含两个整数 n 和 m。
//
//输出格式：输出满足要求的矩阵。
//
//矩阵占 n 行，每行包含 m 个空格隔开的整数。
//
//数据范围
//1≤n,m≤100
//
//输入样例：
//3 3
//
//输出样例：
//1 2 3
//8 9 4
//7 6 5

#include <iostream>
#include <cstdio>
using namespace std;

int res[100][100];

int main ()
{
    int n,m;
    cin >> n >> m;
    
    int x,y,d,k;
    int dx[] = {0,1,0,-1},dy[] = {1,0,-1,0};    			 //偏移量
    
    for(x=0,y=0,d=0,k=1;k<=m*n;k++)
    {
        res[x][y] = k;										 //给每个位置赋值	
        int a = x + dx[d] , b = y + dy[d];					 //找到下一个坐标 
        if(a<0 || a>=n || b<0 || b>=m || res[a][b])			 //考虑边界问题（上、下、左、右） 
        {
            d = (d+1) % 4;									 //到达边界后
            a = x + dx[d] , b = y + dy[d];					 //改变偏移量  
        } 
        x = a,y = b;    									 //移动坐标 
    }
    
    int i,j;
    for (i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%4d ",res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
