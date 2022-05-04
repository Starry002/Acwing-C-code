//���� n ������ [li,ri]��Ҫ��ϲ������н��������䡣
//ע������ڶ˵㴦�ཻ��Ҳ���н�����
//����ϲ���ɺ�����������
//���磺[1,3] �� [2,6] ���Ժϲ�Ϊһ������ [1,6]��

//�����ʽ
//��һ�а������� n��
//������ n �У�ÿ�а����������� l �� r��

//�����ʽ
//��һ�У�����һ����������ʾ�ϲ�������ɺ�����������

//���ݷ�Χ
//1��n��100000,
//-109��li��ri��109

//����������
//5
//1 2
//2 4
//5 6
//7 8
//7 9

//���������
//3

//��һ��  2022/04/10
//�ڶ���  2022/04/30 
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int , int > PII;
int n;
vector<PII> segs;												//�洢ÿһ������ 

void merge(vector<PII> &segs)									//�����Զ���� vector �ϲ����� 
{
    vector<PII> res;
    
    sort(segs.begin(),segs.end());								//��������Ҫ�ǽ���˵��źã�����ϲ��� �������� 
    
    int st = -2e9 , ed = -2e9;									//�������Ҷ˵㣨��ͷ������β �� ȡ -2e9 ��Ϊ��ͼ���� �� int��ȡֵ��ΧΪ -2147483648 ~~ +2147483648 �� -0x3f3f3f3f �� -1<<30 
    for(auto seg:segs)											// c++ 11 ���� �������ᱨ�������� ��������� 
        if(ed < seg.first)										//�����ǰ������Ҷ˵�С����һ���������˵㣨�޽�������ֱ�Ӽӵ� res ���� 
        {
            if(st != -2e9) res.push_back({st,ed});				//����������һ������ 
            st = seg.first , ed = seg.second;					//�������� 
        }
        else ed = max(ed,seg.second);							//��ǰ�����Ҷ˵���ڵ�����һ���������˵㣨�н����������������Ҷ˵� ���˴��������ֵ ���� 
    
    if(st != -2e9) res.push_back({st,ed});						//�������һ�����䣨��Ϊѭ���Ѿ�������û����һ������������бȽ��ˣ� 
    
    segs = res;													//�� res ��ֵ�� segs ���ش�  
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

