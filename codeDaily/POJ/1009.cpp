
#include<stdio.h>
#include<stdlib.h>

int width;int maps[1000][2];int outMaps[8000][2];
int numPairs;int total;

int getCode(int pos)
{
	int p=0;int i=0;
	while(p<pos)
		p+=maps[i++][1];
	return maps[i-1][0];
}

int GetCode(int row,int col)
{
	int nowCode=getCode(row*width+col+1);int mx=-1;
	for(int i=row-1;i<=row+1;i++)
	{
		for(int j=col-1;j<=col+1;j++)
		{
			int tPos=i*width+j+1;
			if(i==row&&j==col)
				continue;
			if(i<0||j<0||j>=width||tPos>total)
				continue;
			int nW=getCode(tPos);
			if(abs(nowCode-nW)>mx)
				mx=abs(nowCode-nW);
		}
	}
	return mx;
}

int cmp(const void*v1,const void*v2)
{
	int*i1=(int*)v1;int*i2=(int*)v2;
	if(i1[0]==i2[0])
		return 0;
	else
		return i1[0]>i2[0]?1:-1;
}

int main()
{
	while(scanf("%d",&width)&&width!=0)
	{
		numPairs=0;total=0;
		while(scanf("%d%d",&maps[numPairs][0],&maps[numPairs][1]))
		{
			if(maps[numPairs][0]==0&&maps[numPairs][1]==0)
				break;
			total+=maps[numPairs][1];
			numPairs++;	
		}
		int nowPos=1;
		int num=0;
		for(int i=0;i<=numPairs;i++)
		{
			int row=(nowPos-1)/width;int col=(nowPos-1)%width;
			for(int j=row-1;j<=row+1;j++)
			{
				for(int k=col-1;k<=col+1;k++)
				{
					int tPos=j*width+k+1;
					if(j<0||k<0||k>=width||tPos>total)
						continue;
					outMaps[num][0]=tPos;
					outMaps[num++][1]=GetCode(j,k);
				}
			}
			nowPos+=maps[i][1];
		}
		qsort(outMaps,num,sizeof(int)*2,cmp);
		
		int tmpI=0;
		printf("%d\n",width);
		for(int i=0;i<num;i++)
		{
			if(outMaps[tmpI][1]==outMaps[i][1])
				continue;
			printf("%d %d\n",outMaps[tmpI][1],outMaps[i][0]-outMaps[tmpI][0]);
			tmpI=i;
		}
		printf("%d %d\n0 0\n",outMaps[tmpI][1],total-outMaps[tmpI][0]+1);
	}
	printf("0\n");
	return 0;
}
