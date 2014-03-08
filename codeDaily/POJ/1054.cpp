#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

char maps[5001][5001];
//int pairs[5001][2];
typedef struct{
	int x;int y;
}POINT;

POINT points[5001];int used[5001];

int cmp(const POINT p1,const POINT p2)
{
	if(p1.y<p2.y)
		return 1;
	else  if(p1.y==p2.y)
	{
		if(p1.x<p2.x)
			return 1;
	}
	return 0;
}

int main()
{
	int R,C;int N;
	while(scanf("%d%d",&R,&C)!=EOF)
	{
		scanf("%d",&N);memset(maps,0,5001*5001);
		for(int i=0;i<N;i++)
		{	scanf("%d%d",&points[i].x,&points[i].y);
			maps[points[i].x][points[i].y]=1;
		}
		sort(points,points+N,cmp);
		int k=3;int flag=0;int num=0;
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				if(i==1&&j==3)
				{
					while(0);
				}
				int difx=points[j].x-points[i].x;
				int dify=points[j].y-points[i].y;
				int tmp=2;int stx,sty;
				stx=points[i].x-difx;sty=points[i].y-dify;
				if(stx>=1&&stx<=R&&sty>=1&&sty<=C)
					continue;
				for(stx=points[j].x+difx,sty=points[j].y+dify;stx>=1&&stx<=R&&sty>=1&&sty<=C;stx+=difx,sty+=dify)
				{
					if(maps[stx][sty]==0)
						break;
					tmp++;
				}
				if(stx>=1&&stx<=R&&sty>=1&&sty<=C)
				{
				}
				else
				{
					if(tmp>k)
					{	if(tmp==6)
						{
							while(0);
						}
						k=tmp;flag=1;
					}
				}
			}
		}
		if(flag==1)
			printf("%d\n",k);
		else
			printf("0\n");
	}
	return 0;
}