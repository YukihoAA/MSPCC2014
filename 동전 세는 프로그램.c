#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int input = 0;
	while (1)
	{
		printf("�Ž����� �Է�\n");
		scanf("%d", &input);
		fflush(stdin);
		if (input > 1000000000 || input < -1000000000)
			printf("-10��� �̻� ~ 10��� ���Ϸ� �Է����ּ���.\n\n");
		else
			break;
	}
	if(input<0)
	{
		input*=-1;
		printf("����� %d������ ����մϴ�.\n",input);
	}

	printf("�Ž�����(���� ��)\n");
	printf("500�� ����: %d��\n",input/500);
	printf("100�� ����: %d��\n",(input-=input/500*500)/100);
	printf("50�� ����: %d��\n",(input-=input/100*100)/50);
	printf("10�� ����: %d��\n",(input-=input/50*50)/10);

	system("pause");
	return 0;
}