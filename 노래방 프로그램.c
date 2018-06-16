#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SONG{
	char *name;
	char *lyric;
}SONG;

int main(void)
{
	int size=0,input=0,i=0;
	char name[1024], lyric[1024];
	SONG *list=(SONG *)calloc(0,sizeof(SONG));
	FILE *fp=fopen("song.txt","r");
	for(;!feof(fp);)
	{
		size++;
		list=(SONG *)realloc(list,size*sizeof(SONG));
		fscanf(fp,"%[^\t]\t%[^\n]\n",name,lyric);
		name[1]='\t';
		list[size-1].name=(char *)calloc(strlen(name)+1,sizeof(char));
		list[size-1].lyric=(char *)calloc(strlen(lyric)+1,sizeof(char));
		strcpy(list[size-1].name,name);
		strcpy(list[size-1].lyric,lyric);
		strcpy(name,"");
		strcpy(lyric,"");
	}
	fclose(fp);
	fp=NULL;

	printf("\tMSP�뷡�濡 ���Ű��� ȯ���մϴ�!\n\n"
		"\t��ȣ\t����  -  �뷡����\n"
		"\t------------------------------------\n");
	for (i = 0; i < size; i++)
	{
		printf("\t%s\n", list[i].name);
	}
		
	while(1)
	{
		printf("\n\t�뷡 ��ȣ�� �Է����ּ���.\n\t(0�� ������ �뷡�����α׷��� ����˴ϴ�.) : ");
		scanf("%d",&input);
		fflush(stdin);
		if(input>size || input < 1)
			printf("\n\t**��ȣ�� �߸� �ԷµǾ����ϴ�.**\n");
		else if(input == 0)
			break;
		else
			printf("\n\t%s\n",list[input-1].lyric);
	}
	for(i=0;i<size;i++)
	{
		free(list[i].name);
		free(list[i].lyric);
		list[i].name=NULL;
		list[i].lyric=NULL;
	}
	free(list);
	list=NULL;
	system("pause");
	return 0;
}