/*
	64게임 만들기 (Q17)
	세로 6줄 가로 42줄의 콘솔창

	Move 한후 Sum 하고 Move 한다. (모두 밀착하게 바꾼 후 우선순위에 따라 더한 후 다시 모두 밀착시킨다)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int map[4][4]={0,};	//map[Y][X]
int Best=0;
int Score=0;
_Bool Complete=0;
_Bool GameEnd=0;

void AddRandNum(void);

void Init(void)
{
	int i=0, j=0;
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			map[i][j]=0;
		}
	}
	Complete=0;
	Score=0;
	AddRandNum();
}

_Bool full(void)
{
	int i=0, j=0;
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(map[i][j]==0)
				return 0;
		}
	}
	return 1;
}

void prthelp(void)
{
	printf("W : 모든 숫자 위로\n"
		"A : 모든 숫자 왼쪽으로\n"
		"S : 모든 숫자 아래로\n"
		"D : 모든 숫자 오른쪽으로\n"
		"X : 게임종료");
}

void prtmap(void)
{
	int i=0, j=0;
	system("cls");
	for(i=0; i<4; i++)
	{
		printf("+---------+---------+---------+---------+\n"
			"|         |         |         |         |\n|");
		for(j=0; j<4; j++)
		{
			if(map[i][j])
				printf("    %-2d   |",map[i][j]);
			else
				printf("         |");
		}
		printf("\n|         |         |         |         |\n");
	}
	printf("+---------+---------+---------+---------+\n\n"
			"BEST\t: %d\n"
			"SCORE\t: %d\n\n", Best, Score);
}

_Bool canmove(void)
{
	int i=0, j=0;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(map[i][j]==map[i][j+1]||map[i][j]==map[i+1][j])
				return 1;
		}
	}
	return 0;
}

void _MoveRight(_Bool *moved, int y, int x)
{
	int i=0;
	_Bool nonum=1;
	for(i=0; i<x; i++)
	{
		if(map[y][i])
			nonum=0;
	}
	if(map[y][x]==0&&!nonum)
	{
		for(i=x; i>0; i--)
		{
			if(map[y][i-1])
			{
				map[y][i]=map[y][i-1];
				map[y][i-1]=0;
				*moved=1;
			}
		}
		_MoveRight(moved, y, x);
	}
}

void MoveRight(_Bool *moved)
{
	int x=0, y=0;
	for(y=0; y<4; y++)
	{
		for(x=3; x>0; x--)
		{
			_MoveRight(moved, y, x);
		}
	}
}

void SumRight(_Bool *moved)
{
	int x=0, y=0;
	for(y=0; y<4; y++)
	{
		for(x=3; x>0; x--)
		{
			if(map[y][x]!=0&&map[y][x]==map[y][x-1])
			{
				map[y][x]+=map[y][x];
				map[y][x-1]=0;
				Score+=map[y][x];
				*moved=1;
				if(map[y][x]>=64)
					Complete=1;
			}
		}
	}
}

void _MoveLeft(_Bool *moved, int y, int x)
{
	int i=0;
	_Bool nonum=1;
	for(i=x+1; i<=3; i++)
	{
		if(map[y][i])
			nonum=0;
	}
	if(map[y][x]==0&&!nonum)
	{
		for(i=x; i<3; i++)
		{
			if(map[y][i+1])
			{
				map[y][i]=map[y][i+1];
				map[y][i+1]=0;
				*moved=1;
			}
		}
		_MoveLeft(moved, y, x);
	}
}

void MoveLeft(_Bool *moved)
{
	int x=0, y=0;
	for(y=0; y<4; y++)
	{
		for(x=0; x<3; x++)
		{
			_MoveLeft(moved, y, x);
		}
	}
}

void SumLeft(_Bool *moved)
{
	int x=0, y=0;
	for(y=0; y<4; y++)
	{
		for(x=0; x<3; x++)
		{
			if(map[y][x]!=0&&map[y][x]==map[y][x+1])
			{
				map[y][x]+=map[y][x];
				map[y][x+1]=0;
				Score+=map[y][x];
				*moved=1;
				if(map[y][x]>=64)
					Complete=1;
			}
		}
	}
}

void _MoveDown(_Bool *moved, int y, int x)
{
	int i=0;
	_Bool nonum=1;
	for(i=0; i<y; i++)
	{
		if(map[i][x])
			nonum=0;
	}
	if(map[y][x]==0&&!nonum)
	{
		for(i=y; i>0; i--)
		{
			if(map[i-1][x])
			{
				map[i][x]=map[i-1][x];
				map[i-1][x]=0;
				*moved=1;
			}
		}
		_MoveDown(moved, y, x);
	}
}

void MoveDown(_Bool *moved)
{
	int x=0, y=0;
	for(x=0; x<4; x++)
	{
		for(y=3; y>0; y--)
		{
			_MoveDown(moved, y, x);
		}
	}
}

void SumDown(_Bool *moved)
{
	int x=0, y=0;
	for(x=0; x<4; x++)
	{
		for(y=3; y>0; y--)
		{
			if(map[y][x]!=0&&map[y][x]==map[y-1][x])
			{
				map[y][x]+=map[y][x];
				map[y-1][x]=0;
				Score+=map[y][x];
				*moved=1;
				if(map[y][x]>=64)
					Complete=1;
			}
		}
	}
}

void _MoveUp(_Bool *moved, int y, int x)
{
	int i=0;
	_Bool nonum=1;
	for(i=y+1; i<=3; i++)
	{
		if(map[i][x])
			nonum=0;
	}
	if(map[y][x]==0&&!nonum)
	{
		for(i=y; i<3; i++)
		{
			if(map[i+1][x])
			{
				map[i][x]=map[i+1][x];
				map[i+1][x]=0;
				*moved=1;
			}
		}
		_MoveUp(moved, y, x);
	}
}

void MoveUp(_Bool *moved)
{
	int x=0, y=0;
	for(x=0; x<4; x++)
	{
		for(y=0; y<3; y++)
		{
			_MoveUp(moved, y, x);
		}
	}
}

void SumUp(_Bool *moved)
{
	int x=0, y=0;
	for(x=0; x<4; x++)
	{
		for(y=0; y<3; y++)
		{
			if(map[y][x]!=0&&map[y][x]==map[y+1][x])
			{
				map[y][x]+=map[y][x];
				map[y+1][x]=0;
				Score+=map[y][x];
				*moved=1;
				if(map[y][x]>=64)
					Complete=1;
			}
		}
	}
}


void Right(void)
{
	_Bool moved=0;
	MoveRight(&moved);
	/*(prtmap();
	printf("%d", moved);
	_getch();*/
	SumRight(&moved);
	MoveRight(&moved);
	//prtmap();
	//_getch();
	if(moved)
		AddRandNum();
}

