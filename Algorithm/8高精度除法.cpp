//���������Ǹ�����������ǰ�� 0�� A��B��������� A/B ���̺�������

//�����ʽ
//�����У���һ�а������� A���ڶ��а������� B��

//�����ʽ
//�����У���һ�����������̣��ڶ����������������

//���ݷ�Χ
//1��A�ĳ��ȡ�100000,
//1��B��10000,
//B һ����Ϊ 0

//����������
//7
//2

//���������
//3
//1

//��һ��  2022/04/03
//�ڶ���  2022/04/17
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> div(vector<int> &A,int b,int &r)					//�Զ��� vector ����� ���� ������Ĭ�� A �Ǹ߾������� ��b �Ƕ�������r�������� 
{
    vector<int> C;
    r = 0;
    for(int i = A.size()-1;i>=0;i--)							//ֻҪ A û�꣬�ͼ������� 
    {
        r = r*10 + A[i];										//�� A ��ÿһλ ���� ��һλ������ * 10 
        C.push_back(r/b);										//�� C �м����������� 
        r %= b;													//�� r �������� 
    }
    
    reverse(C.begin(),C.end());									//���ڳ����Ǹ�λ��ǰ�������Ҫ��תһ�� 
    while(C.size()>1 && C.back() == 0) C.pop_back();			//ȥ��ǰ����
    
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

