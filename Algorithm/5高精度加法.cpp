//��������������������ǰ�� 0�����������ǵĺ͡�

//�����ʽ
//�����У�ÿ�а���һ��������

//�����ʽ
//��һ�У���������ĺ͡�

//���ݷ�Χ
//1���������ȡ�100000

//����������
//12
//23

//���������
//35

//��һ��  2022/04/02
//�ڶ���  2022/04/17 
#include <iostream>
#include <vector>
using namespace std;

vector<int> add(vector<int> &A,vector<int> &B)						//�Զ��� vector ����� �ӷ� ���� ��ֱ������ A��B ��Ϊ�˽�ʡʱ�䣬������ copy һ�飩 
{
	int t=0; 
    vector<int> C;
    for(int i = 0;i<A.size() || i<B.size();i++)						//�� t ��ʱ�洢 A��B �ĵ� i λ֮��  , ֻҪ A��B ��һ��û�꣬�ͼ������� 
    {
        if(i<A.size()) t += A[i];									//��� A �� i λ�������֣��ͼӵ� t �� 
        if(i<B.size()) t += B[i];									//��� B �� i λ�������֣��ͼӵ� t �� 
        C.push_back(t%10);											//�� C �� i λ�ϴ� t ������ 
        t /= 10;													//������� 10 �ͽ�λ 
    }
    if(t) C.push_back(1);
    return C;
}

int main ()
{
    string a,b;														// �ַ������루���ֺܳ��� 
    vector<int> A,B;												// vector ����洢���� 
    
    cin >> a >> b;
    for(int i = a.size()-1;i>=0;i--) A.push_back(a[i]-'0');			//��������ַ����� ӳ�� Ϊ���������� 
    for(int i = b.size()-1;i>=0;i--) B.push_back(b[i]-'0');			//��λ�ں󣬵�λ��ǰ����Ҫ�Ƿ����λ�������һλ���ף� 
    
    vector<int> C = add(A,B);
    
    for(int i = C.size()-1;i>=0;i--) printf("%d",C[i]);				//�����Ƿ��Ŵ洢�����֣�������ҲҪ���� 
    return 0;
} 
