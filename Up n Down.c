#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int answer=0,input=0,i=0,start=0,end=50;
	srand((unsigned)time(NULL));
	answer=rand()%51;
	printf("0-50�� �� �� �ϳ��� �Է��Ͽ� ������ ã�ƺ�����.\n�õ� ���� Ƚ���� 10���Դϴ�\n");
	for(i=1;i<=10;i++)
	{
		printf("%d���� %d ������ ���� �ϳ� �Է����ּ��� > ",start,end);
		scanf("%d",&input);
		fflush(stdin);
		printf("�Է°� : %d ",input);
		if(input>50 || input < 0)
		{
			printf("<��ȿ���� ���� �� �Դϴ�>");
			i--;
		}
		else if(input>answer)
		{
			printf("<���亸�� ū ���� �ԷµǾ����ϴ�>");
			end=input;
		}
		else if(input<answer)
		{
			printf("<���亸�� ���� ���� �ԷµǾ����ϴ�>");
			start=input;
		}
		else
		{
			printf("�����Դϴ�! (�õ� Ƚ�� = %d)\n",i);
			break;
		}
		printf("\n");
	}
	if(i==11)
		printf("�õ� ���� Ƚ���� �ʰ��߽��ϴ�.\n");
	system("pause");
	return 0;
}