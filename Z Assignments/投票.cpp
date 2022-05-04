#include <iostream>
#include <cstring>
using namespace std;
typedef struct
{
	int mark;
	char name[10];
}pf;
pf pfm1 = {0,"Zhangsan"} , pfm2 = {0,"Lisi"};
int main()
{
	FILE *fp = fopen("in.txt","r") , *ft = fopen("out.txt","w");
	
	char s[10];
	while(!feof(fp))
	{
		fscanf(fp,"%s",s);
		if(!strcmp(s,"Zhangsan")) pfm1.mark++;
		else pfm2.mark++;
	}
	fprintf(ft,"%s %d\n",pfm1.name,pfm1.mark);
	fprintf(ft,"%s %d\n",pfm2.name,pfm2.mark);

	fclose(fp) , fclose(ft);
	return 0;
}

