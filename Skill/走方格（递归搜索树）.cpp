//����һ�� n��m �ķ��������ŷ���ı����ߣ������Ͻ� (0,0) ��ʼ��ÿ��ֻ�����һ���������һ����λ���룬���ߵ����½� (n,m) һ���ж����ֲ�ͬ���߷���

//�����ʽ
//��һ�У������������� n �� m��

//�����ʽ
//��һ�У�����һ����������ʾ�߷�������

//���ݷ�Χ
//1��n,m��10

//����������2 3

//���������10


#include <iostream>
using namespace std;
int cnt;
int n,m;
void num(int x,int y)
{
    if(x==n && y==m)
    {
        cnt++;
        return ;
    }
    if(x<n)num(x+1,y);
    if(y<m)num(x,y+1);
}
int main ()
{
    cin >> n >> m;
    num(0,0);
    cout << cnt << endl;
    return 0;
}
