#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int money=0,price=0,point=0,use=0;
	char ch=0;
	FILE *fmoney=NULL,*fpoint=NULL;
	fmoney=fopen("통장잔고.txt","r");
	fpoint=fopen("적립금.txt","r");
	
	fscanf(fmoney,"%d",&money);
	fscanf(fpoint,"%d",&point);

	fclose(fmoney);
	fclose(fpoint);
	fmoney=NULL;
	fpoint=NULL;

	printf("[ 적립금 프로그램 ]\n\n\n... 현재 통장 잔고 : %d원, 적립금 : %d원\n",money,point);
buy:
	printf("\n구매하실 물건의 가격 : ");
	scanf("%d",&price);
	fflush(stdin);

	if(price>money)
	{
		printf("현재 통장 잔고가 부족합니다. 구매하실 물건의 가격을 다시 입력해주세요\n");
		goto buy;
	}

retype:
	printf("적립금을 사용하시겠습니까?\n--> ");

	if((ch=getchar()) == 'n')
	{
		point+=price/20;
		money-=price;
		printf("%d원 적립되었습니다...",price/20);
	}
	else if(ch=='y')
	{
reuse:
		printf("\n\n사용하실 적립금을 입력하세요 : ");
		scanf("%d",&use);
		fflush(stdin);
		if(use>point)
		{
			printf("현재 적립금이 부족합니다. 사용할 적립금을 다시 입력해주세요\n");
			goto reuse;
		}
		price-=use;
		point-=use;
		money-=price;
		printf("적립금 사용하셔서 %d원 결제되었습니다...",price);
	}
	else
	{
		printf("y/n으로 입력해주세요.\n");
		goto retype;
	}
	fmoney=fopen("통장잔고.txt","w+");
	fpoint=fopen("적립금.txt","w+");
	
	fprintf(fmoney,"%d",money);
	fprintf(fpoint,"%d",point);

	fclose(fmoney);
	fclose(fpoint);
	fmoney=NULL;
	fpoint=NULL;
	
	printf("\n\n... 현재 통장 잔고 : %d원, 적립금 : %d원\n",money,point);
	system("pause");
	return 0;
}