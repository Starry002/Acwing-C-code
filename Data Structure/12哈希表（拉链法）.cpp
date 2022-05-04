//ά��һ�����ϣ�֧�����¼��ֲ�����
//I x������һ���� x��
//Q x��ѯ���� x �Ƿ��ڼ����г��ֹ���
//����Ҫ���� N �β���������ÿ��ѯ�ʲ��������Ӧ�Ľ����

//�����ʽ
//��һ�а������� N����ʾ����������
//������ N �У�ÿ�а���һ������ָ�����ָ��Ϊ I x��Q x �е�һ�֡�

//�����ʽ
//����ÿ��ѯ��ָ�� Q x�����һ��ѯ�ʽ������� x �ڼ����г��ֹ�������� Yes��������� No��
//ÿ�����ռһ�С�

//���ݷ�Χ
//1��N��105
//-109��x��109

//����������
//5
//I 1
//I 2
//I 3
//Q 2
//Q 5

//���������
//Yes
//No

//��һ��  2022/03/25
//�ڶ���  2022/04/06 
#include <iostream>
#include <cstring>                  // memset �� cstring ������ �����ֽڸ�ֵ��һ�㸳ֵΪ 1 �� 0 ��ÿ�ֽڶ���ͬ�� 
using namespace std;
const int N = 100003;               
int h[N],e[N],ne[N],idx;			// N һ��Ҫȡ�������ݷ�Χ�ĵ�һ�������������� 2 �Ĵη���Զ�����ͳ�ͻ���ʣ�

void insert(int x)
{
    int k = (x % N + N) % N;        //ȷ�� k ��ֵΪ������ x % N �Ļ��п����Ǹ�����
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x)					//���Һ����� bool ���� 
{
    int i,k = (x % N + N) % N;
    for(i=h[k];i!=-1;i=ne[i])
        if(e[i] == x)
            return true;
    return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    memset(h,-1,sizeof h);          //���ֽڸ�ֵ����ʼ������ʹ��ָ��գ�-1��
    
    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(*op == 'I') insert(x);
        else 
        {
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }
    
    return 0;
}

//���������룺
//int i,j;
//for(i=1e5;;i++)
//{
//    bool flag = true;
//    for(j=2;j*j<=i;j++)
//    { 
//	    if(i % j == 0)
//	    {
//	        flag = false;
//	        break;
//	    }
//	} 
//    if(flag)
//    {
//        cout << i << endl;
//        break;
//    }
//}

