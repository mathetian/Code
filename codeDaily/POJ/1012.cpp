#include<stdio.h>

#define N 15

int work(int k,int m)
{
	int r=1;int a=0;
	while(r<=k)
	{
		if((a+m-1)%(2*k+1-r)>=k)
		{
			a=(a+m-1)%(2*k+1-r);
			r++;
		}
		else
			return 0;

	}
	return 1;
}

int main()
{
	int data[N];
	for(int len=1;len<N;len++)
	{
		for(int r=len+1;;r=r+len+1)
		{
			if(r==7)
			{
				while(0);
			}
			if(work(len,r)==1)
			{
				data[len]=r;
			//	printf("%d %d\n",len,r);
				break;
			}
			else if(work(len,r+1)==1)
			{
				data[len]=r+1;
			//	printf("%d %d\n",len,r+1);
				break;
			}
		}
	}
	int a;
	while(scanf("%d",&a)&&a!=0)
	{
		printf("%d\n",data[a]);
	}
	return 0;
}