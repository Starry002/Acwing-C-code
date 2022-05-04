#include <stdio.h>
#include <string.h>
void fun(char *s, char t[])
{
	for(int i=0,j=0;*s != '\0';i++,s++)
		if(i%2==1)  t[j] = *s , j++;
}
main()
{
	FILE *fp = fopen("zifuchuan.txt","r");
	char s[100] , t[100];
	printf("Please enter string S:\n"); 
	fscanf(fp,"%s",s);
	fun(s, t);
	printf("The result is: %s\n", t);
}
