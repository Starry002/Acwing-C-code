//给定两个非负整数（不含前导 0） A，B，请你计算 A/B 的商和余数。

//输入格式
//共两行，第一行包含整数 A，第二行包含整数 B。

//输出格式
//共两行，第一行输出所求的商，第二行输出所求余数。

//数据范围
//1≤A的长度≤100000,
//1≤B≤10000,
//B 一定不为 0

//输入样例：
//7
//2

//输出样例：
//3
//1

//第一遍  2022/04/03
//第二遍  2022/04/17
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> div(vector<int> &A,int b,int &r)					//自定义 vector 数组的 除法 函数（默认 A 是高精度整数 ，b 是短整数，r是余数） 
{
    vector<int> C;
    r = 0;
    for(int i = A.size()-1;i>=0;i--)							//只要 A 没完，就继续输入 
    {
        r = r*10 + A[i];										//给 A 的每一位 加上 上一位的余数 * 10 
        C.push_back(r/b);										//给 C 中加上整除的数 
        r %= b;													//令 r 等于余数 
    }
    
    reverse(C.begin(),C.end());									//由于除法是高位在前，因此需要反转一下 
    while(C.size()>1 && C.back() == 0) C.pop_back();			//去掉前导零
    
    return C;
}

int main()
{
    int b,r;
    string a;
    cin >> a >> b;
    
    vector<int> A;
    for(int i = a.size()-1;i>=0;i--) A.push_back(a[i] - '0');
    
    vector<int> C = div(A,b,r);
    
    for(int i = C.size()-1;i>=0;i--) printf("%d",C[i]);
    printf("\n%d",r);
    
    return 0;
} 

