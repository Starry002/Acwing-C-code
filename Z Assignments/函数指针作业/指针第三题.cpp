#include <iostream>
#include <string>
using namespace std;
int main(){
	int cnt=0;
	char c;
	string s; 
	cout << "�������ַ���" << endl;
	cin >> s;
	cout << "������Ҫ���ҵ��ַ�" << endl;
	cin >> c;
	char *p = &s[0];
	while(*p != c) p++ , cnt++;
	printf("%c�ַ�λ��%dλ",*p,cnt+1);
	return 0;
}

