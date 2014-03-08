#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define UP 0
#define DOWN 1

int fullEdge;int difNum;int edgeSize[10];int fullArea;int fillArea;
int begin[51][2];int end[51][2];int maps[51][51][2];

int cmp(const void*p1,const void*p2)
{
	return (int)(*(int*)p1)-(int)(*(int*)p2)>0?1:-1;
}

int process_ahead()
{
		qsort(edgeSize,difNum,sizeof(int),cmp);
		int i;
		for(i=difNum-1;i>=0;i--)
		{
			if(edgeSize[i]<=fullEdge)
				break;
		}
		if(i<0)
			return -1;
		difNum=i+1;
		for(i=0;i<difNum;i++)
		{
			if(fullEdge%edgeSize[i]==0)
				break;
		}
		if(i<difNum)
			return 1;
		int used[21];
		memset(used,0,sizeof(int)*21);
		for(i=difNum-1;i>=1;i--)
		{
			int j;
			for(j=0;j<=i-1;j++)
			{
				if(edgeSize[i]%edgeSize[j]==0)
				{
					used[i]=1;break;
				}
			}
		}
		int index=0;
		for(i=0;i<difNum;i++)
		{
			if(used[i]==0)
				edgeSize[index++]=edgeSize[i];
		}
		difNum=index;
		return 0;
}

void init()
{
		begin[0][UP]=fullEdge;end[0][UP]=2*fullEdge-1;
		begin[0][DOWN]=fullEdge;end[0][DOWN]=2*fullEdge;
		for(int i=1;i<fullEdge;i++)
		{
			begin[i][UP]=begin[i-1][UP]-1;end[i][UP]=end[0][UP];
			begin[i][DOWN]=begin[i-1][DOWN]-1;end[i][DOWN]=end[0][DOWN];
		}
		begin[fullEdge][UP]=0;end[fullEdge][UP]=end[0][UP];
		begin[fullEdge][DOWN]=1;end[fullEdge][DOWN]=end[fullEdge][UP];
		for(int i=fullEdge+1;i<2*fullEdge;i++)
		{
			begin[i][UP]=0;end[i][UP]=end[i-1][UP]-1;
			begin[i][DOWN]=1;end[i][DOWN]=end[i][UP];
		}
}

int getEglible(int&row,int&col,int&flag)
{
	int i,j;
	for(i=row;i<2*fullEdge;i++)
	{
		for(j=col;j<=end[i][flag];j++)
		{
			if(maps[i][j][flag]==0)
				break;
		}
		if(j<=end[i][flag])
		{
			row=i;col=j;break;
		}
		if(flag==UP)
		{
			int k;
			for(k=begin[i][DOWN];k<=end[i][DOWN];k++)
			{
				if(maps[i][k][DOWN]==0)
					break;
			}
			if(k<=end[i][DOWN])
			{
				row=i;col=k;flag=DOWN;break;
			}
		}
		flag=UP;
		if(i<2*fullEdge-1)
			col=begin[i+1][UP];
	}
	if(i>=2*fullEdge)
		return 0;
	else
		return 1;
}

int getNext(int&nrow,int&ncol,int&nflag,int row,int col,int flag)
{
	int i,j;int beg=col+1;
	for(i=row;i<2*fullEdge;i++)
	{
		for(j=beg;j<=end[i][flag];j++)
		{
			if(maps[i][j][flag]==0)
			{
				nrow=i;ncol=j;nflag=flag;return 1;
			}
		}
		if(flag==UP)
		{
			int k;
			for(k=begin[i][DOWN];k<=end[i][DOWN];k++)
			{
				if(maps[i][k][DOWN]==0)
				{
					nrow=i;ncol=k;nflag=DOWN;
					return 1;
				}
			}
		}
		if(i<2*fullEdge-1)
		{
			beg=begin[i+1][UP];
		}
		flag=UP;
	}
	return 0;
}

