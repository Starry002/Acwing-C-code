#include <iostream>
using namespace std;
void fun(int a,int b)
{
	int x = a*b;
	int c = 0;
	while(b)
	{
		c = a%b;
		a = b;
		b = c;
	}
	cout << a << ' ' << x/a << endl;
}
int main()
{
	int a,b;
	cin >> a >> b;
	fun(a,b);
	return 0;
}

