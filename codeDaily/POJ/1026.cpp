#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int turn[300];int minTurn[300];int n;
int result[300];

int get_turn(int val,int orign,int times)
{
	while(val!=orign)
	{
		times++;
		val=turn[val];
	}
	return times;
}

int get_minYue()
{
	int minTurn2[300];
	memcpy(minTurn2,minTurn,sizeof(int)*300);
	sort(minTurn2+1,minTurn2+n+1);
	int min2=minTurn2[1]=1;
	int index=2;
	while(min2>=1)
	{
		int j;
		for(j=1;j<=n;j++)
		{
			if(minTurn2[j]%min2!=0)
				break;
		}
		if(j==n+1)
			return min2;
		min2=minTurn2[1]/index;index++;
	}
}

int get_minBei()
{
	int total=1;
	for(int i=1;i<=n;i++)
		total=total*minTurn[i];
	return total/get_minYue();
}

int get2(int times,int index)
{
	while(times!=0)
	{
		times--;
		index=turn[index];
	}
	return index;
}

int main()
{
	
	while(scanf("%d",&n)&&n!=0)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",turn+i);
		int times;
		memset(minTurn,0,sizeof(int)*300);
		for(int i=1;i<=n;i++)
		{
			if(turn[i]==i)
				minTurn[i]=1;
			else
				minTurn[i]=get_turn(turn[i],i,1);
		}
		//int minBei=get_minBei();
	while(scanf("%d",&times))
	{
		if(times==0)
		{
			printf("\n");break;
		}
		//times%=minBei;
		for(int i=1;i<=n;i++)
			result[i]=get2(times%minTurn[i],i);
		char input[300];char tmp;
		scanf("%c",&tmp);gets(input);
		int len=strlen(input);
		if(len<n)
		{
			for(int i=len;i<n;i++)
				input[i]=' ';
			input[n]='\0';
		}
		char result2[300];
		memset(result2,0,300);
		for(int i=0;i<n;i++)
			result2[result[i+1]-1]=input[i];
		result2[n]='\0';
		printf("%s\n",result2);
	}
	}
	return 0;
}