#include <vector>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)
vector<vector<int> >prim;int n;vector<int>allPrimes;

int dp[1<<20][51];

void dfs(int mask,int pos,int m)
{
	int&res=dp[mask][pos];
	if(pos==n)
	{
		res=max(res,m);
	}
	else
	{
		vector<int> dd=prim.at(pos);int nmask=mask;
		int i;FF(i,dd.size()) if((mask&(1<<dd.at(i)))!=0) break; else nmask|=(1<<dd.at(i));
		dfs(mask,pos+1,m);if(i==dd.size()) dfs(nmask,pos+1,m+1);
	}
}

int findSize(vector<int> const &S) 
{
	int i,j;n=S.size();for(i=2;i<52;i++)
	{
		for(j=2;j*j<=i;j++) if(i%j==0) break;
		if(j*j>i) allPrimes.push_back(i);
	}
	vector<int>bigprimes;memset(dp,-1,sizeof(dp));
	for(i=52;i<=100;i++)
	{
		for(j=2;j*j<=i;j++) if(i%j==0) break;
		if(j*j>i) bigprimes.push_back(i);
	}
	int num=0, one=0;FF(i,n)
	{
		if(S.at(i)==1) {one=1;continue;}
		else if(S.at(i)>=52)
		{
			FF(j,bigprimes.size()) if(bigprimes.at(j)==S.at(i)) break;
			if(j<bigprimes.size()){num++;continue;}
		}
		vector<int> dd;FF(j,allPrimes.size()) 
		if(S.at(i)%allPrimes.at(j)==0) dd.push_back(j);
		prim.push_back(dd);
	}
	int mx=0;num+=one;n-=num;
	dfs(0,0,0);FF(i,1<<allPrimes.size()) 
	if(dp[i][n]!=-1) mx=max(mx,dp[i][n]);return num+mx;
}

/*int dfs()
{
	int&res=dp[mask]
}*/

/*void dfs(int mask,int pos,int m)
{
	
}*/