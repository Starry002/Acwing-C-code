#include <stdio.h>
#include <math.h>
float fun()
{
	float f1 = 1 , f2 = 1 , f3 , r1 = 2 , r2;
	do{r2=r1; r1=f1/f2; f3=f1+f2; f1=f2; f2=f3;} while(fabs(r1-r2) > 1e-4); 
	return r1;
}
int main()
{
	printf("y=%f\n",fun());
}
