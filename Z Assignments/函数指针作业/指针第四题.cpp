#include <iostream>
#include <cstring>
using namespace std;
int main(){
	string s;
	cin >> s;
	int len = s.size(),cnt=0;
	char *p = &s[0] , *t = &s[len-1];
	while(*p == *t && cnt<len) p++ , t-- , cnt++;
	if(cnt == len) cout << "����" << endl;
	else cout << "���ǻ���" << endl; 
	return 0;
}

