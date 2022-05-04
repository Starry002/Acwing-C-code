#include <iostream>
#include <cmath>
using namespace std;
int sump(int x,int y)
{
	return x*x+y*y;
}
int main(){
	int x, y;
	cin >> x >> y;
	cout << sump(x,y) << endl;
	return 0;
}

