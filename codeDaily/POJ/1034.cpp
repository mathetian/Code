#include<stdio.h>
#include<math.h>
#include<string.h>

int maps[101][101];
double masterPoint[101][2];double entPoint[101][2];int result[101];int use[101];int link[101];int N,M;

double dist(int i,int j,int flag)
{
	if(flag==0)
		return sqrt((masterPoint[i][0]-masterPoint[j][0])*(masterPoint[i][0]-masterPoint[j][0])+(masterPoint[i][1]-masterPoint[j][1])*(masterPoint[i][1]-masterPoint[j][1]));
	else
		return sqrt((masterPoint[i][0]-entPoint[j][0])*(masterPoint[i][0]-entPoint[j][0])+(masterPoint[i][1]-entPoint[j][1])*(masterPoint[i][1]-entPoint[j][1]));
}


int can(int n)
{
	for(int i=0;i<M;i++)
	{
		if(use[i]==0&&maps[n][i]==1)
		{
			use[i]=1;
			if(link[i]==-1||can(link[i])==1)
			{
				link[i]=n;result[n]=i;return 1;
			}
		}
	}
	return 0;
}

int vis()
{
	memset(link,-1,sizeof(int)*101);int num=0;
	for(int i=0;i<N;i++)
	{
		memset(use,0,sizeof(int)*101);
		if(can(i))
			num++;
	}
	return num;
}

int main()
{
	memset(maps,0,sizeof(int)*101*101);memset(result,-1,sizeof(int)*101);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%lf%lf",&masterPoint[i][0],&masterPoint[i][1]);
	for(int i=0;i<M;i++)
		scanf("%lf%lf",&entPoint[i][0],&entPoint[i][1]);
	for(int i=0;i<N-1;i++)
	{
		for(int j=0;j<M;j++)
		{
			double len1=dist(i,i+1,0);
			double len2=dist(i,j,1);
			double len3=dist(i+1,j,1);
			if(len2+len3<2*len1)
				maps[i][j]=1;
		}
	}
	int total=N+vis();
	printf("%d\n",total);
	for(int i=0;i<N-1;i++)
	{
		printf("%d %d ",(int)masterPoint[i][0],(int)masterPoint[i][1]);
		if(result[i]==-1)
			continue;
		printf("%d %d ",(int)entPoint[result[i]][0],(int)entPoint[result[i]][1]);
	}
	printf("%d %d\n",(int)masterPoint[N-1][0],(int)masterPoint[N-1][1]);
	return 0;
}