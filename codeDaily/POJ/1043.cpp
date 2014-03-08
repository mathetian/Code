#include<stdio.h>
#include<string.h>

int maps[30][30];
char idName[30][30];char reName[30][30];
int flag[30]; int num;int state[30];
int count;int result[30];int maps2[30];
int ableNum;

int getID(char*name)
{
	for(int i=0;i<num;i++)
		if(strcmp(name,idName[i])==0)
			return i;
}

void sort_bySelf()
{
	int i,j;
	for(i=1;i<num;i++)
	{
		char tmp2[30];strcpy(tmp2,reName[i]);
		int index=maps2[i];
		for(j=i-1;j>=0;j--)
		{
			if(strcmp(tmp2,reName[j])<0)
			{
				strcpy(reName[j+1],reName[j]);
				maps2[j+1]=maps2[j];
			}
			else
				break;
		}
		strcpy(reName[j+1],tmp2);
		maps2[j+1]=index;
	}
}

int dfs(int reIndex)
{
	for(int i=0;i<num;i++)
	{
		if(state[i]==0&&maps[reIndex][i]==1)
		{
			state[i]=1;
			if(result[i]==-1||dfs(result[i]))
			{
				result[i]=reIndex;
				return 1;
			}
		}
	}
	return 0;
}

int HunGurgy()
{
	int ans=0;
	for(int i=0;i<count;i++)
	{
		memset(state,0,sizeof(int)*30);
		if(dfs(i))
			ans++;
	}
	return ans;
}

int main()
{
	//int maps[30][30];
//char idName[30][30];char reName[30][30];
//int flag[30]; int num;int state[30];
//int count;int result[30];int maps2[30];

	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%s",idName[i]);
	}
	char tmp4[5];count=0;
	while(scanf("%s",tmp4)&&strcmp(tmp4,"Q")!=0)
	{
		char name[30];
		scanf("%s",name);char tmp=tmp4[0];
		if(tmp=='E')
		{
			int i=0;
			for(;i<count;i++)
			{
				if(strcmp(name,reName[i])==0)
					break;
			}
			flag[i]=1;
			if(i==count)
			{
				strcpy(reName[count],name);flag[count]=1;count++;
			}
		}
		else if(tmp=='L')
		{
			int i=0;
			for(;i<count;i++)
			{
				if(strcmp(name,reName[i])==0)
					break;
			}
			flag[i]=0;
		}
		else if(tmp=='M')
		{
			int i=0;
			for(;i<num;i++)
			{
				int ds=getID(name);
				if(flag[i]==0)
					maps[i][ds]=-1;
				else if(flag[i]==1&&maps[i][ds]!=-1)
						maps[i][ds]=1;
			}
		}
	}
	memset(result,-1,sizeof(int)*30);
	int mxPipei=HunGurgy();
	memset(maps2,-1,sizeof(int)*30);
	ableNum=0;int index=0;
	for(int i=0;i<num;i++)
	{   int j;
		for(j=0;j<num;j++)
		{
			if(maps[i][j]==1)
			{
				maps[i][j]=0;
				memset(result,-1,sizeof(int)*30);
				int tmpV=HunGurgy();
				if(mxPipei!=tmpV)
				{	
					maps2[i]=j;ableNum++;
					maps[i][j]=1;break;
				}
				maps[i][j]=1;
			}
		}
		if(j==num)
			index=i;
	}
	int j;
	if(ableNum==num-1)
	{
		int rema=(num-1)*num/2;
		for(int i=0;i<num;i++)
		{		
			if(maps2[i]!=-1)
				rema-=maps2[i];
		}
		maps2[index]=rema;
	}

	sort_bySelf();
	for(int i=0;i<num;i++)
	{
		printf("%s:",reName[i]);
		if(maps2[i]==-1)
			printf("???\n");
		else
			printf("%s\n",idName[maps2[i]]);
	}
	return 0;
}