//һ��¥�ݹ��� n ��̨�ף�ÿ�ο�����һ�������������ʴӵ� 0 ��̨���ߵ��� n ��̨��һ���ж����ַ�����

//�����ʽ
//��һ�У�����һ������ n��

//�����ʽ
//��һ�У�����һ����������ʾ��������

//���ݷ�Χ
//1��n��15

//����������5

//���������8

#include <iostream>
using namespace std;
int fps(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;
    return fps(n-1)+fps(n-2);
}
int main ()
{
    int n;
    cin >> n;
    cout << fps(n) << endl;;
    return  0;
}
