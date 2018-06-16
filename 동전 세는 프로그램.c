#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int input = 0;
	while (1)
	{
		printf("거스름돈 입력\n");
		scanf("%d", &input);
		fflush(stdin);
		if (input > 1000000000 || input < -1000000000)
			printf("-10억원 이상 ~ 10억원 이하로 입력해주세요.\n\n");
		else
			break;
	}
	if(input<0)
	{
		input*=-1;
		printf("양수인 %d원으로 계산합니다.\n",input);
	}

	printf("거스름돈(동전 수)\n");
	printf("500원 동전: %d개\n",input/500);
	printf("100원 동전: %d개\n",(input-=input/500*500)/100);
	printf("50원 동전: %d개\n",(input-=input/100*100)/50);
	printf("10원 동전: %d개\n",(input-=input/50*50)/10);

	system("pause");
	return 0;
}