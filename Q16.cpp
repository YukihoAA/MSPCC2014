/*
	볼링게임
	총 10프레임을 투구하며, 각 프레임은 최고 2회(10프레임은 3회) 투구한다. 총 최고 21회 투구한다.

	미스: 두번 투구해서 모두 쓰러트리지 못했을때, (2회의 합산이 점수)
	스페어: 두번째 투구에서 모두 쓰러트렸을때, (10 + 바로 다음 투구의 핀수)
	스트라이크: 1회 투구에서 모두 쓰러트렸을때, (10 + 다음 투구의 핀수 + 다다음 투구의 핀수)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct frame{
	int first;
	int second;
};

int main(void)
{
	int total=0, player=0, i=0, j=0, k=0, score=0;
	int *arr=NULL;
	frame *frm=NULL;
	FILE *fp=fopen("input.txt", "r");
	fscanf(fp,"%d", &player);
	if(player>100)
	{
		printf("error");
		fclose(fp);
		system("pause");
		return 1;
	}
	for(i=0; i<player; i++)
	{
		try{
			fscanf(fp, "%d", &total);
			if(total < 11 || total>21)
			{
				printf("error\n");
				continue;
			}
			arr=(int *) calloc(total, sizeof(int));
			frm=(frame *) calloc(11, sizeof(frame));
			for(j=0; j<total; j++)
			{
				fscanf(fp, "%d ", &arr[j]);
				if(arr[j]>10)
				{
					score=-1;
					break;
				}
			}
			if(score==-1)
			{
				printf("error\n");
				score=0;
				free(frm);
				free(arr);
				arr=NULL;
				arr=NULL;
				continue;
			}
			for(j=0, k=0; j<10; j++)
			{
				if(j==9&&arr[k]==10)
				{
					frm[j].first=10;
					frm[++j].first=arr[++k];
					frm[j].second=arr[++k];
					if(k!=total-1||k>total)
					{
						score=-1;
						break;
					}
				}
				else if(arr[k]==10)
					frm[j].first=arr[k++];
				else
				{
					if(j==9&&(arr[k]+arr[k+1]==10))
					{
						frm[j].first=arr[k++];
						frm[j].second=arr[k++];
						frm[++j].first=arr[k];
						if(k!=total-1||k>total)
						{
							score=-1;
							break;
						}
					}
					else
					{
						frm[j].first=arr[k++];
						frm[j].second=arr[k++];
					}
					if(frm[j].first+frm[j].second>10 || k>total)
					{
						score=-1;
						break;
					}
				}
			}
			if(score==-1)
			{
				printf("error\n");
				score=0;
				free(frm);
				free(arr);
				arr=NULL;
				arr=NULL;
				continue;
			}

			for(j=0; j<10; j++)
			{
				if(frm[j].first+frm[j].second<10)
					score+=frm[j].first+frm[j].second;
				else if(j==9&&frm[j].first==10)
					score+=10+frm[j+1].first+frm[j+1].second;
				else if(frm[j].first==10)
					score+=frm[j].first+(frm[j+1].first==10?(frm[j+1].first+frm[j+2].first):frm[j+1].first+frm[j+1].second);
				else if(frm[j].first+frm[j].second==10)
					score+=10+frm[j+1].first;
			}

			if(score==-1)
				printf("error\n");
			else
				printf("%d\n", score);
			score=0;
			free(frm);
			free(arr);
			arr=NULL;
			arr=NULL;
		}
		catch(...){
			printf("error\n");
		}
	}
	fclose(fp);
	system("pause");
	return 0;
}