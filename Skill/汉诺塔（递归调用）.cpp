#include <iostream>
using namespace std;
void fun(int n , char a , char b, char c)
{
	if(n==1) cout << a << "-->" << c << endl;
	else
	{
		fun(n-1,a,c,b);							//�� A ���� n-1 ��������ͨ�� C �ᵽ B 
		cout << a << "-->" << c << endl;		//�ٰ�����µ����Ӱᵽ C 
		fun(n-1,b,a,c);							//���Ѵ� A �ᵽ B �ϵ� n-1 ������ͨ�� A �ᵽ C 
	}
}
int main()
{
	int n;
	cin >> n;
	fun(n,'A','B','C');
	return 0;
}
