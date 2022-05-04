//给定 n 个区间 [li,ri]，要求合并所有有交集的区间。
//注意如果在端点处相交，也算有交集。
//输出合并完成后的区间个数。
//例如：[1,3] 和 [2,6] 可以合并为一个区间 [1,6]。

//输入格式
//第一行包含整数 n。
//接下来 n 行，每行包含两个整数 l 和 r。

//输出格式
//共一行，包含一个整数，表示合并区间完成后的区间个数。

//数据范围
//1≤n≤100000,
//-109≤li≤ri≤109

//输入样例：
//5
//1 2
//2 4
//5 6
//7 8
//7 9

//输出样例：
//3

//第一遍  2022/04/10
//第二遍  2022/04/30 
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int , int > PII;
int n;
vector<PII> segs;												//存储每一对区间 

void merge(vector<PII> &segs)									//引入自定义的 vector 合并区间 
{
    vector<PII> res;
    
    sort(segs.begin(),segs.end());								//先排序（主要是将左端点排好，方便合并） ！！！！ 
    
    int st = -2e9 , ed = -2e9;									//定义左右端点（从头遍历到尾 ） 取 -2e9 是为了图方便 ， int的取值范围为 -2147483648 ~~ +2147483648 ， -0x3f3f3f3f ， -1<<30 
    for(auto seg:segs)											// c++ 11 特性 编译器会报错！！！！ （待解决） 
        if(ed < seg.first)										//如果当前区间的右端点小于下一个区间的左端点（无交集），直接加到 res 里面 
        {
            if(st != -2e9) res.push_back({st,ed});				//特判跳过第一个区间 
            st = seg.first , ed = seg.second;					//更新区间 
        }
        else ed = max(ed,seg.second);							//当前区间右端点大于等于下一个区间的左端点（有交集），更新最大的右端点 ，此处不用添加值 ！！ 
    
    if(st != -2e9) res.push_back({st,ed});						//特判最后一个区间（因为循环已经结束，没有下一个区间和它进行比较了） 
    
    segs = res;													//将 res 赋值给 segs 返回答案  
}

int main ()
{
    int n;
    cin >> n;
    while(n--)
    {
        int l,r;
        cin >> l >> r;
        segs.push_back({l,r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}

