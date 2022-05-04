#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int print()
{
	printf("===============================\n");
	printf("=========C语言 关机程序========\n");
	printf("*1.实现10分钟内的定时关闭计算机\n");
	printf("*2.立即关闭计算机\n");
	printf("*3.注销计算机\n");
	printf("*0.退出系统\n");
	printf("===============================\n");
} 
int main()
{
	system("title C语言关机程序");
	system("mode con cols=150 lines=100");
	system("color C");
	system("date /T");
	system("time /T");
	char cmd[20] = "shutdown -s -t";
	char t[5]="0";
	print();
	int c;
	scanf("%d",&c);
	getchar();
	switch(c)
	{
		case 1:printf("你想在多少秒后自动关闭计算机？（0~600）\n");scanf("%s",t);system(strcat(cmd,t));break;
		case 2:system("shutdown -p");break;
		case 3:system("shutdown -l");break;
		case 0:break;
		default:printf("Error!\n");
	}
	system("pause");
	exit(0);
	return 0;
}

