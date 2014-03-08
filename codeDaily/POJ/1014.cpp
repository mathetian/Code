#include<stdio.h>


#define N 120001

int flag[N];int num[6];int total;

int max(int a,int b)
{
	return a>b?a:b;
}

void zeroOnePack(int cost,int value)
{
	for(int i=total/2;i>=cost;i--)
	{
		flag[i]=max(flag[i],flag[i-cost]+value);
	}
}

void completePacket(int cost,int value)
{
	for(int i=cost;i<=total/2;i++)
	{
		flag[i]=max(flag[i],flag[i-cost]+value);
	}
}

void multiPacket(int cost,int value,int amount)
{
	if(cost*amount>=total/2)
	{
		completePacket(cost,value);
	}
	else
	{
		for(int i=1;i<amount;)
		{
			zeroOnePack(i*cost,i*value);
			amount=amount-i;
			i=2*i;
		}
		zeroOnePack(amount*cost,amount*value);
	}
}

int main()
{
	int index=0;
	while(1)
	{
		int flag1=0;total=0;
		for(int i=0;i<6;i++)
		{
			scanf("%d",num+i);
			total=total+num[i]*(i+1);
			if(num[i]!=0)
				flag1=1;
		}
		if(flag1==0)
			break;
		if(total%2!=0)
		{
			printf("Collection #%d:\n",++index);
			printf("Can't be divided.\n\n");
			continue;
		}
		flag[0]=0;
		for(int i=1;i<=total/2;i++)
		{
			flag[i]=0-N-10;
		}
		/*
		for(int i=0;i<6;i++)
		{
			if(num[i]!=0)
			{
				for(int k=1;k<=num[i];k++)
				for(int j=total/2;j>=i+1;j--)
				{
					flag[j]=(flag[j]>flag[j-i-1]+1?flag[j]:flag[j-i-1]+1);
				}
			}
		}
		*/
		for(int i=0;i<6;i++)
		{
			if(num[i]!=0)
			{
				multiPacket(i+1,1,num[i]);
			}
		}
		printf("Collection #%d:\n",++index);
		if(flag[total/2]>0)
			printf("Can be divided.\n\n");
		else
			printf("Can't be divided.\n\n");

	}
	return 0;
}