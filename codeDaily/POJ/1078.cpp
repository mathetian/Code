#include<stdio.h>
#include<string.h>

int used[101];int found;

int dfs(int low,int high,int pos,int flag)
{
	if(low==1)
	{
		if(flag==1)
			return 1;
		else
		{
			found=1;
			if(dfs(high,high,2,1))
				return 1;
			return 0;
		}
	}
	else
	{
		for(;pos<=100;pos++)
		{
			if(low%pos==0&&used[pos]==0)
			{
				used[pos]=1;
				if(dfs(low/pos,high,pos+1,flag)==1)
					return 1;
				used[pos]=0;
			}
		}
		return 0;
	}
}

int main()
{
	int low,high;
	while(scanf("%d%d",&low,&high)!=EOF)
	{
		if(low>high)
		{
			int tmp=low;low=high;high=tmp;
		}
		memset(used,0,sizeof(int)*101);
		found=0;
		int flag=dfs(low,high,2,0);
		if(flag==1)
			printf("%d\n",high);
		else
		{
			if(found==1)
				printf("%d\n",low);
			else
				printf("%d\n",high);
		}
	}
	return 0;
}