void Left(void)
{
	_Bool moved=0;
	MoveLeft(&moved);
	/*(prtmap();
	printf("%d", moved);
	_getch();*/
	SumLeft(&moved);
	MoveLeft(&moved);
	//prtmap();
	//_getch();
	if(moved)
		AddRandNum();
}

void Up(void)
{
	_Bool moved=0;
	MoveUp(&moved);
	/*(prtmap();
	printf("%d", moved);
	_getch();*/
	SumUp(&moved);
	MoveUp(&moved);
	//prtmap();
	//_getch();
	if(moved)
		AddRandNum();
}

void Down(void)
{
	_Bool moved=0;
	MoveDown(&moved);
	/*(prtmap();
	printf("%d", moved);
	_getch();*/
	SumDown(&moved);
	MoveDown(&moved);
	//prtmap();
	//_getch();
	if(moved)
		AddRandNum();
}

void AddRandNum(void)
{
	int x=rand()%4, y=rand()%4, sel=0;
	_Bool End=0;
	if(Complete)
	{
		prtmap();
		if(Best<Score)
		{
			Best=Score;
			printf("%d점으로 BEST Score를 갱신하였습니다!!", Score);
		}
		printf("\n\n게임을 한 번 더 하시겠습니까? (y/n) ");
		while(!End)
		{
			sel=_getch();
			switch(sel)
			{
			case 'N':
			case 'n':
				GameEnd=1;
				End=1;
				break;
			case 'Y':
			case 'y':
				Init();
				End=1;
				break;
			}

		}
	}
	else if(map[y][x]==0)
	{
		map[y][x]=2*(rand()%2+1);
		if(full() && !canmove())
		{
			prtmap();
			printf("64를 만들지 못했습니다.");
			printf("\n\n게임을 한 번 더 하시겠습니까? (y/n) ");
			while(!End)
			{
				sel=_getch();
				switch(sel)
				{
				case 'N':
				case 'n':
					GameEnd=1;
					End=1;
					break;
				case 'Y':
				case 'y':
					Init();
					End=1;
					break;
				}
			}
		}
	}
	else
		AddRandNum();
}

int main(void)
{
	int sel=0;
	_Bool End=0;
	system("mode con cols=42 lines=26");
	srand((unsigned)time(NULL));
	AddRandNum();
	while(!End && !GameEnd)
	{
		prtmap();
		prthelp();
		sel=_getch();
		switch(sel)
		{
		case 'W':
		case 'w':
			Up();
			break;
		case 'A':
		case 'a':
			Left();
			break;
		case 'S':
		case 's':
			Down();
			break;
		case 'D':
		case 'd':
			Right();
			break;
		case 'X':
		case 'x':
			End=1;
			break;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}