#include <iostream>
#include <string>
using namespace std;
int main(){
	int cnt=0;
	char c;
	string s; 
	cout << "请输入字符串" << endl;
	cin >> s;
	cout << "请输入要查找的字符" << endl;
	cin >> c;
	char *p = &s[0];
	while(*p != c) p++ , cnt++;
	printf("%c字符位于%d位",*p,cnt+1);
	return 0;
}

