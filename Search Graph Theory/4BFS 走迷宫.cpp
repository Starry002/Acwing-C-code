//给定一个 n×m 的二维整数数组，用来表示一个迷宫，数组中只包含 0 或 1，其中 0 表示可以走的路，1 表示不可通过的墙壁。
//最初，有一个人位于左上角 (1,1) 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。
//请问，该人从左上角移动至右下角 (n,m) 处，至少需要移动多少次。
//数据保证 (1,1) 处和 (n,m) 处的数字为 0，且一定至少存在一条通路。

//输入格式
//第一行包含两个整数 n 和 m。
//接下来 n 行，每行包含 m 个整数（0 或 1），表示完整的二维数组迷宫。

//输出格式
//输出一个整数，表示从左上角移动至右下角的最少移动次数。

//数据范围
//1≤n,m≤100

//输入样例：
//5 5
//0 1 0 0 0
//0 1 0 1 0
//0 0 0 0 0
//0 1 1 1 0
//0 0 0 1 0

//输出样例：
//8

//第一遍  2022/3/29 
#include <cstring>
#include <iostream>
using namespace std;
const int N = 110;
typedef pair<int ,int> PII;
int n,m;
PII load[N][N];																			//存储路径 
int g[N][N];																			// g 存储地图 
int d[N][N];																			// d 存储每个点到 0，0  的距离 
PII q[N * N];																			// q 存储当前点可选的方向（利用队列先进先出的特性求出最短路径） 

int bfs()																				//宽度优先搜索 
{
	int hh=0,tt=0;																		//定义队头，队尾 
	q[0] = {0,0};																		//定义起点 
	
	memset(d,-1,sizeof d);																//初始化 d 中的每个点 ，标记为 -1 （未走过） 
	d[0][0] = 0;																		//起点一定是走过的！ 
	
	int dx[4] = {-1,0,1,0} , dy[4] = {0,1,0,-1};										//利用向量（偏移量）表示每个点的下一个点 
	
	while(hh<=tt)																		//如果可以扩展到下一层（保证先把周围一圈走完再走下一层） 
	{
		PII t = q[hh++];																//取出队头元素（先进先出），加下标 ！！ 
		
		for(int i=0;i<4;i++)															//枚举向量的四个方向 
		{
			int x = t.first + dx[i] , y = t.second + dy[i];								//利用向量（偏移量）表示每个点的下一个点 
			if(x>=0 && x<n && y>=0 && y<m && g[x][y] == 0 && d[x][y] == -1)				//如果下一个点 x，y 不出界 ，可以走 并且没走过（保证了最短路径） 
			{
				load[x][y] = t;
				d[x][y] = d[t.first][t.second] + 1;										//下一个点的距离为当前点的距离加 1  
				q[++tt] = {x,y};														//先把下一个点 x，y 存储到 q 中 ，再开出下一个位置 
			}
		}
	}
	
	int x = n - 1, y = m - 1;															//打印路径 （倒序） 
	while(x || y)
	{
		cout << x << ' ' << y << endl;
		PII t = load[x][y];
		x = t.first , y = t.second;	
	} 
	
	return d[n-1][m-1];																	//返回队列 q 中最后一个点的距离 
}

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)															//写入地图 
			cin >> g[i][j];
			
	cout << bfs() << endl;
	
	return 0;
}


/*
C++ queue写法： 
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;

typedef pair<int, int> PII;

int n, m;
int g[N][N], d[N][N];

int bfs()
{
    queue< pair<int, int> > q;

    q.push({0, 0});

    memset(d, -1, sizeof(d));

    d[0][0] = 0;


    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size())//队列不为空
    {
        PII t = q.front();//取队头元素

        q.pop();//出队

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;//当前点到起点的距离
                q.push({x, y});//将新坐标入队
            }
        }
    }

    return d[n - 1][m -1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}

*/
