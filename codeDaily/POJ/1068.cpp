#include<stdio.h>
#include<string.h>

int wSeq[100];int pSeq[100];int result[1000];int used[1000];

int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int n;scanf("%d",&n);
		int old=0;int num=0;int Pos[1000];
		for(int i=0;i<n;i++)
		{
			scanf("%d",pSeq+i);
			for(int j=0;j<pSeq[i]-old;j++)
				result[num++]=1;
			result[num++]=0;
			Pos[i]=num-1;
			old=pSeq[i];
		}
		memset(used,0,sizeof(int)*1000);
		for(int i=0;i<n;i++)
		{
			int tmpNum=1;
			for(int j=Pos[i]-1;j>=0;j--)
			{
				if(result[j]==1&&used[j]==0)
				{
					printf("%d ",tmpNum);used[j]=1;
					break;
				}
				else if(result[j]==0)
					tmpNum++;
			}
			
		}
		putchar('\n');
	}
	return 0;
}