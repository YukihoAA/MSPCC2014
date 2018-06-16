/*
구슬을 끼는 프로그램 

A~Z까지의 색이 있고 각 구슬은 두개의 색을 가지며 이웃한 구슬의 부분은 같은 색을 가져야한다. (마지막도 마찬가지)

구슬을 입력할 갯수를 입력받고, 색을 입력한다.

그 뒤 입력받은 색으로 목걸이를 만들 수 있는지를 확인한다.

이는 오일러회로가 존재하는가에 대한 문제이다

단순히 가능한가 아닌가를 판단하려면 모든 정점(색)의 차수가 짝수이거나 단 두 정점의 차수가 홀수인가를 판단하면 되지만

이 경우에는 예시를 보이라고 했기 때문에 해당 알고리즘은 사용할 수 없다.

이 경우 직접 경로를 그려나가는 아주 비 효율적인 알고리즘을 사용해야한다.

오일러 회로가 존재한다면 어떤 정점에서 시작해도 항상 같은 결과가 나온다. 따라서 시작색은 언제나 랜덤하게 설정할 수 있다.

시작색을 랜덤하게 설정하고 이웃한 다른 색을 다음 색으로 지정해 검색해서 결과가 없다면 해당 구슬 조합은 Fail이다.

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