#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int ccx[100];int ccy[100];
int hash2[2][10000];int pairNum[2];
int flag[2][100][100];
int ccNum;int width,height;int pointNum;

int dirX[]={1,-1,0,0};
int dirY[]={0,0,1,-1};

void dfs(int cat,int cx,int cy)
{
	flag[cat][cx][cy]=0;ccx[ccNum]=cx;ccy[ccNum++]=cy;
	for(int i=0;i<4;i++)
	{
		if(cx+dirX[i]>=0&&cx+dirX[i]<height)
		{
			if(cy+dirY[i]>=0&&cy+dirY[i]<width)
			{
				if(flag[cat][cx+dirX[i]][cy+dirY[i]]==1)
				{
					dfs(cat,cx+dirX[i],cy+dirY[i]);
				}
			}
		}
	}
}

int cmp(const int a,const int b)
{
	return a<b;
}

int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d%d%d",&width,&height,&pointNum);
		memset(flag,0,sizeof(int)*10000*2);
		int tmpx;int tmpy;
		for(int u=0;u<2;u++)
		{
			for(int i=0;i<pointNum;i++)
			{
				scanf("%d%d",&tmpy,&tmpx);
				flag[u][tmpx][tmpy]=1;
			}
		}
		pairNum[0]=0;pairNum[1]=0;
		for(int u=0;u<2;u++)
		{
			for(int i=0;i<height;i++)
			{
				for(int j=0;j<width;j++)
				{
					ccNum=0;
					if(flag[u][i][j]==0)
						continue;
					dfs(u,i,j);
					hash2[u][pairNum[u]]=0;
					for(int m=0;m<ccNum;m++)
					{
						for(int n=m+1;n<ccNum;n++)
						{
							hash2[u][pairNum[u]]+=(ccx[m]-ccx[n])*(ccx[m]-ccx[n])+(ccy[m]-ccy[n])*(ccy[m]-ccy[n]);
						}
					}
					pairNum[u]++;
				}
			}
		}
		if(pairNum[0]!=pairNum[1])
			puts("NO");
		else
		{
			for(int u=0;u<2;u++)
				sort(hash2[u],hash2[u]+pairNum[u],cmp);
			int i;
			for(i=0;i<pairNum[0];i++)
			{
				if(hash2[0][i]!=hash2[1][i])
				{
					puts("NO");break;
				}
			}
			if(i==pairNum[0])
				puts("YES");
		}
	}
	return 0;
}