int getBiggest(int row,int col,int flag)
{
	int sizeN=1;
	if(maps[row][col][flag]==1)
		return 0;
	if(flag==UP)
	{
		int size;
		for(size=2;row+size<=2*fullEdge;size++)
		{
			int j,k;int mx=size-1;
			for(j=0;j<size;j++)
			{
				for(k=0;k<=mx;k++)
				{
					if(col+k>end[row+j][UP]||maps[row+j][col+k][UP]==1)
						return size-1;
				}
				mx--;
			}
			mx=size-1;
			for(j=0;j<size-1;j++)
			{
				for(k=1;k<=mx;k++)
				{
					if(col+k>end[row+j][DOWN]||maps[row+j][col+k][DOWN]==1)
						return size-1;
				}
				mx--;
			}
		}
		return size-1;
	}
	else
	{
		int size;
		for(size=2;size+row<=2*fullEdge;size++)
		{
			if(size==14)
				while(0);
			int j,k;int mx=0;
			for(j=0;j<size;j++)
			{
				for(k=mx;k<=0;k++)
				{
					if(k+col<begin[j+row][DOWN]||k+col>end[row+j][DOWN]||maps[row+j][col+k][DOWN]==1)
						return size-1;
				}
				mx--;
			}
			
			mx=-1;
			for(j=1;j<size;j++)
			{
				for(k=mx;j<0;k++)
				{
					if(k+col<begin[j+row][UP]||maps[row+j][col+k][UP]==1)
						return size-1;
				}
				mx--;
			}
		}
		return size-1;
	}
	
}

void fill(int row,int col,int flag,int size,int mark)
{
	if(flag==UP)
	{
		int i,j;int mx=size-1;
		for(i=0;i<size;i++)
		{
			for(j=0;j<=mx;j++)
				maps[row+i][col+j][UP]=mark;
			mx--;
		}
		mx=size-1;
		for(i=0;i<size-1;i++)
		{
			for(j=1;j<=mx;j++)
				maps[row+i][col+j][DOWN]=mark;
			mx--;
		}
	}
	else
	{
		int i,j;int mx=0;
		for(i=0;i<size;i++)
		{
			for(j=mx;j<=0;j++)
				maps[row+i][col+j][DOWN]=mark;
			mx--;
		}
		mx=-1;
		for(i=1;i<size;i++)
		{
			for(j=mx;j<0;j++)
				maps[row+i][col+j][UP]=mark;
			mx--;
		}
	}
}

int dfs(int row,int col,int flag)
{
	if(row==2*fullEdge)
		return 0;
	if(getEglible(row,col,flag)==0)
		return 0;
	int bigSize=getBiggest(row,col,flag);
	/*
	int nrow,ncol,nflag;
	if(flag==UP)
	{
		if(col==end[row][UP])
		{
			ncol=begin[row][DOWN];nrow=row;nflag=DOWN;
		}
		else
		{
			nrow=row;ncol=col+1;nflag=UP;
		}
	}
	else
	{
		if(col==end[row][DOWN])
		{
			if(row==2*fullEdge-1)
			{
				nrow=2*fullEdge;ncol=0;nflag=UP;
			}
			else
			{
				nrow=row+1;ncol=0;nflag=UP;
			}
		}
		else
		{
			nrow=row;ncol=col+1;nflag=flag;
		}
	}
	*/
	if(row==9&&col==12)
		while(0);
//	printf("(%d,%d,%d:%d)",row,col,flag,bigSize);
	for(int i=0;i<difNum&&edgeSize[i]<=bigSize;i++)
	{
		fill(row,col,flag,edgeSize[i],1);
		fillArea+=edgeSize[i]*edgeSize[i];
		if(fillArea==fullArea||dfs(row,col,flag)==1)
			return 1;
		fillArea-=edgeSize[i]*edgeSize[i];
		fill(row,col,flag,edgeSize[i],0);
	}
	//dfs(nrow,ncol,nflag);
	return 0;
}

int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d%d",&fullEdge,&difNum);
		for(int i=0;i<difNum;i++)
			scanf("%d",edgeSize+i);
		int flag=process_ahead();
		if(flag==-1)
		{
			printf("NO\n");continue;
		}
		else if(flag==1)
		{
			printf("YES\n");continue;
		}
		init();
		memset(maps,0,sizeof(int)*51*51*2);
		fullArea=6*fullEdge*fullEdge;
		fillArea=0;
		dfs(0,fullEdge,UP);
		if(fillArea==fullArea)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}