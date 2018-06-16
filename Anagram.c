#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *v1, const void *v2)
{
	if(*(char *)v1<*(char *)v2)
		return 1;
	else if(*(char *)v1>*(char *)v2)
		return -1;
	else
		return 0;
}

void codestr(char *str)
{
	unsigned i=0,len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]<='z' && str[i]>='a')
			str[i]-=32;
		else if(str[i]<='Z' && str[i]>='A')
			continue;
		else
			str[i]=0;
	}
	qsort(str,len+1,sizeof(char),compare);
}

int main(void)
{
	char str1[1024]="",str2[1024]="",sel=0;

	while(1)
	{
		printf("Input the 1st sentence: ");
		scanf("%[^\n]",str1);
		fflush(stdin);
		printf("Input the 2nd sentence: ");
		scanf("%[^\n]",str2);
		fflush(stdin);

		codestr(str1);
		codestr(str2);

		if(strcmp(str1,str2))
			printf("No! They are not anagrams!!");
		else
			printf("Yes! They are anagrams!!");
		
		printf("\nContinue? (y/N)");
		scanf("%c",&sel);
		fflush(stdin);
		putchar('\n');
		if(sel=='n' || sel=='N')
			break;
	}
	printf("Thank you !!\n");
	system("pause");
	return 0;
}