//PS����С������ == ab��˳������Լ�� 
//ԭ����ʾ��
//  16 20 16 
//	20 16 4 
//	16 4  0
//	4  0  0


// C++�ݹ�д�� 
#include <iostream>
using namespace std;
int gcd(int a,int b)
{
    if(a%b == 0)return b;
    return gcd(b,a%b);
}
int main ()
{
    int a,b,max_gcd,max_lcm;
    cin >> a >> b;
    max_gcd = gcd(a,b);
    max_lcm = (a*b)/max_gcd;
    cout << max_lcm << endl;
    return 0;
}

// C��ͨд��
#include <stdio.h>
int main()
{
	int m,n;
	scanf("%d %d",&n,&m);
	int x = m*n;
	int a = 0;
	while(m)								// m Ϊ��ʱ��ѭ������ 
	{
		a = n%m;
		n = m;								//�� n ���� m 
		m = a;								//�� m ���� n �� m ������
	}
	printf("%d\n%d",n,x/n);
	return 0;
}
