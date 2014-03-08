
#include<stdio.h>
#include<string.h>

typedef struct BIGINT{
	int len;char data[5000];
	BIGINT operator=(BIGINT b1)
	{
		len=b1.len;
		memcpy(data,b1.data,5000);
		return *this;
	}
	BIGINT()
	{
		len=0;memset(data,0,5000);
	}
}BIGINT;

int a[1001];
//BIGINT f[1001];BIGINT g[1001];BIGINT t[1001];

BIGINT operator+(BIGINT p1,BIGINT p2)
{
	if(p1.len==0)
		return p2;
	else if(p2.len==0)
		return p1;
	else
	{
		BIGINT p;p.len=0;
		int i;int mx=p1.len>p2.len?p1.len:p2.len;
		int remain=0;
		for(i=0;i<mx;i++)
		{
			p.data[p.len]=p1.data[i]+p2.data[i]+remain;
			remain=p.data[p.len]/10;
			p.data[p.len]=p.data[p.len]%10;
			p.len++;
		}
		if(remain!=0)
			p.data[p.len++]=remain;
		return p;
	}
}

BIGINT operator+(BIGINT p1,int p2)
{
	BIGINT p3;p3.len=1;p3.data[0]=p2;
	return p1+p3;
}

int main()
{
	//f[n]:change 1~n -> 0
	//g[n]:change 1~n -> (1~n-1)0 (n)1
	//t[n]:change (1~n-1)0 (n)1 -> 0

	//f[n]= g[n-1] + 1 + t[n-1] if a[n]=1;
	//    = f[n-1] else if a[n]=0
	//g[n]= f[n-1] if a[n]=1
	//    = g[n-1] + 1 + t[n-1]
	//t[n]= 2*t[n-1] + 1
	int m;scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",a+i);
	int j;
	for(j=1;j<=m;j++)
		if(a[j]==1)
			break;
	if(j>m)
	{
		printf("0\n");return 0;
	}
	BIGINT oldF;BIGINT oldG;BIGINT oldT;
	BIGINT newF;BIGINT newG;BIGINT newT;
	for(int n=1;n<=m;n++)
	{
		if(a[n]==1)
			newF=oldG+oldT+1;
		else
			newF=oldF;
		if(a[n]==1)
			newG=oldF;
		else
			newG=oldG+oldT+1;
		newT=oldT+oldT+1;
		oldF=newF;oldG=newG;oldT=newT;
	}
	for(int i=oldF.len-1;i>=0;i--)
		putchar(oldF.data[i]+'0');
	putchar('\n');
	return 0;
}
