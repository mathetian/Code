#include<stdio.h>
#include<queue>
using namespace std;

char maps[80][80];

int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};int height;int width;
typedef struct POINT{
	int x,y;int step;
	bool operator==(POINT p1)
	{
		if(x==p1.x&&y==p1.y)
			return 1;
		return 0;
	}
}POINT;

int bfs(POINT beg,POINT dest)
{
	queue<POINT>dpQ;
	beg.step=0;
	dpQ.push(beg);
	int visited[80][80];memset(visited,0,sizeof(int)*6400);
	visited[beg.x][beg.y]=1;
	while(!dpQ.empty())
	{
		beg=dpQ.front();dpQ.pop();
		if(beg==dest)
			return beg.step;
		for(int i=0;i<4;i++)
		{
			int x1=beg.x+dir[i][0];
			int y1=beg.y+dir[i][1];
			while(x1>=0&&x1<=height+1&&y1>=0&&y1<=width+1)
			{
				POINT now;now.x=x1;now.y=y1;
				if(now==dest)
					return beg.step+1;
				if(maps[x1][y1]==' '&&visited[x1][y1]==0)
				{
					now.step=beg.step+1;
					visited[x1][y1]=1;
					dpQ.push(now);
				}
				else
					break;
				x1+=dir[i][0];y1+=dir[i][1];
			}
		}
	}
	return -1;
}

int main()
{
	int cases=1;
	while(scanf("%d%d",&width,&height))
	{
		if(width==0&&height==0)
			break;
		char c;
		for(int i=0;i<=width+1;i++)
			maps[0][i]=maps[height+1][i]=' ';
		for(int i=0;i<=height+1;i++)
			maps[i][0]=maps[i][width+1]=' ';
		getchar();
		for(int i=1;i<=height;i++)
		{
			for(int j=1;j<=width;j++)
			{
				char c;
				c=getchar();
				maps[i][j]=c;
			}
			getchar();
		}
		POINT beg,dest;int num=1;
		printf("Board #%d:\n",cases++);
		while(scanf("%d%d%d%d",&beg.y,&beg.x,&dest.y,&dest.x))
		{
			if(beg.x==0&&beg.y==0&&dest.x==0&&dest.y==0)
				break;
			int val=bfs(beg,dest);
			printf("Pair %d: ",num++);
			if(val==-1)
				puts("impossible.");
			else
				printf("%d segments.\n",val);
		}
		putchar('\n');
	}
	return 0;
}