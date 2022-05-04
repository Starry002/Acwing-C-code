#include <iostream>
using namespace std;
void fun(int n , char a , char b, char c)
{
	if(n==1) cout << a << "-->" << c << endl;
	else
	{
		fun(n-1,a,c,b);							//把 A 上面 n-1 个盘子先通过 C 搬到 B 
		cout << a << "-->" << c << endl;		//再把最底下的盘子搬到 C 
		fun(n-1,b,a,c);							//最后把从 A 搬到 B 上的 n-1 个盘子通过 A 搬到 C 
	}
}
int main()
{
	int n;
	cin >> n;
	fun(n,'A','B','C');
	return 0;
}
