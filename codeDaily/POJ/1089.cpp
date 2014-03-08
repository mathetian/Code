#include<stdio.h>
#include<stdlib.h>

int input[100000][2];int pairNum;int opt[100000][2];int optNum;

int cmp(const void*p1,const void*p2)
{
	int*v1=(int*)p1;int*v2=(int*)p2;
	int vv1=v1[0];int vv2=v2[0];
	return vv1>vv2?1:-1;
}

int main()
{
	scanf("%d",&pairNum);
	for(int i=0;i<pairNum;i++)
		scanf("%d%d",&input[i][0],&input[i][1]);
	qsort(input,pairNum,sizeof(int)*2,cmp);
	optNum=0;int nowEnd=input[0][1];int nowBeg=input[0][0];
	for(int i=0;i<pairNum;i++)
	{
		if(input[i][0]<=nowEnd)
		{
			if(input[i][1]>nowEnd)
				nowEnd=input[i][1];
		}
		else
		{
			opt[optNum][0]=nowBeg;opt[optNum++][1]=nowEnd;
			nowBeg=input[i][0];nowEnd=input[i][1];
		}
	}
	opt[optNum][0]=nowBeg;opt[optNum++][1]=nowEnd;
	for(int i=0;i<optNum;i++)
		printf("%d %d\n",opt[i][0],opt[i][1]);
	return 0;
}