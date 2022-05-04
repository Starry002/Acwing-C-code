#include<stdio.h>
void swap(int &a,int &b)
{   int temp;
    temp=a; a=b; b=temp;
}
int main()
{

  int x=7,y=11;

    printf("x=%d,\ty=%d\n",x,y);

    printf("½»»»ºó\n");

    swap(x,y);

    printf("x=%d,\ty=%d\n",x,y);

    return 0;

}
