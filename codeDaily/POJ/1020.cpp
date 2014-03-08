#include<stdio.h>
#include<string.h>

int fullEdge;int peoNum;
int people[16];int num[11];int used[161];

int dfs(int index)
{
	if(index==peoNum)
	{
		printf("KHOOOOB!\n");
		return 1;
	}
	else
	{
		int min2=used[1];int cy=1;int i,j;
		for(i=1;i<=fullEdge;i++)
		{
			if(min2>used[i])
			{
				min2=used[i];cy=i;
			}
		}
		for(i=10;i>=1;i--)
		{
			if(num[i]==0)
				continue;
			if((cy+i<=fullEdge+1)&&(min2+i<=fullEdge+1))
			{
			}
			else
				continue;
			for(j=cy+1;j<cy+i;j++)
			{
				if(used[j]>min2)
					break;                                   
			}
			if(j<cy+i)
				continue;
			if(j==cy+i)
			{
				for(j=cy;j<cy+i;j++)
					used[j]+=i;
				num[i]--;
				if(dfs(index+1)==0)
				{
					num[i]++;
					for(j=cy;j<cy+i;j++)
						used[j]-=i;
				}
				else
					return 1;
			}
		}
		return 0;
	}
}

int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		
		scanf("%d",&fullEdge);
		scanf("%d",&peoNum);
		memset(num,0,sizeof(int)*11);
		for(int i=0;i<peoNum;i++)
		{
			scanf("%d",people+i);
			num[people[i]]++;
		}
		int total=0;
		for(int i=0;i<peoNum;i++)
			total=total+people[i]*people[i];
		if(total!=fullEdge*fullEdge||fullEdge==0)
		{
			printf("HUTUTU!\n");continue;
		}
		for(int i=1;i<=fullEdge;i++)
			used[i]=1;
		if(dfs(0)==0)
		{
			printf("HUTUTU!\n");
		}
	}
	return 0;
}