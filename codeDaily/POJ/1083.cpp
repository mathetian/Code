#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void*p1,const void*p2)
{
	int a=*(int*)p1;int b=*(int*)p2;
	return a>b;
}

int main()
{
	int cases;scanf("%d",&cases);
	while(cases--)
	{
		int mvNum;
		scanf("%d",&mvNum);
		int mv[300];
		memset(mv,0,sizeof(int)*300);
		for(int i=0;i<mvNum;i++)
		{
			int a,b;scanf("%d%d",&a,&b);
			if(a%2==0)
				a-=1;
			if(b%2==0)
				b-=1;
			if(a>b)
			{
				int tmp=a;a=b;b=tmp;
			}
			a=a/2;b=b/2;
			for(int i=a;i<=b;i++)
				mv[i]++;
		}
		qsort(mv,200,sizeof(int),cmp);
		printf("%d\n",mv[199]*10);
	}
	return 0;
}