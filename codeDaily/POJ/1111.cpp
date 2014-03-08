#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

#define MX 50

int input[MX][MX];int row[MX][MX];int col[MX][MX];
int n,r,p,q;char str[MX];int i,j,k;int result;

int flags[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int bFlags[MX][MX];

typedef pair<int,int> iPair;
queue<iPair>ipQ;

int bfs(int a,int b)
{	
	memset(bFlags,0,sizeof(int)*MX*MX);
	bFlags[a][b]=1;
	ipQ.push(make_pair(a,b));
	while(!ipQ.empty())
	{
		iPair tmp=ipQ.front();ipQ.pop();
		for(i=0;i<8;i++)
		{
			int newx=tmp.first+flags[i][0];
			int newy=tmp.second+flags[i][1];
			if(newx<0||newx>=n||newy<0||newy>=r||bFlags[newx][newy]==1||input[newx][newy]==0)
				continue;
			bFlags[newx][newy]=1;
			ipQ.push(make_pair(newx,newy));
			//printf("(%d %d)\n",newx,newy);
		}
	}
	return 1;
}


int main()
{
	
	while(scanf("%d%d%d%d",&n,&r,&p,&q))
	{
		if(n==0&&r==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			for(j=0;j<r;j++)
			{
				if(str[j]=='X')
					input[i][j]=1;
				else
					input[i][j]=0;
			}
		}
		bfs(p-1,q-1);
		memset(row,0,sizeof(int)*MX*MX);
		memset(col,0,sizeof(int)*MX*MX);
		for(i=0;i<n;i++)
		{
			for(j=0;j<r;j++)
			{
				if(bFlags[i][j]==1)
				{
					//printf("%d %d\n",i,j);
					row[i][j]++;col[i][j]++;
					row[i+1][j]++;col[i][j+1]++;
				}
			}
		}
		//printf("(%d)",bFlags[1][5]);
		result=0;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=r;j++)
			{
				if(row[i][j]==1)
				{
					result++;
					//printf("(%d %d)\n",i,j);
				}
					
				if(col[i][j]==1)
					result++;
			}
		}
		printf("%d\n",result);
	}
	return 0;
}