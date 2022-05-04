#include <iostream>
using namespace std;
void fun(int n , char a , char b, char c)
{
	if(n==1) cout << a << "-->" << c << endl;
	else
	{
		fun(n-1,a,c,b);
		cout << a << "-->" << c << endl;
		fun(n-1,b,a,c);
	}

}
int main()
{
	int n;
	cin >> n;
	fun(n,'A','B','C');
	return 0;
}
