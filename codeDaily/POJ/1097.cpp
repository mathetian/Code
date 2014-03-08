#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define EPS 1e-9
#define MIN(a,b) a>b?b:a

typedef struct{
	char name[20];int secNo;
}ROAD;

typedef struct{
	char name[20];int dist;
}NAME;

bool operator<(NAME&n1,NAME&n2)
{
	if(n1.dist==n2.dist)
	{
		int flag=strcmp(n1.name,n2.name);
		if(flag==-1)
			return 1;
		return 0;
	}
	return n1.dist<n2.dist?1:0;
}

typedef struct{
	int from,to;
	double distF;
	NAME name2[50];int nameNum;
	void sort_B()
	{
		sort(name2,name2+nameNum);
	}
}SIGN;

int secNum;int roadNum;int citNum;int sigNum;
ROAD roads[50];double maps[50][50];SIGN signs[100];

int get_i(double val)
{
	int newV=(int)(val+0.5);int oldV=(int)val;
	if(newV==oldV)
		return oldV;
	else
		return newV;
}

int main()
{
	scanf("%d%d%d",&secNum,&roadNum,&citNum);
	for(int i=0;i<secNum;i++)
	{
		for(int j=0;j<secNum;j++)
			maps[i][j]=-1;
		maps[i][i]=0;
	}
	for(int i=0;i<roadNum;i++)
	{
		int a,b;double c;
		scanf("%d%d%lf",&a,&b,&c);
		maps[a][b]=c;maps[b][a]=c;
	}
	for(int i=0;i<citNum;i++)
		scanf("%d%s",&roads[i].secNo,roads[i].name);
	scanf("%d",&sigNum);
	for(int i=0;i<sigNum;i++)
	{
		scanf("%d%d%lf",&signs[i].from,&signs[i].to,&signs[i].distF);
		signs[i].nameNum=0;
	}
	//floryd
	for(int k=0;k<secNum;k++)
	{
		for(int i=0;i<secNum;i++)
		{
			for(int j=0;j<secNum;j++)
			{
				if(fabs(maps[i][j]+1)<EPS)
				{
					if(fabs(maps[i][k]+1)<EPS||fabs(maps[k][j]+1)<EPS)
						continue;
					maps[i][j]=maps[i][k]+maps[k][j];
				}
				else
				{
					if(fabs(maps[i][k]+1)<EPS||fabs(maps[k][j]+1)<EPS)
						continue;
					maps[i][j]=MIN(maps[i][j],maps[i][k]+maps[k][j]);
				}
			}
		}
	}
	for(int i=0;i<sigNum;i++)
	{
		int from=signs[i].from;int to=signs[i].to;
		if(i==1)
			while(0);
		for(int j=0;j<citNum;j++)
		{
			double dist1=maps[from][roads[j].secNo];
			double dist2=maps[to][roads[j].secNo];
			if(fabs(dist1+1)<EPS||fabs(dist2+1)<EPS)
				continue;
			//dist1-dist2-maps[from][to]==0
			if(dist1-dist2>=0&&fabs(dist1-dist2-maps[from][to])<EPS)
			{
				strcpy(signs[i].name2[signs[i].nameNum].name,roads[j].name);
				signs[i].name2[signs[i].nameNum].dist=get_i(dist1-signs[i].distF);
				signs[i].nameNum++;
			}
		}
	}
	for(int i=0;i<sigNum;i++)
	{
		signs[i].sort_B();
		for(int j=0;j<signs[i].nameNum;j++)
			printf("%-20s%d\n",signs[i].name2[j].name,signs[i].name2[j].dist);
		putchar('\n');
	}
	return 0;
}