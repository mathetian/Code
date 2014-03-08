#include<stdio.h>
#include<string.h>

int fishPotNum;int hours;int tpminutes;
int initFish[30];int decress[30];int interTime[30];
int FinshNow[30];int times[30];int fiTimes[30];

int get_index(int edP)
{
	int index=0;int index2=0;
	for(;index<=edP;index++)
	{
		if(FinshNow[index2]<FinshNow[index])
			index2=index;
	}
	if(FinshNow[index2]==0)
		return -1;
	return index2;
}

int main()
{
	while(scanf("%d",&fishPotNum)&&fishPotNum!=0)
	{
		scanf("%d",&hours);
		for(int i=0;i<fishPotNum;i++)
			scanf("%d",&initFish[i]);
		for(int i=0;i<fishPotNum;i++)
			scanf("%d",&decress[i]);
		for(int i=0;i<fishPotNum-1;i++)
			scanf("%d",&interTime[i]);
		hours*=12;int fiTotal=0;
		memset(fiTimes,0,sizeof(int)*30);
		for(int endPos=0;endPos<fishPotNum;endPos++)
		{
			int needTime=0;tpminutes=hours;
			for(int i=0;i<endPos;i++)
				needTime+=interTime[i];
			tpminutes-=needTime;
			if(tpminutes<=0)
				continue;
			for(int i=0;i<=endPos;i++)
				FinshNow[i]=initFish[i];
			memset(times,0,sizeof(int)*30);
			int total=0;
			while(tpminutes!=0)
			{
				int mxIndex=get_index(endPos);
				if(mxIndex==-1)
				{
					times[0]+=tpminutes;
					break;
				}
				total+=FinshNow[mxIndex];
				FinshNow[mxIndex]-=decress[mxIndex];
				if(FinshNow[mxIndex]<0)
					FinshNow[mxIndex]=0;
				times[mxIndex]++;

				tpminutes--;
			}
			if(total>fiTotal)
			{
				fiTotal=total;
				for(int i=0;i<30;i++)
					fiTimes[i]=times[i];
			}
			else if(total==fiTotal)
			{
				int i;int flag3=0;
				for(i=0;i<fishPotNum;i++)
				{
					if(times[i]>fiTimes[i])
					{	flag3=0;break;}
					else if(times[i]<fiTimes[i])
					{ flag3=1;break;}
					else 
						continue;
				}
				if(flag3==0)
				{
					memcpy(fiTimes,times,sizeof(int)*30);
				}

			}
		}
		for(int i=0;i<fishPotNum-1;i++)
			printf("%d, ",fiTimes[i]*5);
		printf("%d\n",fiTimes[fishPotNum-1]*5);
		printf("Number of fish expected: %d\n\n",fiTotal);
	}
	return 0;
}