#include <iostream>
using namespace std;
int fun(int n)
{
	if(n==0) return 1;
	return (fun(n-1)+1)*2;
}
int main()
{
	cout << fun(10) << endl;
	return 0;
}
// sum   1   2   3   4   5  6  7  8  9   10
//3070  1534 766 382 190 94 46 22 10 4   1
