//假定有一个无限长的数轴，数轴上每个坐标上的数都是 0。
//现在，我们首先进行 n 次操作，每次操作将某一位置 x 上的数加 c。
//接下来，进行 m 次询问，每个询问包含两个整数 l 和 r，你需要求出在区间 [l,r] 之间的所有数的和。

//输入格式
//第一行包含两个整数 n 和 m。
//接下来 n 行，每行包含两个整数 x 和 c。
//再接下来 m 行，每行包含两个整数 l 和 r。

//输出格式
//共 m 行，每行输出一个询问中所求的区间内数字和。

//数据范围
//-109≤x≤109,
//1≤n,m≤105,
//-109≤l≤r≤109,
//-10000≤c≤10000

//输入样例：
//3 3
//1 2
//3 6
//7 5
//1 3
//4 6
//7 8

//输出样例：
//8
//0
//5

//第一遍  2022/04/09
//第二遍  2022/04/27
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;					//使用 pair 定义双元组 
const int N = 3e5+10;
		
int n,m;									//离散化的本质，是映射，将间隔很大的点，映射到相邻的数组元素中。减少对空间的需求，也减少计算量。
int a[N],s[N];								// a[N] 存储每个数字 ， s[N] 存储前缀和 
vector<int> alls;							//存储所有需要 添加和查询 的下标 ，进行映射（排序，去重） 
vector<PII> add,query;						//开二元组类型 vector 记录每一对添加和查询 （映射前的数字） ，用于二分查找 

int find(int x)								//二分查找，用于找映射后的下标（向右二分，找到大于等于 x 的第一个下标） 
{
    int l = 0 , r = alls.size()-1;			//定义左右区间 
    while(l<r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l+1;								//返回 l + 1 是因为下标从 1 开始的（方便求前缀和） 
}

int main()
{
    cin >> n >> m;
    
    while(n--)
    {
        int x,c;
        cin >> x >> c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    
    sort(alls.begin(),alls.end());									//排序 
    alls.erase(unique(alls.begin(),alls.end()),alls.end());			//去重 
   
    for(auto item : add)											// c++ 11 特性 编译器会报错！！！！ （待解决） 
    {
        int x = find(item.first);
        a[x] += item.second;
    }
    
    for(int i=1;i<=alls.size();i++) s[i] = s[i-1] + a[i];			//前缀和 
    
    for(auto item : query)											// c++ 11 特性 编译器会报错！！！！ （待解决） 
    {
        int l = find(item.first) , r = find(item.second);
        cout << s[r] - s[l-1] << endl;
    }
    
    return 0;
}

/* 
vector<int>::iterator unique(vector<int> &a)						//手写 unique （双指针算法） 
{
    int j=0;
	for(int i=0;i<a.size();i++)										// a[0] ~~ a[j-1] 记录 a 中所有不重复的数 
		if(!i || a[i] != a[i+1])									//只要 a[i] 是 第一次出现 或者 与下一位不同 
			a[j++] = a[i];
	return a.begin() + j;											//返回最后一位数的指针 
}
*/ 

