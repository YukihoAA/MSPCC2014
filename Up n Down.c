#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int answer=0,input=0,i=0,start=0,end=50;
	srand((unsigned)time(NULL));
	answer=rand()%51;
	printf("0-50의 수 중 하나를 입력하여 정답을 찾아보세요.\n시도 가능 횟수는 10번입니다\n");
	for(i=1;i<=10;i++)
	{
		printf("%d부터 %d 사이의 수를 하나 입력해주세요 > ",start,end);
		scanf("%d",&input);
		fflush(stdin);
		printf("입력값 : %d ",input);
		if(input>50 || input < 0)
		{
			printf("<유효하지 않은 수 입니다>");
			i--;
		}
		else if(input>answer)
		{
			printf("<정답보다 큰 값이 입력되었습니다>");
			end=input;
		}
		else if(input<answer)
		{
			printf("<정답보다 작은 값이 입력되었습니다>");
			start=input;
		}
		else
		{
			printf("정답입니다! (시도 횟수 = %d)\n",i);
			break;
		}
		printf("\n");
	}
	if(i==11)
		printf("시도 가능 횟수를 초과했습니다.\n");
	system("pause");
	return 0;
}