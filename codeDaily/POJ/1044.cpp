#include<stdio.h>

#define N 10000

typedef struct{
	int y,a,b;int diff;
}COMPU;

COMPU computer[20];int comNum;

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int index=1;
	while(scanf("%d",&comNum)&&comNum!=0)
	{
		int mxB=-1;
		for(int i=0;i<comNum;i++)
		{
			scanf("%d%d%d",&computer[i].y,&computer[i].a,&computer[i].b);
			computer[i].diff=computer[i].b-computer[i].a;
			mxB=max(mxB,computer[i].a);
		}
		int tim2;int flag=0;
		for(tim2=mxB;tim2<N&&!flag;tim2++)
		{
			int i;
			for(i=0;i<comNum;i++)
			{
				if((tim2-computer[i].y)%computer[i].diff!=0)
					break;
			}
			if(i==comNum)
				flag=1;
		}
		printf("Case #%d:\n",index);index++;
		if(flag)
			printf("The actual year is %d.\n\n",tim2-1);
		else
			printf("Unknown bugs detected.\n\n");
	}
	return 0;
}