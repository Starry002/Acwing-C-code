#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int cnt=0,i=1;
	char a[100],b[100];
	FILE *fp = fopen("zifu.txt","r") , *ft = fopen("jieguo.txt","w");
	fscanf(fp,"%s",a);
	char *p = &a[0] , *t=&b[1];
	while(*p != '\0')
	{
		b[i++] = *p++,cnt++;
		if(cnt%3==0) b[i++] = '*';
	}
	while(*t != '\0') fprintf(ft,"%c",*t) , cout << *t ,t++;
	return 0;
}

