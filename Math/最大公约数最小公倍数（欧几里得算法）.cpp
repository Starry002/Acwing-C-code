//PS：最小公倍数 == ab相乘除以最大公约数 
//原理演示：
//  16 20 16 
//	20 16 4 
//	16 4  0
//	4  0  0


// C++递归写法 
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

// C普通写法
#include <stdio.h>
int main()
{
	int m,n;
	scanf("%d %d",&n,&m);
	int x = m*n;
	int a = 0;
	while(m)								// m 为零时，循环结束 
	{
		a = n%m;
		n = m;								//让 n 等于 m 
		m = a;								//让 m 等于 n 除 m 的余数
	}
	printf("%d\n%d",n,x/n);
	return 0;
}
