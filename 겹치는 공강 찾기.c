#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i=0;
	char my[30]={0,};
	char fr[30]={0,};
	char day[5][3]={"��","ȭ","��","��","��"};
	FILE *fmy=NULL,*ffr=NULL;
	fmy=fopen("mytime.txt","r");
	ffr=fopen("friendtime.txt","r");
	
	for(i=0;i<30;i++)
	{
		fscanf(fmy,"%c ",&my[i]);
		fscanf(ffr,"%c ",&fr[i]);
	}
	fclose(fmy);
	fclose(ffr);
	fmy=NULL;
	ffr=NULL;

	printf(" [ ��ġ�� ���� ã���ִ� ���α׷� ]\n"
		     "  cf) ������ \"-\"�� ������ \"o\"�� ǥ�õ˴ϴ�!\n"
			 " < My Timetable >\n");
	printf("\tMON\tTUE\tWED\tTHU\tFRI\n");
	for(i=0;i<30;i++)
	{
		if(i%5==0)
			printf("%d\t",i/5+1);
		printf("%c\t",my[i]);
		if(i%5==4)
			printf("\n");
	}
	printf("\n\n< Friend's Timetable >\n");
	printf("\tMON\tTUE\tWED\tTHU\tFRI\n");
	for(i=0;i<30;i++)
	{
		if(i%5==0)
			printf("%d\t",i/5+1);
		printf("%c\t",fr[i]);
		if(i%5==4)
			printf("\n");
	}

	printf("\n\n< ��ġ�� ���� >\n");
	for(i=0;i<30;(i>=25&& i!=29)?(i=i%5+1):(i+=5))
	{
		if(my[i]=='-' && fr[i]=='-')
		{
			printf("%s���� %d����\n",day[i%5],i/5+1);
		}
	}
	system("pause");
	return 0;
}