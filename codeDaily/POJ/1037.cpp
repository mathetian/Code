#include<stdio.h>
#include<string.h>

typedef long long ll;
int K,N;ll C;
typedef struct{
	ll up;ll down;
}PLANK;

PLANK planks[21][21];int realVal[21];int LessPos[21];
/*
	flag:   0 up 1 down
	oldPos: 上一个从1~N-num+1 中选择的那个数
	num:    已经选择了的个数
	total:  以oldPos在前的个数
*/
void dfs(int flag,int oldPos,int num,ll total)
{
	while(num!=N)
	{
	//	printf("%d\n",num);
		if(flag==0)//up
		{
		for(int i=oldPos;i<=N-num;i++)
		{
			total+=planks[N-num][i].down;
			if(total>=C)
			{
				total-=planks[N-num][i].down;
				realVal[num+1]=i+LessPos[i];
				for(int j=i;j<=N-num-1;j++)
					LessPos[j]=LessPos[j+1]+1;
				LessPos[N-num]=0;
				flag=1;oldPos=i;num=num+1;break;
			}
		}
	}
	else
	{
		for(int i=1;i<=oldPos-1;i++)
		{
			total+=planks[N-num][i].up;
			if(total>=C)
			{
				total-=planks[N-num][i].up;
				realVal[num+1]=i+LessPos[i];
				for(int j=i;j<=N-num-1;j++)
					LessPos[j]=LessPos[j+1]+1;
				LessPos[N-num]=0;
				flag=0;oldPos=i;num=num+1;break;
			}
		}
	}
	}
	if(num==N)
	{
		for(int i=1;i<N;i++)
			printf("%d ",realVal[i]);
		printf("%d\n",realVal[N]);
	}
}

int main()
{

	scanf("%d",&K);
	while(K--)
	{
		scanf("%d%lld",&N,&C);
		for(int i=1;i<=N;i++)
			LessPos[i]=0;
		memset(planks,0,sizeof(PLANK)*21*21);
		planks[1][1].down=1;planks[1][1].up=1;
		for(int n=2;n<=N;n++)
		{
			for(int T=1;T<=n;T++)
			{
				for(int k=T;k<n;k++)
					planks[n][T].up+=planks[n-1][k].down;
				for(int k=1;k<T;k++)
					planks[n][T].down+=planks[n-1][k].up;
			}
		}
		long long total=0;int nowPos=1;int flag=0;int oldPos;
		int i=1;
		while(total<C)
		{
			total+=planks[N][nowPos].down;
			if(total>=C)
			{	total-=planks[N][nowPos].down;realVal[1]=nowPos;flag=1;oldPos=nowPos;
				for(int i=nowPos;i<=N-1;i++)
					LessPos[i]+=1;
				LessPos[N]=0;
				break;
			}
			total+=planks[N][nowPos].up;
			if(total>=C)
			{	total-=planks[N][nowPos].up;realVal[1]=nowPos;oldPos=nowPos;
				for(int i=nowPos;i<=N-1;i++)
					LessPos[i]+=1;
				LessPos[N]=0;
				break;
			}
			nowPos++;
		}
		dfs(flag,oldPos,1,total);
	}
	return 0;
}