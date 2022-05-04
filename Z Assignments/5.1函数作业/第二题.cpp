#include <iostream>
#include <cmath>
using namespace std;
int ads(int &a,int &b,int &c)
{
	if(a>b) swap(a,b);
	if(a>c) swap(a,c);
	if(b>c) swap(b,c);
	return c-a;
}
int main()
{
	int a,b,c,max,min;
	cin >> a >> b >> c;
	cout << ads(a,b,c) << endl;
	return 0;
}

