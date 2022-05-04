#include <iostream>
#include <cstdio>
#include <cstring>
char s[100],s1[100];
using namespace std;
int main()
{
	
	FILE *fp,*ft;
	fp = fopen("in.txt","r") , ft = fopen("out.txt","w");
	
	int i=0;
	while(!feof(fp)) fscanf(fp,"%c",&s[i++]);
	for(int i=0;i<strlen(s);i++) s1[i] = s[i],s1[i+strlen(s)] = s[i];
	for(int i=0;i<strlen(s1);i++) fprintf(ft,"%c",s1[i]),printf("%c",s1[i]);
	
	fclose(ft) , fclose(fp);
	
	return 0;
}

