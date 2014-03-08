#include<stdio.h>

int rows,cols;

int maps[101][101];

typedef struct{
	int less,big;
	char direct;
}CHASE;

CHASE chases[1001];int chaseNum;

int dfs(int stx,int sty,int chaseTmp)
{
	if(chaseTmp==chaseNum)
		return 1;
	else
	{
		int i;int j;
		switch(chases[chaseTmp].direct)
		{
		case 'R':
			for(i=0;i<chases[chaseTmp].less&&i+sty<cols;i++)
			{
				if(maps[stx][sty+i]==1)
					goto label1;
			}
			for(i=chases[chaseTmp].less;i<=chases[chaseTmp].big&&i+sty<cols;i++)
			{
				if(maps[stx][sty+i]==1)
					break;
				if(dfs(stx,sty+i,chaseTmp+1)==1)
					return 1;
			}
			break;
		case 'L':
			for(i=0;i<chases[chaseTmp].less&&sty-i>=0;i++)
			{
				if(maps[stx][sty-i]==1)
					goto label1;
			}
			for(i=chases[chaseTmp].less;i<=chases[chaseTmp].big&&sty-i>=0;i++)
			{
				if(maps[stx][sty-i]==1)
					break;
				if(dfs(stx,sty-i,chaseTmp+1)==1)
					return 1;
			}
			break;
		case 'U':
			for(i=0;i<chases[chaseTmp].less&&stx-i>=0;i++)
			{
				if(maps[stx-i][sty]==1)
					goto label1;
			}
			for(i=chases[chaseTmp].less;i<=chases[chaseTmp].big&&stx-i>=0;i++)
			{
				if(maps[stx-i][sty]==1)
					break;
				if(dfs(stx-i,sty,chaseTmp+1)==1)
					return 1;
			}
			break;
		case 'D':
			for(i=0;i<chases[chaseTmp].less&&i+stx<rows;i++)
			{
				if(maps[stx+i][sty]==1)
					goto label1;
			}
			for(i=chases[chaseTmp].less;i<=chases[chaseTmp].big&&stx+i<rows;i++)
			{
				if(maps[stx+i][sty]==1)
					break;
				if(dfs(stx+i,sty,chaseTmp+1)==1)
					return 1;
			}
			break;
		}
	}
label1:;
	return 0;
}

int main()
{
	int caseNum;scanf("%d",&caseNum);
	while(caseNum--)
	{
		scanf("%d%d",&rows,&cols);
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
				scanf("%d",&maps[i][j]);
		}
		chaseNum=0;
		while(scanf("%d%d",&chases[chaseNum].less,&chases[chaseNum].big))
		{
			if(chases[chaseNum].less==0&&chases[chaseNum].big==0)
				break;
			getchar();
			scanf("%c",&chases[chaseNum++].direct);
		}
		int ableNum=0;
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				if(maps[i][j]==1)
					continue;
				if(i==0&&j==5)
					while(0);
				if(dfs(i,j,0)==1)
				{
					//printf("(%d,%d)",i,j);
					ableNum++;
				}
				//putchar('\n');
			}
		}
		printf("%d\n",ableNum);
	}
	return 0;
}