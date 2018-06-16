#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n=0, result=0, num=0;
	int i=0, j=0;
	int arr[20][20]={0,};

	for(;;)
	{
		printf("Please enter any value for nXn array : ");
		result = scanf("%d",&n);
		
		if(result != 1 || n < 1 || n > 20)
		{
			printf("Please enter number (1~20)\n");
			while(getchar()!='\n');
		}
		else
			break;
	}

	if(n==1)
	{
		printf("%4d\n",1);
		return 0;
	}

	//ù �� ���
	for(j=0;j < n ; j++)
		arr[i][j]=++num;
	j--;

	//ù �캯 ���
	for(i=1; i < n ; i++)
		arr[i][j]=++num;

	for(;num<n*n;)
	{
		//�Ʒ��� ���
		for(i--, j--; j >= n-i-1 ; j--)
			arr[i][j]=++num;

		//�º� ���
		for(j++, i--; i > j ; i--)
			arr[i][j]=++num;

		//���� ���
		for(i++, j++; j < n-i ; j++)
			arr[i][j]=++num;

		//�캯 ���
		for(j--, i++; i <= j ; i++)
			arr[i][j]=++num;
	}
	
	for(i=0; i < n ; i++)
	{
		for(j=0; j < n ; j++)
		{
			printf("%4d", arr[i][j]);
		}
		putchar('\n');
	}

	return 0;
}