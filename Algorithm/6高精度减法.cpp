//��������������������ǰ�� 0�����������ǵĲ����������Ϊ������

//�����ʽ
//�����У�ÿ�а���һ��������

//�����ʽ
//��һ�У���������Ĳ

//���ݷ�Χ
//1���������ȡ�105

//����������
//32
//11

//���������
//21

//��һ��  2022/04/02
//�ڶ���  2022/04/17 
#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> &A,vector<int> &B)								//�Զ��� vector ����� �Ƚ� ����  
{
	if(A.size() != B.size()) return A.size() > B.size();			// A��B���Ȳ���ȣ�ֱ���ж� A��B��С 
	for(int i = A.size()-1;i>=0;i--)								//���� A ����Ԫ�� 
		if(A[i] != B[i])											//��� A��B �ĵ� i λ����ȣ��ж� A��B��С 
			return A[i] > B[i];
	return true;													//���� A ���� B ����Ҫ�鵽��һ��������������ţ� 
} 

vector<int> sub(vector<int> &A,vector<int> &B)						//�Զ��� vector ����� ���� ����  ��Ĭ�� A ����λ�� ��ȥ  B����λ���� 
{
	vector<int> C;
	for(int i = 0,t = 0;i<A.size();i++)								//�� t ��ʱ�洢 A��B �ĵ� i λ֮��  , ֻҪ A����λ�� û�꣬�ͼ������� 
	{
		t = A[i] - t;												// t �ȼ�ȥ��λ 
		if(i < B.size()) t -= B[i];									//��� B��С���� ���� i λ ���ټ� i λ 
		C.push_back((t+10)%10);										//��� t ������ (t+10)%10 �൱�� t ����� t �Ǹ��� (t+10)%10 �൱�� t+10����λ�� 
		if(t<0) t = 1;												// t �Ǹ��ģ���λ 
		else t = 0;													// t �����ģ�����λ 
	}
	
	while(C.size() > 1 && C.back() == 0) C.pop_back();				//ȥ��ǰ���� 
	return C;
}

int main()
{
    string a,b;
    vector<int> A,B;
    
    cin >> a >> b;
    for(int i = a.size()-1;i>=0;i--) A.push_back(a[i] - '0');
    for(int i = b.size()-1;i>=0;i--) B.push_back(b[i] - '0');
    
    if(cmp(A,B))													//��� ������С�� ֱ���� sub ���� 
    {
        vector<int> C = sub(A,B);
        for(int i = C.size()-1;i>=0;i--) printf("%d",C[i]);
    }
    else															//��� С�������� ������ sub ���� ��Ȼ��� - �� 
    {
        vector<int> C = sub(B,A);
        printf("-");
        for(int i = C.size()-1;i>=0;i--) printf("%d",C[i]);
    }
    return 0;
}
