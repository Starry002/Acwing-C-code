#include <iostream>
#include <cstdio>
#include <cmath>									//sqrt����ƽ����     abs��������ֵ 
using namespace std;
int main()
{
    int n;											//��Ŀ�涨�������Ϊ���� 
    cin >> n;
    int i,j;
    int x = n/2 , y = n/2;							//�������ĵ� 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           if(abs(i - x) + abs(j - y) <= n/2)       //�۲�n�����ι��ɵã��õ㵽���ĵ������پ���С��  n/2 ���� ������� 
                cout << "*";
           else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
