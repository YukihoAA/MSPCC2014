/*
숫자를 영문으로 바꾸는 프로그램

천, 백의 자리는 그냥 수에 + 단위, 십의 자리는 모두 다르고, 일의 자리는 그냥 수를 출력한다. 특히 10~19는 특이하다.

천의 자리부터 출력해야한다. 이를 위해 배열에 저장한다.


*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i=0, d=0;
	printf("정수를 입력해주세요 : ");
	scanf("%d",&d);
	if(d>9999 || d<0)
		printf("Out of Range!\n");
	else
	{
		printf("결과값: ");
		if(d==0)
		{
			printf("Zero");
			goto END;
		}
		switch (d/1000)
		{
		case 0:
			break;
		case 1:
			printf("one");
			break;
		case 2:
			printf("two");
			break;
		case 3:
			printf("three");
			break;
		case 4:
			printf("four");
			break;
		case 5:
			printf("five");
			break;
		case 6:
			printf("six");
			break;
		case 7:
			printf("seven");
			break;
		case 8:
			printf("eight");
			break;
		case 9:
			printf("nine");
			break;
		}
		if(d>=1000)
			printf(" thousand ");
		d%=1000;
		switch (d/100)
		{
		case 0:
			break;
		case 1:
			printf("one");
			break;
		case 2:
			printf("two");
			break;
		case 3:
			printf("three");
			break;
		case 4:
			printf("four");
			break;
		case 5:
			printf("five");
			break;
		case 6:
			printf("six");
			break;
		case 7:
			printf("seven");
			break;
		case 8:
			printf("eight");
			break;
		case 9:
			printf("nine");
			break;
		}
		if(d>=100)
			printf(" hundred ");
		d%=100;
		switch (d/10)
		{
		case 0:
			break;
		case 1:
			switch (d)
			{
			case 10:
				printf("ten");
				break;
			case 11:
				printf("eleven");
				break;
			case 12:
				printf("twelve");
				break;
			case 13:
				printf("thirteen");
				break;
			case 14:
				printf("fourteen");
				break;
			case 15:
				printf("fifteen");
				break;
			case 16:
				printf("sixteen");
				break;
			case 17:
				printf("seventeen");
				break;
			case 18:
				printf("eighteen");
				break;
			case 19:
				printf("nineteen");
				break;
			}
			goto END;
			break;
		case 2:
			printf("twenty");
			break;
		case 3:
			printf("thirty");
			break;
		case 4:
			printf("fourty");
			break;
		case 5:
			printf("fifty");
			break;
		case 6:
			printf("sixty");
			break;
		case 7:
			printf("seventy");
			break;
		case 8:
			printf("eighty");
			break;
		case 9:
			printf("ninety");
			break;
		}
		switch (d%10)
		{
		case 0:
			break;
		case 1:
			printf(" one");
			break;
		case 2:
			printf(" two");
			break;
		case 3:
			printf(" three");
			break;
		case 4:
			printf(" four");
			break;
		case 5:
			printf(" five");
			break;
		case 6:
			printf(" six");
			break;
		case 7:
			printf(" seven");
			break;
		case 8:
			printf(" eight");
			break;
		case 9:
			printf(" nine");
			break;
		}
	}
END:
	putchar('\n');
	system("pause");
	return 0;
}