#include<stdio.h>
#include<string.h>

int data[2][100000];int map2[100000];int result[100][100];
void fill(int row,int col,int val,int edgeSize,int index,int flag);

void process(int index,int tmpN,int density,int flag)
{
	int row=0,col=0;
	int tmp[100];int tmpNum=0;
	while(index!=0)
	{
		tmp[tmpNum++]=index;
		index=(index-1)/4;
	}
	for(int i=0;i<tmpNum-1;i++)
		tmp[i]-=tmp[i+1]*4;
	int edgeSize=tmpN;
	for(int j=tmpNum-1;j>=0;j--)
	{
		switch(tmp[j])
		{
		case 1:break;
		case 2:col+=tmpN/2;break;
		case 3:row+=tmpN/2;break;
		case 4:row+=tmpN/2;col+=tmpN/2;break;
		}
		tmpN/=2;
	}
//	for(int i=0;i<tmpN*tmpN;i++)
//		data[flag][row*edgeSize+col+i]=density;
	for(int i=0;i<tmpN;i++)
	{
		for(int j=0;j<tmpN;j++)
		{
			fill(row+i,col+j,density,edgeSize,0,flag);
		}
	}
}

void process3(int edgeSize,int*org,int*now,int stx)
{
	if(edgeSize==1)
		return;
	int vak=map2[stx];
	int i;
	for(i=0;i<edgeSize*edgeSize;i++)
	{
		if(map2[stx+i]!=vak)
			break;
	}
	if(i==edgeSize*edgeSize)
		return;
	
	int size=edgeSize*edgeSize/4;
	int pos[4]={0,size,size*2,size*3};
	int val[4];
	for(int i=0;i<4;i++)
		val[i]=now[pos[i]];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<size*4;j++)
		{
			if(val[i]==org[j])
			{
				if(j<size)
					pos[i]=0;
				else if(j<size*2)
					pos[i]=1;
				else if(j<size*3)
					pos[i]=2;
				else
					pos[i]=3;
			}
		}
	}
	if(stx==8)
		while(0);
	int tmp3[100000];
	memcpy(tmp3,map2+stx,4*size*sizeof(int));
	
	for(int i=0;i<4;i++)
	{
		if(pos[i]==i)
			continue;
		int stPos=stx+pos[i]*size;
		memcpy(map2+stPos,tmp3+i*size,size*sizeof(int));
		//map2[stPos]=tmp3[stx+i*size];
	}

	memcpy(tmp3,now,4*size*sizeof(int));
	for(int i=0;i<4;i++)
	{
		if(pos[i]==i)
			continue;
		int stPos=pos[i]*size;
		memcpy(now+stPos,tmp3+i*size,size*sizeof(int));
	//	now[stPos]=t
	}

	//memcpy(tmp3,org,4*size*sizeof(int));
//	for(int i=0;i<4;i++)
///	{
//		int stPos=pos[i]*size;
//		memcpy(org+stPos,tmp3+i*size,size*sizeof(int));
//	}
	if(edgeSize==2)
		return;
	for(int i=0;i<4;i++)
		process3(edgeSize/2,org+i*size,now+i*size,stx+size*i);
}

void process2(int row,int col,int st,int edgeSize)
{
	if(edgeSize==1)
		result[row][col]=map2[st];
	else
	{
		int size=edgeSize*edgeSize/4;int half=edgeSize/2;
		process2(row,col,st,half);
		process2(row,col+half,st+size,half);
		process2(row+half,col,st+2*size,half);
		process2(row+half,col+half,st+3*size,half);
	}
}

int orgm[100000];int n;

void fill(int row,int col,int val,int edgeSize,int index,int flag)
{
	if(edgeSize==1)
	{
		if(flag==-1)
			orgm[index]=val;
		else
			data[flag][index]=val;
	}
	else
	{
		int size=edgeSize*edgeSize/4;
		if(row<edgeSize/2&&col<edgeSize/2)
			fill(row,col,val,edgeSize/2,index,flag);
		else if(row<edgeSize/2)
			fill(row,col-edgeSize/2,val,edgeSize/2,index+size,flag);
		else if(col<edgeSize/2)
			fill(row-edgeSize/2,col,val,edgeSize/2,index+size*2,flag);
		else
			fill(row-edgeSize/2,col-edgeSize/2,val,edgeSize/2,index+size*3,flag);
	}
}

int init_matric[100][100];

void init_m(int edgeSize)
{
	for(int i=0;i<edgeSize;i++)
	{
		for(int j=0;j<edgeSize;j++)
			fill(i,j,init_matric[i][j],edgeSize,0,-1);
	}
}

int main()
{
	int cases;scanf("%d",&cases);
	for(int no=1;no<=cases;no++)
	{
		scanf("%d",&n);
		int leafNum;
		scanf("%d",&leafNum);
		for(int i=0;i<leafNum;i++)
		{
			int index;int density;
			scanf("%d%d",&index,&density);
			process(index,n,density,0);
		}
		scanf("%d",&leafNum);
		for(int i=0;i<leafNum;i++)
		{
			int index;int density;
			scanf("%d%d",&index,&density);
			process(index,n,density,1);
		}
		memcpy(map2,data[1],sizeof(int)*100000);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				init_matric[i][j]=i*n+j;
		}
		init_m(n);
		//memcpy(map2,data[1],sizeof(int)*100000);
		process3(n,orgm,data[0],0);
		process2(0,0,0,n);
		printf("Case %d\n\n",no);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				printf("%4d",result[i][j]);
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}