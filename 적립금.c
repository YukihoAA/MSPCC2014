#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int money=0,price=0,point=0,use=0;
	char ch=0;
	FILE *fmoney=NULL,*fpoint=NULL;
	fmoney=fopen("�����ܰ�.txt","r");
	fpoint=fopen("������.txt","r");
	
	fscanf(fmoney,"%d",&money);
	fscanf(fpoint,"%d",&point);

	fclose(fmoney);
	fclose(fpoint);
	fmoney=NULL;
	fpoint=NULL;

	printf("[ ������ ���α׷� ]\n\n\n... ���� ���� �ܰ� : %d��, ������ : %d��\n",money,point);
buy:
	printf("\n�����Ͻ� ������ ���� : ");
	scanf("%d",&price);
	fflush(stdin);

	if(price>money)
	{
		printf("���� ���� �ܰ� �����մϴ�. �����Ͻ� ������ ������ �ٽ� �Է����ּ���\n");
		goto buy;
	}

retype:
	printf("�������� ����Ͻðڽ��ϱ�?\n--> ");

	if((ch=getchar()) == 'n')
	{
		point+=price/20;
		money-=price;
		printf("%d�� �����Ǿ����ϴ�...",price/20);
	}
	else if(ch=='y')
	{
reuse:
		printf("\n\n����Ͻ� �������� �Է��ϼ��� : ");
		scanf("%d",&use);
		fflush(stdin);
		if(use>point)
		{
			printf("���� �������� �����մϴ�. ����� �������� �ٽ� �Է����ּ���\n");
			goto reuse;
		}
		price-=use;
		point-=use;
		money-=price;
		printf("������ ����ϼż� %d�� �����Ǿ����ϴ�...",price);
	}
	else
	{
		printf("y/n���� �Է����ּ���.\n");
		goto retype;
	}
	fmoney=fopen("�����ܰ�.txt","w+");
	fpoint=fopen("������.txt","w+");
	
	fprintf(fmoney,"%d",money);
	fprintf(fpoint,"%d",point);

	fclose(fmoney);
	fclose(fpoint);
	fmoney=NULL;
	fpoint=NULL;
	
	printf("\n\n... ���� ���� �ܰ� : %d��, ������ : %d��\n",money,point);
	system("pause");
	return 0;
}