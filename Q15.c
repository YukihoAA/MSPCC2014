/*
������ ���� ���α׷� 

A~Z������ ���� �ְ� �� ������ �ΰ��� ���� ������ �̿��� ������ �κ��� ���� ���� �������Ѵ�. (�������� ��������)

������ �Է��� ������ �Է¹ް�, ���� �Է��Ѵ�.

�� �� �Է¹��� ������ ����̸� ���� �� �ִ����� Ȯ���Ѵ�.

�̴� ���Ϸ�ȸ�ΰ� �����ϴ°��� ���� �����̴�

�ܼ��� �����Ѱ� �ƴѰ��� �Ǵ��Ϸ��� ��� ����(��)�� ������ ¦���̰ų� �� �� ������ ������ Ȧ���ΰ��� �Ǵ��ϸ� ������

�� ��쿡�� ���ø� ���̶�� �߱� ������ �ش� �˰����� ����� �� ����.

�� ��� ���� ��θ� �׷������� ���� �� ȿ������ �˰����� ����ؾ��Ѵ�.

���Ϸ� ȸ�ΰ� �����Ѵٸ� � �������� �����ص� �׻� ���� ����� ���´�. ���� ���ۻ��� ������ �����ϰ� ������ �� �ִ�.

���ۻ��� �����ϰ� �����ϰ� �̿��� �ٸ� ���� ���� ������ ������ �˻��ؼ� ����� ���ٸ� �ش� ���� ������ Fail�̴�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _BEAD{
	char c1;
	char c2;
}BEAD;

char search(BEAD *arr, int *total, char c)
{
	int i=0, j=0;
	char ret=0;
	for(i=0; i<*total; i++)
	{
		if(arr[i].c1==c || arr[i].c2==c)
		{
			if(arr[i].c1==c)
				ret=arr[i].c2;
			else
				ret=arr[i].c1;
			for(j=i; j<(*total)-1; j++)
			{
				arr[j]=arr[j+1];
			}
			(*total)--;
			return ret;
		}
	}
	return 0;
}

int main(void)
{
	int total=0, i=0;
	char *str=NULL, res=0, c1=0;
	_Bool Fail=0;
	BEAD *arr=NULL;
START:
	printf("Insert the number of bead you\'re gonna choose(5~100): ");
	scanf("%d", &total);
	fflush(stdin);

	if(total<5||total>100)
		goto START;
	arr=(BEAD *) calloc(total-1, sizeof(BEAD));
	str=(char *) calloc(total*7, sizeof(char));
	printf("Insert two colors of each bead (%d)", total);
	total--;
	printf("\n=> 1. : ");
	scanf("%c %c", &c1, &res);
	fflush(stdin);
	for(i=0; i<total; i++)
	{
		printf("=> %d. : ", i+2);
		scanf("%c %c", &arr[i].c1, &arr[i].c2);
		fflush(stdin);
	}

	printf("This is YOUR BEADS you picked.\n");

	printf("[%c, %c] ", c1, res);
	for(i=0; i<total; i++)
	{
		printf("[%c, %c] ", arr[i].c1, arr[i].c2);
	}

	sprintf(str, "[%c, %c] [%c, ", c1, res, res);
	while(total>0)
	{
		res=search(arr, &total, res);
		if(res!=0 && total >= 1)
			sprintf(str, "%s%c] [%c, ", str, res, res);
		else if(res==c1)
			sprintf(str, "%s%c]", str, res);
		else
		{
			Fail=1;
			break;
		}
	}
	if(!Fail)
		printf("\n\nIt's Possible to make complete Bracelet as follows!!\n%s", str);
	else
		printf("\n\nIt's IMPOSSIBLE to make complete Bracelet!!");

Q:
	printf("\n\nOne MORE ?? ;-> : ");
	scanf("%c",&c1);
	fflush(stdin);
	if(c1=='Y'||c1=='y')
	{
		free(arr);
		free(str);
		total=0, i=0;
		str=NULL, res=0, c1=0;
		Fail=0;
		arr=NULL;
		printf("\n==================================================\n\n");
		goto START;
	}
	else if(c1=='N'||c1=='n')
		return 0;
	else
		goto Q;
	return 0;
}