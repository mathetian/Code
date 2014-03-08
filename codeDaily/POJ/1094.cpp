#include<stdio.h>
#include<string.h>

#define UNCETRAIN 0
#define INCON 1
#define SORTED 2
int n,m;int c[30][30];
int d[30];//indegreee
int e[30];//dup indegree

int zeroJudge(int*outInc)
{
	int numZero=0;
	for(int i=0;i<n;i++)
	{
		if(outInc[i]==0&&e[i]==0)
			numZero++;
	}
	if(numZero!=1)
		return 0;
	return 1;
}

int toplogy(char*result,int index)
{
	memcpy(e,d,sizeof(int)*30);
	int outInc[30];
	memset(outInc,0,sizeof(int)*30);

	int wprcNum=n;int resultNum=0;
	while(wprcNum!=0)
	{
		if(zeroJudge(outInc)==0)
			return 0;
		int i;
		for(i=0;i<n;i++)
		{
			if(outInc[i]==0&&e[i]==0)
				break;
		}
		outInc[i]=1;result[resultNum++]=i+'A';
		for(int j=0;j<n;j++)
			if(c[i][j]==1&&outInc[j]==0)
				e[j]--;
		wprcNum--;
	/*	if(wprcNum==4&&index==28)
			while(0);*/
	}
	return 1;
}

int dfs(int i,int j)
{
	if(j==i)
		return 1;
	else
	{
		for(int k=0;k<n;k++)
		{
			if(c[j][k]==1)
			{
				if(dfs(i,k)==1)
					return 1;
			}
		}
	}
	return 0;
}
char answer[100];

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0)
	{
		memset(c,0,sizeof(int)*900);
		memset(d,0,sizeof(int)*30);memset(answer,'\0',100);
		int flag=UNCETRAIN;
		for(int i=0;i<m;i++)
		{
			getchar();char a,b;
			scanf("%c<%c",&a,&b);
			c[a-'A'][b-'A']=1;d[b-'A']++;
	
			/*if(c[b-'A'][a-'A']==1&&flag==UNCETRAIN)
			{
				printf("Inconsistency found after %d relations.\n",i+1);flag=INCON;
			}*/
		/*	for(int j=0;j<n&&flag==UNCETRAIN;j++)
			{
				if(c[b-'A'][j]==1)
				{
					if(c[j][a-'A']==1)
					{
						printf("Inconsistency found after %d relations.\n",i+1);flag=INCON;
					}
					if(c[a-'A'][j]==0)
					{
						c[a-'A'][j]=1;d[j]++;
					}
				}
			}
			for(int j=0;j<n&&flag==UNCETRAIN;j++)
			{
				if(c[j][a-'A']==1)
				{
					if(c[j][b-'A']==0)
					{
						c[j][b-'A']=1;d[b-'A']++;
					}
				}
			}
		*/
			if(flag==UNCETRAIN&&dfs(a-'A',b-'A')==1)
			{
				//printf("Inconsistency found after %d relations.\n",i+1);
				sprintf(answer,"Inconsistency found after %d relations.",i+1);
				flag=INCON;
			}
			char result[30];memset(result,'\0',30);
			if(flag==UNCETRAIN&&toplogy(result,i)==1)
			{
				//printf("Sorted sequence determined after %d relations: %s.\n",i+1,result);
				sprintf(answer,"Sorted sequence determined after %d relations: %s.",i+1,result);
				flag=SORTED;
			}
		}
		if(flag==UNCETRAIN)
			puts("Sorted sequence cannot be determined.");
		else
			puts(answer);
	}
	return 0;
}