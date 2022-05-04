//给定两个正整数（不含前导 0），计算它们的和。

//输入格式
//共两行，每行包含一个整数。

//输出格式
//共一行，包含所求的和。

//数据范围
//1≤整数长度≤100000

//输入样例：
//12
//23

//输出样例：
//35

//第一遍  2022/04/02
//第二遍  2022/04/17 
#include <iostream>
#include <vector>
using namespace std;

vector<int> add(vector<int> &A,vector<int> &B)						//自定义 vector 数组的 加法 函数 （直接引用 A、B 是为了节省时间，不用再 copy 一遍） 
{
	int t=0; 
    vector<int> C;
    for(int i = 0;i<A.size() || i<B.size();i++)						//用 t 临时存储 A、B 的第 i 位之和  , 只要 A、B 有一个没完，就继续输入 
    {
        if(i<A.size()) t += A[i];									//如果 A 的 i 位上有数字，就加到 t 上 
        if(i<B.size()) t += B[i];									//如果 B 的 i 位上有数字，就加到 t 上 
        C.push_back(t%10);											//给 C 的 i 位上存 t 的余数 
        t /= 10;													//如果大于 10 就进位 
    }
    if(t) C.push_back(1);
    return C;
}

int main ()
{
    string a,b;														// 字符串输入（数字很长） 
    vector<int> A,B;												// vector 数组存储数据 
    
    cin >> a >> b;
    for(int i = a.size()-1;i>=0;i--) A.push_back(a[i]-'0');			//将输入的字符数字 映射 为真正的数字 
    for(int i = b.size()-1;i>=0;i--) B.push_back(b[i]-'0');			//高位在后，低位在前，主要是方便进位（后面加一位容易） 
    
    vector<int> C = add(A,B);
    
    for(int i = C.size()-1;i>=0;i--) printf("%d",C[i]);				//由于是反着存储的数字，因此输出也要反着 
    return 0;
} 
