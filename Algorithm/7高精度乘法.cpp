//给定两个非负整数（不含前导 0） A 和 B，请你计算 A×B 的值。

//输入格式
//共两行，第一行包含整数 A，第二行包含整数 B。

//输出格式
//共一行，包含 A×B 的值。

//数据范围
//1≤A的长度≤100000,
//0≤B≤10000

//输入样例：
//2
//3

//输出样例：
//6 

//第一遍  2022/04/03
//第二遍  2022/04/17
#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(vector<int> &A,int b)						//自定义 vector 数组的 乘法 函数（默认 A 是高精度整数 ，b是短整数） 
{
    vector<int> C;
    
    int t = 0;												// t 临时存储 A[i]*b 的值 
    for(int i = 0;i<A.size() || t;i++)						//只要 A 没完 ，或者 t 还能进位 
    {
        if(i<A.size()) t += A[i] * b;						//用 A 的每一位 直接 乘以 b （整体） 
        C.push_back(t%10);									//给 C 的 i 位上存 t 的余数  
        t /= 10;											//如果大于 10 就进位 
    }
    
    while(C.size()>1 && C.back() == 0) C.pop_back();		//去掉前导零 
    return C;
}

int main()
{
	int b; 
    string a;
    cin >> a >> b;
    
    vector<int> A;
    for(int i = a.size()-1;i>=0;i--) A.push_back(a[i] - '0');
    
    vector<int> C = mul(A,b);

    for(int i = C.size()-1;i>=0;i--) printf("%d",C[i]);
    
    return 0;
}
