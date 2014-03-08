#include<stdio.h>
#include<string.h>

int pol[3][2500];int polNum[3];int tmp4[2500];int tmp5[2500];

void make2(int index)
{
	scanf("%d",polNum+index);
	
	for(int i=polNum[index]-1;i>=0;i--)
	{
		int tmp3;
		scanf("%d",&tmp3);
		pol[index][i]=tmp3;
	}
}

int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		memset(pol,0,sizeof(int)*3*2500);
		make2(0);make2(1);make2(2);	
		int nowDegree,j;
		memset(tmp4,0,sizeof(int)*2500);
		for(nowDegree=0;nowDegree<polNum[1];nowDegree++)
		{
			if(pol[1][nowDegree]==0)
				continue;
			for(j=polNum[0]-1;j>=0;j--)
			{
				if(pol[0][j]==1)
					tmp4[nowDegree+j]+=1;
			}
		}
		int degrees=(polNum[0]-1)+(polNum[1]-1);
		for(int i=degrees;i>=0;i--)
		{
			if(tmp4[i]%2!=0)
			{	degrees=i;break;}
			tmp4[i]=0;
		}
		for(int i=0;i<=degrees;i++)
			tmp4[i]=tmp4[i]%2;
		int degreeG=polNum[2]-1;
		while(degrees>=degreeG)
		{
			//printf("%d\n",degrees);
			int times=degrees-degreeG;
			memset(tmp5,0,sizeof(int)*2500);
			for(int i=0;i<=degreeG;i++)
				tmp5[i+times]=pol[2][i];
			for(int i=0;i<=degrees;i++)
			{
				if((tmp4[i]+tmp5[i])%2==0)
					tmp4[i]=0;
				else
					tmp4[i]=1;
			}
			for(int i=degrees;i>=0;i--)
			{
				if(tmp4[i]!=0)
				{	
					degrees=i;
					break;
				}
			}
			//if(polNum[2]==100)
			//		while(0);
		}
		printf("%d",degrees+1);
		for(int i=degrees;i>=0;i--)
			printf(" %d",tmp4[i]);
		putchar('\n');
	}
	return 0;
}