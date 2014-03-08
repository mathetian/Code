#include<stdio.h>
#include<string.h>

int maps[101][101];int used[101][101];

int dirX[]={0,0,1,-1};int dirY[]={1,-1,0,0};int row,col;

int able(int i,int j,int k)
{
	int nx=i+dirX[k];int ny=j+dirY[k];
	if(nx>=0&&nx<row&&ny>=0&&ny<col)
		return 1;
	return 0;
}
int mx;

void bfs(int i,int j)
{
	//printf("(%d %d)",i,j);
	for(int k=0;k<4;k++)
	{
		if(able(i,j,k)==0)
			continue;
		int nx=i+dirX[k];int ny=j+dirY[k];
		if(maps[nx][ny]>=maps[i][j])
			continue;
		if(used[nx][ny]==0)
			bfs(nx,ny);
		if(used[i][j]<used[nx][ny]+1)
			used[i][j]=used[nx][ny]+1;
	}
	if(used[i][j]==0)
		used[i][j]=1;
}

int main()
{
	while(scanf("%d%d",&row,&col)!=EOF)
	{
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			scanf("%d",&maps[i][j]);
	mx=0;
	memset(used,0,sizeof(int)*101*101);
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(used[i][j]==0)
				bfs(i,j);
			if(used[i][j]>mx)
				mx=used[i][j];
		}
	}
	printf("%d\n",mx);
	}
	return 0;
}