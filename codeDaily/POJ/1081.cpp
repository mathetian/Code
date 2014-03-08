#include<stdio.h>
#include<string.h>

int people[50][50];int favNum[50];
int peopleNum;int min=1000;
int need;int Class[2][50];

int getMx(int classNo,int need)
{
	int n1=100;int favNum2[50];
	memset(favNum2,0,sizeof(int)*50);
	for(int i=0;i<need;i++)
	{
		for(int j=0;j<need;j++)
		{
			if(i==j)	
				continue;
			int no=Class[classNo][i];
			int no2=Class[classNo][j];
			if(people[no][no2]==0)
				favNum2[i]++;
		}
	}
	int mxtmp=favNum2[0];
	for(int i=0;i<need;i++)
	{
		if(mxtmp<favNum2[i])
			mxtmp=favNum2[i];
	}
	return mxtmp;
}

void dfs(int index,int startPos)
{
	if(index==need)
	{
		int mxtmp1=getMx(0,need);

		int used[50];
		memset(used,0,sizeof(int)*50);
		for(int i=0;i<need;i++)
		{
			int no=Class[0][i];
			if(no!=-1)
				used[no]=1;
		}
		int nnum=0;
		for(int i=0;i<peopleNum;i++)
		{
			if(used[i]==0)
				Class[1][nnum++]=i;
		}

		int mxtmp=getMx(1,nnum);
		mxtmp=mxtmp>mxtmp1?mxtmp:mxtmp1;
		if(mxtmp<min)
			min=mxtmp;
	}
	else
	{
		for(;startPos<peopleNum;startPos++)
		{
			Class[0][index]=startPos;
			dfs(index+1,startPos+1);
			Class[0][index]=-1;
		}
	}
}
int main()
{
	memset(people,0,sizeof(int)*2500);
	int stN;peopleNum=0;
	while(scanf("%d",&stN)!=EOF)
	{
		//if(stN==5)
		//	break;
		scanf("%d",&favNum[peopleNum]);
		for(int i=0;i<favNum[peopleNum];i++)
		{
			int tmp;scanf("%d",&tmp);
			people[peopleNum][tmp-1]=1;
		}
		peopleNum++;
	}
	need=peopleNum/2;
	for(int i=0;i<50;i++)
	{
		Class[0][i]=Class[1][i]=-1;
	}
	dfs(0,0);
	printf("%d\n",min);
	return 0;
}