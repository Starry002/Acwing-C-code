#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int print()
{
	printf("===============================\n");
	printf("=========C���� �ػ�����========\n");
	printf("*1.ʵ��10�����ڵĶ�ʱ�رռ����\n");
	printf("*2.�����رռ����\n");
	printf("*3.ע�������\n");
	printf("*0.�˳�ϵͳ\n");
	printf("===============================\n");
} 
int main()
{
	system("title C���Թػ�����");
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
		case 1:printf("�����ڶ�������Զ��رռ��������0~600��\n");scanf("%s",t);system(strcat(cmd,t));break;
		case 2:system("shutdown -p");break;
		case 3:system("shutdown -l");break;
		case 0:break;
		default:printf("Error!\n");
	}
	system("pause");
	exit(0);
	return 0;
}

