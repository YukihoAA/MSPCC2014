#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int main(void)
{
	int num=0;
	char buf[82]={0,};

	for(;;)
	{
		printf("코드 한 줄(80자 이내)을 입력해주세요.\n");
		scanf("%81s",buf);
		if(strlen(buf) <= 80)
			break;
		memset(buf,'\0',sizeof(buf));
		fflush(stdin);
	}
	for(size_t i=0; i < strlen(buf); i++)
	{
		if(buf[i]=='(')
			num++;
		else if(buf[i]==')')
			num>0?num--:(num=-100);
	}
	if(num==0 && strchr(buf,'('))
		printf("YES\n");
	else
		printf("NO\n");
	system("pause");
	return 0;
}