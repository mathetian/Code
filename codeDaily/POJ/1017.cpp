#include<stdio.h>

int main()
{
	int num[7];
	while(1)
	{
		int flag=0;
		for(int i=1;i<7;i++)
		{
			scanf("%d",num+i);
			if(num[i]!=0)
				flag=1;
		}
		if(flag==0)
			break;
		int total=num[6];
		total=total+num[5];
		if(num[5]*11<=num[1])
			num[1]=num[1]-11*num[5];
		else
			num[1]=0;
		total=total+num[4];
		if(num[4]*5<=num[2])
			num[2]=num[2]-5*num[4];
		else
		{
			if(4*(5*num[4]-num[2])<=num[1])
				num[1]=num[1]-4*(5*num[4]-num[2]);
			else
				num[1]=0;
			num[2]=0;
		}
		if(num[3]!=0)
		{
			if(num[3]%4==0)
			{
				total=total+num[3]/4;
				num[3]=0;
			}
			else
			{
				total=total+num[3]/4+1;
				num[3]=num[3]%4;
			}
		}
		int need=7-2*num[3];
		if(num[3]>0)
		{
			if(num[2]>need)
			{
				num[1]=num[1]>(36-num[3]*9-(7-2*num[3])*4)?(num[1]-(36-num[3]*9-(7-2*num[3])*4)):0;
				num[2]=num[2]-need;
			}
			else
			{
				num[1]=num[1]>(36-9*num[3]-num[2]*4)?(num[1]-(36-9*num[3]-num[2]*4)):0;
				num[2]=0;
			}
		}
		total=total+num[2]/9;
		num[2]%=9;
		if(num[2]!=0)
		{
			total+=1;
			num[1]=num[1]>(36-4*num[2])?(num[1]-36+4*num[2]):0;
			num[2]=0;
		}
		total=total+num[1]/36;
		num[1]%=36;
		if(num[1]!=0)
			total+=1;
		printf("%d\n",total);
	}
	return 0;
}