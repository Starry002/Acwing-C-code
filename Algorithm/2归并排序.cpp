//给定你一个长度为 n 的整数数列。
//请你使用归并排序对这个数列按照从小到大进行排序。
//并将排好序的数列按顺序输出。

//输入格式
//输入共两行，第一行包含整数 n。
//第二行包含 n 个整数（所有整数均在 1～109 范围内），表示整个数列。

//输出格式
//输出共一行，包含 n 个整数，表示排好序的数列。

//数据范围
//1≤n≤100000

//输入样例：
//5
//3 1 2 4 5

//输出样例：
//1 2 3 4 5

//第一遍  2022/03/16 
//第二遍  2022/04/14
//第三遍  2022/04/17 
#include <iostream>
using namespace std;
const int N = 1e5+10;
int q[N],tmp[N];												//创建存放数字的数组 q ，和辅助数组 tmp 

void merge_sort(int q[],int l,int r)							//将区间一分为二归并排序 
{
    if(l>=r) return;											//如果区间不存在，不用排序 
    int mid = l+r >> 1;											//采用“分治 ”思想，将区间一分为二，使用位运算 >> 找到区间中点（速度快、逼格高） 
    merge_sort(q,l,mid),merge_sort(q,mid+1,r);					//将两个分好的区间排好序 
    
    int k = 0 , i = l , j = mid + 1;							//设定计数 k 和 i j 两个指针 , j = mid + 1 是因为递归子区间时，l+r=1 会下取整，避免最后一个区间取值为 0，0 
    while(i <= mid && j <= r)									// i j 都没有走完 
    {
        if(q[i] <= q[j]) tmp[k++] = q[i++];						//如果 i 指向的数字大，给 tmp 里存放 q[i] 
        else tmp[k++] = q[j++];									//如果 j 指向的数字大，给 tmp 里存放 q[j] 
    }
    while(i <= mid) tmp[k++] = q[i++];							//当 j 走完 i 没走完时， 直接将 q[i] 及后面的数字放入 tmp 里面 
    while(j <= r) tmp[k++] = q[j++];							//当 i 走完 j 没走完时， 直接将 q[j] 及后面的数字放入 tmp 里面
    
    for(i=l,k=0;i<=r;i++,k++) q[i] = tmp[k];					//将 tmp 里存放的数字放回 q 里面 （注意 q 的下标 i 从左区间端点 l 开始） 
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int i;
    for(i=0;i<n;i++) scanf("%d",&q[i]);
    
    merge_sort(q,0,n-1);
    
    for(i=0;i<n;i++) printf("%d ",q[i]);
    
    return 0;
}
