#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

#define EMPTY 0
#define OBST 1
#define VISITED 2

#define DOWN 0
#define UP 1
#define LEFT 2
#define RIGHT 3
#define FRONT 4
#define BACK 5

int n,m,k,l;

int spacePos[60*3600+10];char posExist[60*3600+10];

int GETPOS(int*pos)
{
	return pos[2]*m*n+pos[1]*n+pos[0];
}

void getPos(int i,int*pos)
{
	int now=spacePos[i];
	pos[2]=now/(m*n);now%=(m*n);
	pos[1]=now/n;now%=n;
	pos[0]=now;
}

int eglible(int*pos)
{
	if(pos[0]<0||pos[0]>=n||pos[1]<0||pos[1]>=m||pos[2]<0||pos[2]>=k)
		return 0;
	return 1;
}

int dir[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};

int existIn(int*pos)
{
	int realPos=GETPOS(pos);
	if(posExist[realPos]=='0')
		return 0;
	return 1;
}

void generate_pos(int realPos,int*oldpos)
{
	oldpos[2]=realPos/(m*n);
	realPos%=(m*n);
	oldpos[1]=realPos/n;
	oldpos[0]=realPos%n;
}

int bfs(int*oldpos)
{
	int realPos=GETPOS(oldpos);
	queue<int>visQue;
	visQue.push(realPos);
	int num=0;
	while(!visQue.empty())
	{
		realPos=visQue.front();visQue.pop();
		generate_pos(realPos,oldpos);
		for(int i=0;i<6;i++)
		{
			int pos[3];
			for(int j=0;j<3;j++)
				pos[j]=oldpos[j]+dir[i][j];
			int realPos2=GETPOS(pos);
			if(eglible(pos)==1)
			{
				if(posExist[realPos2]==EMPTY)
				{
					posExist[realPos2]=VISITED;
					visQue.push(realPos2);
				}
				else if(posExist[realPos2]==OBST)
					num++;
			}
		}
	}
	return num;
}

int dfs(int*oldpos)
{
	int num=0;
	for(int i=0;i<6;i++)
	{
		int pos[3];
		for(int j=0;j<3;j++)
			pos[j]=oldpos[j]+dir[i][j];
		int realPos=GETPOS(pos);
		if(eglible(pos)==1)
		{
			if(posExist[realPos]==EMPTY)
			{
				posExist[realPos]=VISITED;
				num+=dfs(pos);
			}
			else if(posExist[realPos]==OBST)
				num++;
			else
				return num;
		}
	}
	return num;
}

int visit(int FLG)
{
	int n1;int m1;
	switch(FLG)
	{
	case DOWN:
	case UP  : n1=n;m1=m;break;
	case LEFT:
	case RIGHT:n1=n;m1=k;break;
	case FRONT:
	case BACK :n1=m;m1=k;break;
	}
	int num=0;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<m1;j++)
		{
			int pos[3];
			switch(FLG)
			{
			case DOWN:pos[0]=i;pos[1]=j;pos[2]=0;break;
			case UP  :pos[0]=i;pos[1]=j;pos[2]=k-1; break;
			case LEFT:pos[0]=i;pos[1]=0;pos[2]=j;break;
			case RIGHT:pos[0]=i;pos[1]=m-1;pos[2]=j;break;
			case FRONT:pos[0]=0;pos[1]=i;pos[2]=j;break;
			case BACK :pos[0]=n-1;pos[1]=i;pos[2]=j;break;
			}
			int realPos=GETPOS(pos);
			if(posExist[realPos]==EMPTY)
			{
				posExist[realPos]=VISITED;
				//num+=dfs(pos,-1);
				num+=bfs(pos);
			}
			else if(posExist[realPos]==OBST)
				num++;
		}
	}
	return num;
}

int main()
{
	while(scanf("%d%d%d%d",&n,&m,&k,&l))
	{
		memset(spacePos,0,sizeof(int)*(60*3600+10));
		memset(posExist,0,60*3600+10);
		if(n==0&&m==0&&k==0)
			break;
		for(int i=0;i<l;i++)
		{
			scanf("%d",spacePos+i);
			posExist[spacePos[i]]=OBST;
		}
		int num=0;
		for(int i=0;i<6;i++)
			num=num+visit(i);
		printf("The number of faces needing shielding is %d.\n",num);
	}
}