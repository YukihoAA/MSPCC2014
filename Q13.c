/*입력받은 두 수 사이의 소수 구하기

소수: 1과 자기 자신 이외에는 나누어 지지 않는 수,

소수 배열을 선언하여, 입력받은 정수까지의 소수들을 저장한다 (동적할당)

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *prime=(int *)calloc(0,sizeof(int)), psize=0;
	int start=0, end=0, i=0, j=0;

START:
	printf("1부터 300사이 정수 두개 입력 : ");
	scanf("%d %d", &start, &end);

	if(start < 1 || start > 300 || end < 1 || end > 300)
	{
		printf("\n1부터 300사이로 입력해주세요.\n\n");
		goto START;
	}
	else if(start>end)
	{
		i=start;
		start=end;
		end=i;
		i=0;
	}

	for(i=2; i<=start; i++)
	{
		for(j=0; j<psize; j++)
		{
			if(i % prime[j] == 0)
				continue;
		}
		prime=(int *)realloc(prime,sizeof(int) * ++psize);
		prime[psize-1]=i;
	}

	for(; i<end; i++)
	{
		for(j=0; j<psize; j++)
		{
			if(i % prime[j] == 0)
				break;
		}
		if(j==psize)
		{
			prime=(int *)realloc(prime,sizeof(int) * ++psize);
			prime[psize-1]=i;
			printf("%d\n",i);
		}
	}

	free(prime);
	return 0;
}