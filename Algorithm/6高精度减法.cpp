//给定两个正整数（不含前导 0），计算它们的差，计算结果可能为负数。

//输入格式
//共两行，每行包含一个整数。

//输出格式
//共一行，包含所求的差。

//数据范围
//1≤整数长度≤105

//输入样例：
//32
//11

//输出样例：
//21

//第一遍  2022/04/02
//第二遍  2022/04/17 
#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> &A,vector<int> &B)								//自定义 vector 数组的 比较 函数  
{
	if(A.size() != B.size()) return A.size() > B.size();			// A、B长度不相等，直接判断 A、B大小 
	for(int i = A.size()-1;i>=0;i--)								//遍历 A 所有元素 
		if(A[i] != B[i])											//如果 A、B 的第 i 位不相等，判断 A、B大小 
			return A[i] > B[i];
	return true;													//否则 A 等于 B ，需要归到第一类情况（不用添负号） 
} 

vector<int> sub(vector<int> &A,vector<int> &B)						//自定义 vector 数组的 减法 函数  （默认 A （长位） 减去  B（短位）） 
{
	vector<int> C;
	for(int i = 0,t = 0;i<A.size();i++)								//用 t 临时存储 A、B 的第 i 位之差  , 只要 A（长位） 没完，就继续输入 
	{
		t = A[i] - t;												// t 先减去借位 
		if(i < B.size()) t -= B[i];									//如果 B（小数） 存在 i 位 ，再减 i 位 
		C.push_back((t+10)%10);										//如果 t 是正的 (t+10)%10 相当于 t ，如果 t 是负的 (t+10)%10 相当于 t+10（借位） 
		if(t<0) t = 1;												// t 是负的，借位 
		else t = 0;													// t 是正的，不借位 
	}
	
	while(C.size() > 1 && C.back() == 0) C.pop_back();				//去掉前导零 
	return C;
}

int main()
{
    string a,b;
    vector<int> A,B;
    
    cin >> a >> b;
    for(int i = a.size()-1;i>=0;i--) A.push_back(a[i] - '0');
    for(int i = b.size()-1;i>=0;i--) B.push_back(b[i] - '0');
    
    if(cmp(A,B))													//如果 大数减小数 直接用 sub 函数 
    {
        vector<int> C = sub(A,B);
        for(int i = C.size()-1;i>=0;i--) printf("%d",C[i]);
    }
    else															//如果 小数减大数 反着用 sub 函数 ，然后加 - 号 
    {
        vector<int> C = sub(B,A);
        printf("-");
        for(int i = C.size()-1;i>=0;i--) printf("%d",C[i]);
    }
    return 0;
}
