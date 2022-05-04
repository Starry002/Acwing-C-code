//���������Ǹ�����������ǰ�� 0�� A �� B��������� A��B ��ֵ��

//�����ʽ
//�����У���һ�а������� A���ڶ��а������� B��

//�����ʽ
//��һ�У����� A��B ��ֵ��

//���ݷ�Χ
//1��A�ĳ��ȡ�100000,
//0��B��10000

//����������
//2
//3

//���������
//6 

//��һ��  2022/04/03
//�ڶ���  2022/04/17
#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(vector<int> &A,int b)						//�Զ��� vector ����� �˷� ������Ĭ�� A �Ǹ߾������� ��b�Ƕ������� 
{
    vector<int> C;
    
    int t = 0;												// t ��ʱ�洢 A[i]*b ��ֵ 
    for(int i = 0;i<A.size() || t;i++)						//ֻҪ A û�� ������ t ���ܽ�λ 
    {
        if(i<A.size()) t += A[i] * b;						//�� A ��ÿһλ ֱ�� ���� b �����壩 
        C.push_back(t%10);									//�� C �� i λ�ϴ� t ������  
        t /= 10;											//������� 10 �ͽ�λ 
    }
    
    while(C.size()>1 && C.back() == 0) C.pop_back();		//ȥ��ǰ���� 
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
