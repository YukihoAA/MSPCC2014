/*�Է¹��� �� �� ������ �Ҽ� ���ϱ�

�Ҽ�: 1�� �ڱ� �ڽ� �̿ܿ��� ������ ���� �ʴ� ��,

�Ҽ� �迭�� �����Ͽ�, �Է¹��� ���������� �Ҽ����� �����Ѵ� (�����Ҵ�)

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *prime=(int *)calloc(0,sizeof(int)), psize=0;
	int start=0, end=0, i=0, j=0;

START:
	printf("1���� 300���� ���� �ΰ� �Է� : ");
	scanf("%d %d", &start, &end);

	if(start < 1 || start > 300 || end < 1 || end > 300)
	{
		printf("\n1���� 300���̷� �Է����ּ���.\n\n");
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