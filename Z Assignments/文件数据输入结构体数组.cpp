#include <iostream>
#include <cstring>
using namespace std;
struct pf
{
	char name[10];
	int mark;
}pfm[8];
int main()
{
	FILE *fp = fopen("in.txt","r") , *ft = fopen("out.txt","w");
	
	for(int i=0;i<8;i++) fscanf(fp,"%s %d",&pfm[i].name,&pfm[i].mark);
	for(int i=0;i<8;i++) fprintf(ft,"%s %d\n",pfm[i].name,pfm[i].mark);
	cout << pfm[0].mark << endl;

	fclose(fp) , fclose(ft);
	return 0;
}
