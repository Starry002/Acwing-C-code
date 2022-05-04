#include <iostream>
using namespace std;
int main(){
	char a[5][10];
	int i=0 , j=0 , sum=100;
	FILE *fp = fopen("zifu.txt","r");
	while(!feof(fp)) fscanf(fp,"%s",&a[i++]);
	for(int i=0;i<5;i++)
	{
		int cnt = 0;
		char *p = &a[i][0];
		while(*p != '\0') p++ , cnt++;
		if(cnt<sum) sum = cnt;
	}
	cout << sum << endl;
	return 0;
}



//char (*P)[10];   定义一个指向每行 10 元素的 行指针

