/*
	n���� k���� �̾Ƴ��� �˰���
	
	k���� ���Ұ� ������ (nPk)�� �ش��ϴ� ������ ��ü ���Ҹ� ���Ѵ�.
	
	n���� k���� �̾Ƴ��� ��ü ���Ҵ�
	
	n-1���� k���� �̾Ƴ��� ���Ҹ� �����ϰ�, n���� �ݵ�� �����ϸ� �ٸ� n-1���� k-1���� �̾Ƴ��� ���Ҹ� �����Ѵ�
	
	1/1 - 1
	2/1 - 1, 10
	3/1 - 1, 10, 100
	4/1 - 1, 10, 100, 1000
	
	2/2 - 11
	3/2 - 11, 110, 101
	4/2 - 11, 110, 101, 1001, 1010, 1100
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void prtdigit(unsigned num, unsigned n)
{
	unsigned i=0,flag=0x1;
	for(i=1;i<n;i++)
		flag<<=1;
	for(i=0;i<n;i++)
	{
		printf("%c",num&flag?'1':'0');
		flag>>=1;
	}
}

int compare(const void *v1, const void *v2)
{
	if(*(unsigned *)v1>*(unsigned *)v2)
		return 1;
	else if(*(unsigned *)v1<*(unsigned *)v2)
		return -1;
	else
		return 0;
}

void addtoarr(unsigned arr[], unsigned data, unsigned *last)
{
	arr[*last]=data;
	*last+=1;
}

unsigned totalsize(unsigned n, unsigned k)
{
	unsigned i=0,ret=1;
	if(n==k)
		return 1;
	for(i=0;i<k;i++)
		ret*=n-i;
	for(i=1;i<=k;i++)
		ret/=i;
	return ret;
}

void makenum(unsigned arr[], unsigned n, unsigned k, unsigned *last)
{
	unsigned i=0, tlast=0, flag=0x1;
	unsigned *tmp=NULL;
	if(k<=0 || n<=0)
		return ;
	else if(k==1)
	{
		if(n==1)
		{
			addtoarr(arr,flag,last);
		}
		else
		{
			makenum(arr,n-1,k,last);
			for(i=1;i<n;i++)
				flag<<=1;
			addtoarr(arr,flag,last);
		}
	}
	else if(k==n)
	{
		for(i=1;i<n;i++)
		{
			flag<<=1;
			flag|=1;
		}
		addtoarr(arr,flag,last);
	}
	else
	{
		for(i=1;i<n;i++)
		{
			flag<<=1;
		}
		makenum(arr,n-1,k,last);
		tmp=(unsigned *)calloc(totalsize(n-1,k-1),sizeof(unsigned));
		makenum(tmp,n-1,k-1,&tlast);

		for(i=0;i<tlast;i++)
		{
			addtoarr(arr,flag|tmp[i],last);
		}

		free(tmp);
		tmp=NULL;
	}
}

int main(void)
{
	unsigned i=0, last=0, size=0;
	unsigned n=0,k=0;
	unsigned *arr=NULL;

	while(1)
	{
		printf("���� �ƴ� ���� n�Է�: ");
		scanf("%u", &n);
		fflush(stdin);
		printf("���� �ƴ� ���� k�Է�: ");
		scanf("%u", &k);
		fflush(stdin);

		if (n < k)
			printf("\nn�� k���� ���� �� �����ϴ�.\n\n");
		else if(n<0 || k<0 || n>10 || k>10)
			printf("\nn�� k�� 0-10������ ���� �Է����ּ���.\n\n");
		else
			break;
	}

	if(n!=0 && k!=1)
	{
		size=totalsize(n,k);
		
		arr=(unsigned *)calloc(size,sizeof(unsigned));
		
		makenum(arr, n, k, &last);
		
		qsort(arr,size,sizeof(arr[0]),compare);
		for(i=0;i<size;i++)
		{
			prtdigit(arr[i],n);
			putchar(' ');
		}
		free(arr);
		arr=NULL;
	}
	else if(k==1)
		prtdigit(0,n);
	putchar('\n');
	system("pause");
	return 0;
}