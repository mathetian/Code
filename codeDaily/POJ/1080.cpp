#include<stdio.h>

int value[5][5]={{5,-1,-2,-1,-3},
				{-1,5,-3,-2,-4},
				{-2,-3,5,-2,-2},
				{-1,-2,-2,5,-1},
				{-3,-4,-2,-1,0}};

int c[150][150];

int max(int a,int b)
{
	return a>b?a:b;
}

int max(int a,int b,int c)
{
	return max(a,b)>c?max(a,b):c;
}

int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int len[2];char str[2][101];
		scanf("%d%s",len,str[0]);scanf("%d%s",len+1,str[1]);
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<len[i];j++)
			{
				switch(str[i][j])
				{
				case 'A':str[i][j]=0;break;
				case 'C':str[i][j]=1;break;
				case 'G':str[i][j]=2;break;
				case 'T':str[i][j]=3;break;
				}
			}
		}
		//c[i][j]=max{c[i-1][j-1]+value(i,j),c[i-1][j]+value(i,-),c[i][j-1]+value(-,j)}
		//result: c[len[0]][len[1]]
		//c[0][i]=sum{value(0,j) | j:0->len[1]}
		c[0][0]=0;
		for(int i=1;i<=len[1];i++)
			c[0][i]=c[0][i-1]+value[4][str[1][i-1]];
		for(int i=1;i<=len[0];i++)
			c[i][0]=c[i-1][0]+value[4][str[0][i-1]];
		for(int i=1;i<=len[0];i++)
		{
			for(int j=1;j<=len[1];j++)
				c[i][j]=max(c[i-1][j-1]+value[str[0][i-1]][str[1][j-1]],c[i-1][j]+value[str[0][i-1]][4],c[i][j-1]+value[4][str[1][j-1]]);
		}
		printf("%d\n",c[len[0]][len[1]]);
	}
	return 0;
}