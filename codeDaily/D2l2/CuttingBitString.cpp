#include <vector>
#include <string>
#include <string.h>
using namespace std;

int mv=0x3fffff;

typedef long long _int64;char dp[51][51];

void dfs(string const&S, int index,int m)
{
	int n=S.size();
	if(index==n) mv=min(mv,m);
	else
	{
		if(S.at(index)=='0') return;
		for(int i=index;i<n;i++) if(dp[index][i]==1) dfs(S,i+1,m+1);
	}
}

int ispowerOf5(_int64 v)
{
	if(v==0) return 0;
	while(v>1)
	{
		if(v%5!=0) return 0;
		v=v/5;
	}
	return 1;
}

int getmin(string const &S) 
{
	int i,j;int n=S.size();
	memset(dp,0,51*51);
	mv=0x3fffff;
	for(i=0;i<n;i++)
	{
		if(S.at(i)=='0') continue;
		_int64 r=1;dp[i][i]=1;
		for(j=i+1;j<n;j++)
		{
			r=r*2+(S.at(j)-'0');
			if(ispowerOf5(r)) dp[i][j]=1;
		}
	}
	dfs(S,0,0);
	if(mv==0x3fffff) return -1;
    return mv;
}
