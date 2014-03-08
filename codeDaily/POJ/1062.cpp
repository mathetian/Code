#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct{
	int level;int needGold;int replaceNum;
	int replace[101];int replaceGold[101];
}NODE;

NODE nodes[101];int mxLevel;int nid;int minLevel;int mxx;int used[101];int levelDif;int catNum;

int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a>b?b:a;
}

int process(int nowId,int mxLevel,int minLevel,int nowGold)
{
//	printf("%d\n",nowGold);
	int tmp1=nowGold;int tmp2=nowGold;
	for(int i=0;i<nodes[nowId].replaceNum;i++)
	{
		int nid=nodes[nowId].replace[i];
		if(abs(nodes[nid].level-mxLevel)>levelDif||abs(nodes[nid].level-minLevel)>levelDif||used[nid])
			continue;
		used[nid]=1;
		tmp1=tmp1-nodes[nowId].needGold+nodes[nowId].replaceGold[i]+nodes[nid].needGold;
		int mxT=max(mxLevel,nodes[nid].level);int minT=min(minLevel,nodes[nid].level);
		tmp1=process(nid,mxT,minT,tmp1);
		used[nid]=0;
		if(nowGold>tmp1)
			nowGold=tmp1;
	//	if(tmp1==102)
//			while(0);	
		tmp1=tmp2;
	}
	return nowGold;
}

int main()
{
	
	while(scanf("%d%d",&levelDif,&catNum)!=EOF)
	{
		for(int i=1;i<=catNum;i++)
		{
			scanf("%d%d%d",&nodes[i].needGold,&nodes[i].level,&nodes[i].replaceNum);
			for(int j=0;j<nodes[i].replaceNum;j++)
				scanf("%d%d",&nodes[i].replace[j],&nodes[i].replaceGold[j]);
		}
		memset(used,0,sizeof(int)*101);
		used[1]=1;
		int result=process(1,nodes[1].level,nodes[1].level,nodes[1].needGold);
		printf("%d\n",result);
	}
	return 0;
}