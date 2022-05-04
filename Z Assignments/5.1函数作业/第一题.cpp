#include <iostream>
using namespace std;
double s(double l, double h)
{
	return 0.5*l*h;
}
int main(){
	double l,h;
	cin >> l >> h;
	cout << s(l,h) << endl;
	return 0;
}

