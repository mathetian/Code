
#include<stdio.h>

#define N 21254
int main()
{
	int data[4];
	int index=1;
	while(scanf("%d%d%d%d",&data[0],&data[1],&data[2],&data[3])&&data[0]!=-1)
	{
		for(int i=data[3]+1;i<=N+data[3];i++)
		{
			if((i-data[0])%23==0&&
				(i-data[1])%28==0&&
				(i-data[2])%33==0)
			{
				//Case 1: the next triple peak occurs in 21252 days.
				printf("Case %d: the next triple peak occurs in %d days.\n",index,i-data[3]);index++;
				break;
				
			}
		}
	}
	return 0;
}

